# INDEXTOOVERLAYMASK macro

## Syntax

```cpp
UINT INDEXTOOVERLAYMASK(
   UINT i
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

No return value.

## Description

Prepares the index of an overlay mask so that the [ImageList_Draw](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_draw) function can use it.

## Parameters

### `i`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An index of an overlay mask.

## Remarks

The **INDEXTOOVERLAYMASK** macro is defined as follows.

``` syntax
#define INDEXTOOVERLAYMASK(i) ((i) << 8)
```