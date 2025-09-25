# IWTSProtocolConnection::GetLicenseConnection

## Description

[**IWTSProtocolConnection::GetLicenseConnection** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolConnection::GetLicenseConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-getlicenseconnection).]

Retrieves an [IWTSProtocolLicenseConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocollicenseconnection) object that is used to begin the client licensing process. The protocol must add a reference to this object before returning. When the Remote Desktop Services service has finished the licensing process, it will release the reference.

## Parameters

### `ppLicenseConnection` [out]

The address of a pointer to an [IWTSProtocolLicenseConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocollicenseconnection) interface.

## See also

[IWTSProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnection)