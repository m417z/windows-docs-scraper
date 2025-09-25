# IDWriteInlineObject::GetMetrics

## Description

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout) calls this callback function to get the measurement of the inline object.

## Parameters

### `metrics` [out]

Type: **[DWRITE_INLINE_OBJECT_METRICS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_inline_object_metrics)***

When this method returns, contains a structure describing the geometric measurement of an
application-defined inline object. These metrics are in relation to the baseline of the adjacent text.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteInlineObject](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriteinlineobject)