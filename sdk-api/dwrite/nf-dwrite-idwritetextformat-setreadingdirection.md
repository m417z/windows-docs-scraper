# IDWriteTextFormat::SetReadingDirection

## Description

Sets the paragraph reading direction.

## Parameters

### `readingDirection`

Type: **[DWRITE_READING_DIRECTION](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_reading_direction)**

The text reading direction (for example, [DWRITE_READING_DIRECTION_RIGHT_TO_LEFT](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_reading_direction) for languages, such as
Arabic, that read from right to left) for a paragraph.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The reading direction and flow direction must always be set 90 degrees orthogonal to each other, or else you will get the error DWRITE_E_FLOWDIRECTIONCONFLICTS when you
use layout functions like Draw or GetMetrics. So if you set a vertical reading direction (for example, to DWRITE_READING_DIRECTION_TOP_TO_BOTTOM), then you must also
use SetFlowDirection to set the flow direction appropriately (for example, to DWRITE_FLOW_DIRECTION_RIGHT_TO_LEFT).

## See also

[IDWriteTextFormat](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextformat)