/** ======================================================================== **\
	Bit Array

| Version:
1.0.1

| License:
Copyright (c) 2016 Double V

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1.	The origin of this software must not be misrepresented; you must not
	claim that you wrote the original software. If you use this software
	in a product, an acknowledgement in the product documentation would be
	appreciated but is not required.
2.	Altered source versions must be plainly marked as such, and must not be
	misrepresented as being the original software.
3.	This notice may not be removed or altered from any source distribution.
\** ======================================================================== **/


#if defined _inc_bitarray
	#undef _inc_bitarray
#endif

#if defined _TDW_BITARRAY_INC_
	#endinput
#endif

#define _TDW_BITARRAY_INC_


#include "bit"


#define BitArray_GetPos(%0) ((%0) / cellbits)
#define BitArray_GetOffset(%0) ((%0) % cellbits)

#define BitArray:%0<%1> Bit@Array:%0[(%1) / cellbits + 1]

stock
	BitArray_Set(Bit@Array:array[], pos = cellmax, bool:value = true,
		array_size = sizeof array)
{
	if (pos == cellmax)
	{
		new i;
		array_size *= cellbits;
		while (i != array_size)
		{
			if (value)
				BitMSet(_:array[BitArray_GetPos(i)], i);
			else
				BitMClear(_:array[BitArray_GetPos(i)], i);
			i++;
		}
	}
	else
	{
		if (value)
			BitMSet(_:array[BitArray_GetPos(pos)], pos);
		else
			BitMClear(_:array[BitArray_GetPos(pos)], pos);
	}
	return 0;
}


stock
	BitArray_Reset(Bit@Array:array[], pos = cellmax, bool:value = true,
		array_size = sizeof array)
{
	if (pos == cellmax)
	{
		new i;
		array_size *= cellbits;
		while (i != array_size)
		{
			BitMClear(_:array[BitArray_GetPos(i)], i++);
		}
	}
	else
	{
		BitMClear(_:array[BitArray_GetPos(pos)], pos);
	}
	return 0;
}


stock
	BitArray_Flip(Bit@Array:array[], pos = cellmax,
		array_size = sizeof array)
{
	if (pos == cellmax)
	{
		new i;
		array_size *= cellbits;
		while (i != array_size)
		{
			BitMFlip(_:array[BitArray_GetPos(i)], i++);
		}
	}
	else
	{
		BitMFlip(_:array[BitArray_GetPos(pos)], pos);
	}
	return 0;
}