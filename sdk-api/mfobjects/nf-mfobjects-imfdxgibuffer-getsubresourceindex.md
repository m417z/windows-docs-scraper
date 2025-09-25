# IMFDXGIBuffer::GetSubresourceIndex

## Description

Gets the index of the subresource that is associated with this media buffer.

## Parameters

### `puSubresource` [out]

Receives the zero-based index of the subresource.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The subresource index is specified when you create the media buffer object. See [MFCreateDXGISurfaceBuffer](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfcreatedxgisurfacebuffer).

For more information about texture subresources, see [ID3D11Device::CreateTexture2D](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createtexture2d).

## See also

[IMFDXGIBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgibuffer)