# C_ASSERT macro

## Description

Checks assertions at compile time.

## Parameters

### `e`

An expression that can be determined at compile time.

## Remarks

The **C_ASSERT** macro is defined as follows.

```cpp
#define C_ASSERT(e) typedef char __C_ASSERT__[(e)?1:-1]
```

The following examples demonstrate common types of compile-time assertions.

```cpp
C_ASSERT (BUFFER_CCH_SIZE <= MAX_PATH);

C_ASSERT (ARRAYSIZE(array1) == ARRAYSIZE(array2));

C_ASSERT (FIELD_OFFSET(STRUCT_DEF, MemberName) == 0x1d4);

C_ASSERT (sizeof(BOOLEAN) == sizeof(UCHAR));
```