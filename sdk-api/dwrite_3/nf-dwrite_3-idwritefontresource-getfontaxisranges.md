## Description

Retrieves the value ranges of each axis.

## Parameters

### `fontAxisRanges` [out]

Type: **[DWRITE_FONT_AXIS_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_axis_range)\***

A pointer to an array of **DWRITE_FONT_AXIS_RANGE** structures into which **GetFontAxisRanges** writes the list of font axis value ranges. You're responsible for managing the size and the lifetime of this array. Call [GetFontAxisCount](https://learn.microsoft.com/windows/win32/api/dwrite_3/nf-dwrite_3-idwritefontresource-getfontaxiscount) to determine the size of array to allocate.

### `fontAxisRangeCount`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The maximum number of font axis value ranges to write into the memory block pointed to by `fontAxisRanges`.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

|Return value|Description|
|-|-|
|E_INVALIDARG|`fontAxisValueCount` doesn't match the value returned by **GetFontAxisCount**.|

## Remarks

A non-varying axis has an empty range (*minValue* == *maxValue*).

## See also