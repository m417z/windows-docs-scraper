# MFCreateProxyLocator function

## Description

Creates a default proxy locator.

## Parameters

### `pszProtocol` [in]

The name of the protocol.

**Note** In this release of Media Foundation, the default proxy locator does not support RTSP.

### `pProxyConfig` [in]

Pointer to the **IPropertyStore** interface of a property store that contains the proxy configuration in the [MFNETSOURCE_PROXYSETTINGS](https://learn.microsoft.com/windows/desktop/medfound/mfnetsource-proxysettings-property) property.

### `ppProxyLocator` [out]

Receives a pointer to the [IMFNetProxyLocator](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetproxylocator) interface. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Proxy Support for Network Sources](https://learn.microsoft.com/windows/desktop/medfound/proxy-support-for-network-sources)