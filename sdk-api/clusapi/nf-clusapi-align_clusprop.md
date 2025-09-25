# ALIGN_CLUSPROP macro

## Description

Aligns structures properly within [value lists](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/value-lists).

## Parameters

### `count`

Size, in bytes, of the data to align. This value must be a constant.

## Remarks

**ALIGN_CLUSPROP** returns a value that is greater than or equal to *count*. The value represents the total byte size of the data plus the padding required for proper alignment.

ClusAPI.h defines **ALIGN_CLUSPROP** as follows:

`#define ALIGN_CLUSPROP( count ) ((count + 3) & ~3)`

#### Examples

The following example illustrates how to use **ALIGN_CLUSPROP** to calculate the size of a value list entry. For additional examples, see [Using Lists and Tables](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-lists-and-tables).

```cpp
WCHAR szData[] = L"StringData";
DWORD cbSizeofValueListEntry;

cbSizeofValueListEntry = sizeof( CLUSPROP_VALUE ) +
                         ALIGN_CLUSPROP( sizeof( szData ) );

```