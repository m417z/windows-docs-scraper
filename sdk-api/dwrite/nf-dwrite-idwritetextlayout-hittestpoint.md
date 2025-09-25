# IDWriteTextLayout::HitTestPoint

## Description

 The application calls this function passing in a specific pixel location
relative to the top-left location of the layout box and obtains the
information about the correspondent hit-test metrics of the text string
where the hit-test has occurred. When the specified pixel location is
outside the text string, the function sets the output value **isInside* to
**FALSE**.

## Parameters

### `pointX`

Type: **FLOAT**

The pixel location X to hit-test, relative to the top-left location of the layout box.

### `pointY`

Type: **FLOAT**

The pixel location Y to hit-test, relative to the top-left location of the layout box.

### `isTrailingHit` [out]

Type: **BOOL***

An output flag that indicates whether the hit-test location is at the leading or the trailing
side of the character. When the output **isInside* value is set to **FALSE**, this value is set according to the output
*hitTestMetrics->textPosition* value to represent the edge closest to the hit-test location.

### `isInside` [out]

Type: **BOOL***

An output flag that indicates whether the hit-test location is inside the text string.
When **FALSE**, the position nearest the text's edge is returned.

### `hitTestMetrics` [out]

Type: **[DWRITE_HIT_TEST_METRICS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_hit_test_metrics)***

The output geometry fully enclosing the hit-test location. When the output **isInside* value
is set to **FALSE**, this structure represents the geometry enclosing the edge closest to the hit-test location.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)