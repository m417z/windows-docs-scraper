# READ_REGISTER_UCHAR function

## Description

The **READ_REGISTER_UCHAR** routine reads a byte from the specified register address.

## Parameters

### `Register` [in]

Pointer to the register address, which must be a mapped range in memory space.

## Return value

**READ_REGISTER_UCHAR** returns the byte read from the specified register address.

## Syntax

```cpp
UCHAR READ_REGISTER_UCHAR(
  _In_ PUCHAR Register
);
```

## Remarks

Callers of **READ_REGISTER_UCHAR** can be running at any IRQL, assuming the *Register* is resident, mapped device memory.