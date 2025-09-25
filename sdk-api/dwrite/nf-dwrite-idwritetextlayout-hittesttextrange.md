# IDWriteTextLayout::HitTestTextRange

## Description

 The application calls this function to get a set of hit-test metrics corresponding to a range of text positions. One of the main usages is to implement highlight selection of the text string.

The function returns E_NOT_SUFFICIENT_BUFFER, which is equivalent to HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER), when the buffer size of hitTestMetrics is too small to hold all the regions calculated by the function. In this situation, the function sets the output value *actualHitTestMetricsCount to the number of geometries calculated.

The application is responsible for allocating a new buffer of greater size and calling the function again.

A good value to use as an initial value for maxHitTestMetricsCount may be calculated from the following equation:

``` syntax
maxHitTestMetricsCount = lineCount * maxBidiReorderingDepth
```

where lineCount is obtained from the value of the output argument
     *actualLineCount (from the function [IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)::GetLineLengths),
and the maxBidiReorderingDepth value from the [DWRITE_TEXT_METRICS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_text_metrics) structure of the output argument *textMetrics (from the function
[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)::[CreateTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nf-dwrite-idwritefactory-createtextlayout)).

## Parameters

### `textPosition`

Type: **UINT32**

The first text position of the specified range.

### `textLength`

Type: **UINT32**

The number of positions of the specified range.

### `originX`

Type: **FLOAT**

The origin pixel location X at the left of the layout box. This offset is added to the hit-test metrics returned.

### `originY`

Type: **FLOAT**

The origin pixel location Y at the top of the layout box. This offset is added to the hit-test metrics returned.

### `hitTestMetrics` [out, optional]

Type: **[DWRITE_HIT_TEST_METRICS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_hit_test_metrics)***

When this method returns, contains a pointer to a buffer of the output geometry fully enclosing the specified position range. The buffer must be at least as large as *maxHitTestMetricsCount*.

### `maxHitTestMetricsCount`

Type: **UINT32**

Maximum number of boxes *hitTestMetrics* could hold in its buffer memory.

### `actualHitTestMetricsCount` [out]

Type: **UINT32***

Actual number of geometries *hitTestMetrics* holds in its buffer memory.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)