# IMFNetProxyLocatorFactory::CreateProxyLocator

## Description

Creates an [IMFNetProxyLocator](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetproxylocator) interface proxy locator object based on the protocol name.

## Parameters

### `pszProtocol` [in]

Null-terminated wide-character string containing the protocol name (for example, RTSP or HTTP).

### `ppProxyLocator` [out]

Receives a pointer to the [IMFNetProxyLocator](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetproxylocator) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFNetProxyLocatorFactory](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetproxylocatorfactory)