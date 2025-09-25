# ID2D1Factory1::CreateGdiMetafile

## Description

Creates a new [ID2D1GdiMetafile](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1gdimetafile) object that you can use to replay metafile content.

## Parameters

### `metafileStream` [in]

Type: **IStream***

A stream object that has the metafile data.

### `metafile` [out]

Type: **[ID2D1GdiMetafile](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1gdimetafile)****

The address of the newly created GDI metafile object.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid value was passed to the method. |

## See also

[ID2D1Factory1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1factory1)