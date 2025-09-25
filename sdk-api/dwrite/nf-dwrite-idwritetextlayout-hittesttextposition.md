# IDWriteTextLayout::HitTestTextPosition

## Description

 The application calls this function to get the pixel location relative
to the top-left of the layout box given the text position and the
logical side of the position. This function is normally used as part of
caret positioning of text where the caret is drawn at the location
corresponding to the current text editing position. It may also be used
as a way to programmatically obtain the geometry of a particular text
position in UI automation.

## Parameters

### `textPosition`

Type: **UINT32**

The text position used to get the pixel location.

### `isTrailingHit`

Type: **BOOL**

A Boolean flag that indicates whether the pixel location is of the leading or the trailing side of the specified text position.

### `pointX` [out]

Type: **FLOAT***

When this method returns, contains the output pixel location X, relative to the top-left location of the layout box.

### `pointY` [out]

Type: **FLOAT***

When this method returns, contains the output pixel location Y, relative to the top-left location of the layout box.

### `hitTestMetrics` [out]

Type: **[DWRITE_HIT_TEST_METRICS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_hit_test_metrics)***

When this method returns, contains the output geometry fully enclosing the specified text position.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)