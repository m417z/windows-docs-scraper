# WRITE_REGISTER_UCHAR function (miniport.h)

## Description

The **WRITE_REGISTER_UCHAR** routine writes a byte to the specified address.

## Parameters

### `Register` [in]

Pointer to the register, which must be a mapped range in memory space.

### `Value` [in]

Specifies a byte to be written to the register.

## Remarks

Callers of **WRITE_REGISTER_UCHAR** can be running at any IRQL, assuming the *Register* is resident, mapped device memory.