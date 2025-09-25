# IWRdsProtocolManager::NotifySessionOfServiceStop

## Description

Notifies the protocol provider that the Remote Desktop Services service has stopped for a given session.

## Parameters

### `SessionId` [in]

A pointer to a [WRDS_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_session_id) structure that uniquely identifies the session.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWRdsProtocolManager](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolmanager)