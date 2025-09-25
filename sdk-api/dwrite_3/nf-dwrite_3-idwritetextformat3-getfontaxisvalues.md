## Description

Retrieves the list of font axis values on the format.

## Parameters

### `fontAxisValues` [out]

Type: **[DWRITE_FONT_AXIS_VALUE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_axis_value)\***

A pointer to an array of **DWRITE_FONT_AXIS_VALUE** structures into which **GetFontAxisValues** writes the list of font axis values. You're responsible for managing the size and the lifetime of this array. Call [GetFontAxisValueCount](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritetextformat3-getfontaxisvaluecount) to determine the size of array to allocate.

### `fontAxisValueCount`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The maximum number of font axis values to write into the memory block pointed to by `fontAxisValues`.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

## See also