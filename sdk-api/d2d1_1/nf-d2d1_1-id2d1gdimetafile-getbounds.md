# ID2D1GdiMetafile::GetBounds

## Description

 Gets the bounds of the metafile, in device-independent pixels (DIPs), as reported in the metafile’s header.

## Parameters

### `bounds` [out]

Type: **[D2D1_RECT_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-rect-f)***

The bounds, in DIPs, of the metafile.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid value was passed to the method. |

## See also

[ID2D1GdiMetafile](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1gdimetafile)