# IWRdsProtocolLicenseConnection::RequestLicensingCapabilities

## Description

Requests license capabilities from the client.

## Parameters

### `ppLicenseCapabilities` [out]

A pointer to a [WRDS_LICENSE_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_license_capabilities) structure that contains information about the client license capabilities.

### `pcbLicenseCapabilities` [in, out]

A pointer to an integer that contains the size of the structure specified by the *ppLicensingCapabilities* parameter.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWRdsProtocolLicenseConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocollicenseconnection)