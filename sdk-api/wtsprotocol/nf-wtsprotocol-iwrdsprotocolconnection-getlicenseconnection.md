# IWRdsProtocolConnection::GetLicenseConnection

## Description

Retrieves an [IWRdsProtocolLicenseConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocollicenseconnection) object that is used to begin the client licensing process. The protocol must add a reference to this object before returning. When the Remote Desktop Services service has finished the licensing process, it will release the reference.

## Parameters

### `ppLicenseConnection` [out]

The address of a pointer to an [IWRdsProtocolLicenseConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocollicenseconnection) interface the receives the license connection object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code. Upon receiving an error, the Remote Desktop Services service will drop the connection.

## See also

[IWRdsProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolconnection)