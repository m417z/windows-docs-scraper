# INDEXTOSTATEIMAGEMASK macro

## Syntax

```cpp
UINT INDEXTOSTATEIMAGEMASK(
   UINT i
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the index of a state image.

## Description

Prepares the index of a state image so that a tree-view control or list-view control can use the index to retrieve the state image for an item.

## Parameters

### `i`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of a state image.

## Remarks

The **INDEXTOSTATEIMAGEMASK** macro is defined as follows:

``` syntax
#define INDEXTOSTATEIMAGEMASK(i) ((i) << 12)
```