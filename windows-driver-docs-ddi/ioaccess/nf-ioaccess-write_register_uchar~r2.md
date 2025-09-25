# WRITE_REGISTER_UCHAR function

## Description

The **WRITE_REGISTER_UCHAR** routine writes a byte to the specified address.

## Parameters

### `Register` [in]

Pointer to the register, which must be a mapped range in memory space.

### `Value` [in]

Specifies a byte to be written to the register.

## Syntax

```cpp
VOID WRITE_REGISTER_UCHAR(
  _In_ PUCHAR Register,
  _In_ UCHAR  Value
);
```

## Remarks

Callers of **WRITE_REGISTER_UCHAR** can be running at any IRQL, assuming the *Register* is resident, mapped device memory.