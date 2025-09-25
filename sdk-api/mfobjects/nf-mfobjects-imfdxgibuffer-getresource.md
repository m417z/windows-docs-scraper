# IMFDXGIBuffer::GetResource

## Description

Queries the Microsoft DirectX Graphics Infrastructure (DXGI)surface for an interface.

## Parameters

### `riid` [in]

The interface identifier (IID) of the interface being requested.

### `ppvObject` [out]

Receives a pointer to the interface. The caller must release the interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOINTERFACE** | The object does not support the specified interface. |
| **MF_E_INVALIDREQUEST** | Invalid request. |

## Remarks

You can use this method to get a pointer to the [ID3D11Texture2D](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11texture2d) interface of the surface. If the buffer is locked, the method returns **MF_E_INVALIDREQUEST**.

## See also

[IMFDXGIBuffer](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfdxgibuffer)