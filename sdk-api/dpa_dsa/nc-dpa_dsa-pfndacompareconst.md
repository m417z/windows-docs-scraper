# PFNDACOMPARECONST callback function

## Description

Defines the prototype for the compare function used by [DSA_Sort](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dsa_sort) when the items being compared are constant objects.

## Parameters

### `p1` [in, optional]

Type: **const void***

A pointer to the first item in the comparison.

### `p2` [in, optional]

Type: **const void***

A pointer to the second item in the comparison.

### `lParam` [in]

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Additional data passed to *pfnCmp*.

## Return value

Type: **int**

The meaning of the return values depends on the function that uses this callback prototype. The return values for [DSA_Sort](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dsa_sort) are as follows:

|  |  |
| --- | --- |
| less than 0 | If *p1* should be sorted ahead of *p2*. |
| equal to 0 | If *p1* and *p2* should be sorted together. |
| greater than 0 | If *p1* should be sorted after *p2*. |

## Remarks

Alternate names for this callback are **PFNDPACOMPARECONST** and **PFNDSACOMPARECONST**.