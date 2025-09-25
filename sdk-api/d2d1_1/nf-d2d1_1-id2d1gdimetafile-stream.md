# ID2D1GdiMetafile::Stream

## Description

This method streams the contents of the command to the given metafile sink.

## Parameters

### `sink`

Type: **[ID2D1GdiMetafileSink](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1gdimetafilesink)**

The sink into which Direct2D will call back.

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