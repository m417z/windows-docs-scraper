# DSA_Create function

## Description

[**DSA_Create** is available for use in the operating

systems specified in the Requirements section. It may be altered or unavailable in

subsequent versions.]

Creates a dynamic structure array (DSA).

## Parameters

### `cbItem` [in]

Type: **int**

The size, in bytes, of the item.

### `cItemGrow` [in]

Type: **int**

The number of items by which the array should be incremented, if the DSA needs to be enlarged.

## Return value

Type: **HDSA**

Returns a handle to a DSA if successful, or **NULL** if the creation fails.

## Remarks

Unlike a dynamic pointer array (DPA), a DSA can contain elements of any size. This allows structures to be stored directly in the array.