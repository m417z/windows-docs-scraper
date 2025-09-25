# IWRdsProtocolManager::NotifyServiceStateChange

## Description

Notifies the protocol provider that the state of the Remote Desktop Services service is changing.

## Parameters

### `pTSServiceStateChange` [in]

A pointer to a [WRDS_SERVICE_STATE](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_service_state) structure that specifies
whether the service is starting, stopping, or changing its drain state.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWRdsProtocolManager](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolmanager)