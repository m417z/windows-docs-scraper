# WsCountOf macro

## Syntax

```cpp
ULONG WsCountOf(
  [in]   arrayValue
);
```

## Return value

Type: **ULONG**

The number of elements in the array.

## Description

Returns the number of elements a specified array.

## Parameters

### `arrayValue` [in]

The array of objects for which for which to get the count.
The array type can be either a valid C data type or user defined data type. The array must be static.