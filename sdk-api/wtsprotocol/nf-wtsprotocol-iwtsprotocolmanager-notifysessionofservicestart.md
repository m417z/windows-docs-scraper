# IWTSProtocolManager::NotifySessionOfServiceStart

## Description

[**IWTSProtocolManager::NotifySessionOfServiceStart** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolManager::NotifySessionOfServiceStart](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolmanager-notifysessionofservicestart).]

Notifies the protocol provider that the Remote Desktop Services service has started for a given session.

## Parameters

### `SessionId` [in]

A pointer to a [WTS_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_session_id) structure that uniquely identifies the session.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWTSProtocolManager](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolmanager)