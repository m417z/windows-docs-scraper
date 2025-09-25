## Description

Retrieves the axis ranges of a single item.

## Parameters

### `listIndex`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Zero-based index of the font in the set.

### `fontAxisRanges` [out]

Type: **[DWRITE_FONT_AXIS_RANGE](https://learn.microsoft.com/windows/win32/api/dwrite_3/ns-dwrite_3-dwrite_font_axis_range)\***

List of axis value ranges to retrieve.

### `maxFontAxisRangeCount`

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of axis value ranges to retrieve.

### `actualFontAxisRangeCount` [out]

Type: **[UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

The actual number of axis ranges written or needed.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

|Return value|Description|
|-|-|
|E_NOT_SUFFICIENT_BUFFER|The buffer is too small, with *actualFontAxisRangeCount* set to the needed size.|

## Remarks

## See also