# IWTSProtocolLicenseConnection::SendClientLicense

## Description

[**IWTSProtocolLicenseConnection::SendClientLicense** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolLicenseConnection::SendClientLicense](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocollicenseconnection-sendclientlicense).]

Sends a license to the client.

## Parameters

### `pClientLicense` [in]

A pointer to a byte array that contains the license.

### `cbClientLicense` [in]

An integer that contains the size, in bytes, of the license.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values). The remote connection manager logs any errors that you return.

## Remarks

For more information about the byte arrays exchanged in this call, see [[MS-RDPELE]: Remote Desktop Protocol: Licensing Extension](https://learn.microsoft.com/openspecs/windows_protocols/ms-rdpele/3d3f160a-3ab3-4dfb-ba4e-47c27cd79409).

## See also

[IWTSProtocolLicenseConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocollicenseconnection)