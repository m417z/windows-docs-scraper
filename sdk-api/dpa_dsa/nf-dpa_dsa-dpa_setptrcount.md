# DPA_SetPtrCount macro

## Syntax

```cpp
int DPA_SetPtrCount(
  [in] HDPA hdpa,
  [in] int  cItems
);
```

## Return value

Type: **int**

Returns the number of pointers (elements) the DPA contains.

## Description

Sets the number of pointers in a dynamic pointer array (DPA).

## Parameters

### `hdpa` [in]

A handle to an existing DPA.

### `cItems` [in]

The number of items in the DPA.