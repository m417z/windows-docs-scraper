# DSA_GetItemPtr function

## Description

[**DSA_GetItemPtr** is available for use in the operating

systems specified in the Requirements section. It may be altered or unavailable in

subsequent versions.]

Gets a pointer to an element from a dynamic structure array (DSA).

## Parameters

### `hdsa` [in]

Type: **HDSA**

A handle to the DSA containing the element.

### `i` [in]

Type: **int**

The index of the element to be retrieved (zero-based).

## Return value

Returns a pointer to the specified element or **NULL** if the call fails.

## Remarks

Using the element pointer that this function returns, you can modify the data in that element directly. However, be aware that a subsequent insert or destroy operation could cause this pointer value to become invalid or to point to a different element.