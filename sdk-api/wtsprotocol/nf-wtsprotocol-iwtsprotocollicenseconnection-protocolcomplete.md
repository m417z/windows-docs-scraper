# IWTSProtocolLicenseConnection::ProtocolComplete

## Description

[**IWTSProtocolLicenseConnection::ProtocolComplete** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolLicenseConnection::ProtocolComplete](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocollicenseconnection-protocolcomplete).]

Notifies the protocol whether the licensing process completed successfully.

## Parameters

### `ulComplete` [in]

An integer that specifies whether the licensing process ended successfully. A value of one (1) means success. All other values indicate failure.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWTSProtocolLicenseConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocollicenseconnection)