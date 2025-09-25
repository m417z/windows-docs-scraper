# WRITE_REGISTER_ULONG function

## Description

The **WRITE_REGISTER_ULONG** routine writes a ULONG value to the specified address.

## Parameters

### `Register` [in]

Pointer to the register which must be a mapped range in memory space.

### `Value` [in]

Specifies a ULONG value to be written to the register.

## Syntax

```cpp
VOID WRITE_REGISTER_ULONG(
  _In_ PULONG Register,
  _In_ ULONG  Value
);
```

## Remarks

Callers of **WRITE_REGISTER_ULONG** can be running at any IRQL, assuming the *Register* is resident, mapped device memory.