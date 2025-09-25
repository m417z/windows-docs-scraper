# _DXGK_PREEMPTCOMMANDFLAGS structure

## Description

The DXGK_PREEMPTCOMMANDFLAGS structure specifies a union that contains either a structure with a reserved member or a 32-bit value. No bit-field flags are currently defined.

## Members

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting all 32 bits (0xFFFFFFFF) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that DXGK_PREEMPTCOMMANDFLAGS contains that can hold a 32-bit value.

## See also

[DXGKARG_PREEMPTCOMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_preemptcommand)