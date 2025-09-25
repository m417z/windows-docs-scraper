# DPA_Create function

## Description

[**DPA_Create** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Creates a dynamic pointer array (DPA).

## Parameters

### `cItemGrow`

Type: **int**

The number of elements by which the array should be expanded, if the DPA needs to be enlarged.

## Return value

Type: **HDPA**

Returns a handle to a DPA if successful, or **NULL** if the call fails.

## See also

[DPA_CreateEx](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dpa_createex)