# READ_REGISTER_ULONG function (miniport.h)

## Description

The **READ_REGISTER_ULONG** routine reads a ULONG value from the specified register address.

## Parameters

### `Register` [in]

Pointer to the register address, which must be a mapped range in memory space.

## Return value

**READ_REGISTER_ULONG** returns the ULONG value read from the specified register address.

## Remarks

Callers of **READ_REGISTER_ULONG** can be running at any IRQL, assuming the *Register* is resident, mapped device memory.