# ID3D11VideoContext1::GetDataForNewHardwareKey

## Description

Allows the driver to return IHV specific information used when initializing the new hardware key.

## Parameters

### `pCryptoSession` [in]

Type: **ID3D11CryptoSession***

A pointer to the ID3D11CryptoSession interface. To get this pointer, call [ID3D11VideoDevice1::CreateCryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9video-createcryptosession).

### `PrivateInputSize` [in]

Type: **UINT**

The size of the memory referenced by the *pPrivateInputData* parameter.

### `pPrivatInputData` [in]

Type: **const void***

The private input data. The contents of this parameter is defined by the implementation of the secure execution environment. It may contain data about the license or about the stream properties.

### `pPrivateOutputData` [out]

Type: **UINT64***

A pointer to the private output data. The return data is defined by the implementation of the secure execution environment. It may contain graphics-specific data to be associated with the underlying hardware key.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following error codes.

|  |  |
| --- | --- |
| S_OK | The operation completed successfully. |
| E_OUTOFMEMORY | There is insufficient memory to complete the operation. |

## See also

[ID3D11VideoContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11videocontext1)