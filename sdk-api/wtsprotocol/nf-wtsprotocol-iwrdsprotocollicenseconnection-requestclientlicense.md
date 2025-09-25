# IWRdsProtocolLicenseConnection::RequestClientLicense

## Description

Requests a license from the client.

## Parameters

### `Reserve1` [in]

A pointer to a byte array that contains additional data that can be acted upon by the client.

### `Reserve2` [in]

An integer that contains the size, in bytes, of the data specified by the *Reserve1* parameter.

### `ppClientLicense` [out]

A pointer to a byte array that contains the license request.

### `pcbClientLicense` [in, out]

An integer that contains the size, in bytes, of the request specified by the *ppClientLicense* parameter.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

For more information about the byte arrays exchanged in this call (such as the **CLIENT_LICENSE_INFO**, **CLIENT_NEW_LICENSE_REQUEST**, and **CLIENT_PLATFORM_CHALLENGE_RESPONSE** packet structures), see [[MS-RDPELE]: Remote Desktop Protocol: Licensing Extension](https://learn.microsoft.com/openspecs/windows_protocols/ms-rdpele/3d3f160a-3ab3-4dfb-ba4e-47c27cd79409).

## See also

[IWRdsProtocolLicenseConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocollicenseconnection)