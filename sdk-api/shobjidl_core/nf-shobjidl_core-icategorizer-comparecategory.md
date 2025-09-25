# ICategorizer::CompareCategory

## Description

Determines the relative order of two items in their item identifier lists, and hence in the UI.

## Parameters

### `csfFlags`

Type: **[CATSORT_FLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-catsort_flags)**

A flag that specifies how the comparison should be performed. The parameter should be one of the values in [CATSORT_FLAGS](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-catsort_flags).

### `dwCategoryId1`

Type: **DWORD**

A **DWORD** that specifies the first category identifier to use in the comparison.

### `dwCategoryId2`

Type: **DWORD**

A **DWORD** that specifies the second category identifier to use in the comparison.

## Return value

Type: **HRESULT**

If this method is successful, the CODE field of the HRESULT contains a value that specifies the outcome of the comparison, otherwise it returns a COM error code.

## Remarks

The following table shows the values returned in the CODE field of the HRESULT.

|  |  |
| --- | --- |
| Less than zero | The first item should precede the second (*dwCategoryId1* < *dwCategoryId2*). |
| Greater than zero | The first item should follow the second (*dwCategoryId1* > *dwCategoryId2*). |
| Zero | The two items are the same (*dwCategoryId1* = *dwCategoryId2*). |