# WRITE_REGISTER_USHORT function (miniport.h)

## Description

The **WRITE_REGISTER_USHORT** routine writes a USHORT value to the specified address.

## Parameters

### `Register` [in]

Pointer to the register, which must be a mapped range in memory space.

### `Value` [in]

Specifies a USHORT value to be written to the register.

## Remarks

Callers of **WRITE_REGISTER_USHORT** can be running at any IRQL, assuming the *Register* is resident, mapped device memory.