# READ_REGISTER_USHORT function (miniport.h)

## Description

The **READ_REGISTER_USHORT** routine reads a USHORT value from the specified register address.

## Parameters

### `Register` [in]

Pointer to the register address, which must be a mapped range in memory space.

## Return value

**READ_REGISTER_USHORT** returns the USHORT value read from the specified register address.

## Remarks

Callers of **READ_REGISTER_USHORT** can be running at any IRQL, assuming the *Register* is resident, mapped device memory.