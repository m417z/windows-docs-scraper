## Description

This topic describes the **WheaAdd2Ptr** macro.

## Parameters

### `P`

A pointer to an error record.

### `I`

A pointer to a descriptor.

## Remarks

The macro is defined as follows:

```cpp
#define WheaAdd2Ptr(P,I) ((PVOID)((PUCHAR)(P) + (I)))
```

## See also