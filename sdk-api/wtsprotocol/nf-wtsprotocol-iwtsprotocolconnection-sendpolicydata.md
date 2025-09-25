# IWTSProtocolConnection::SendPolicyData

## Description

[**IWTSProtocolConnection::SendPolicyData** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolManager::NotifySettingsChange](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolmanager-notifysettingschange).]

Sends computer policy settings to the custom protocol. These settings are a combination of listener policies and Group Policy settings.

## Parameters

### `pPolicyData` [in]

A pointer to a [WTS_POLICY_DATA](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_policy_data) structure that contains computer policy settings.

## Remarks

The **SendPolicyData** method is the second method called by the Remote Desktop Services service during a connection sequence. The protocol must call the [OnReady](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocolconnectioncallback-onready) method after this method is called, or the connection is dropped.

## See also

[IWTSProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnection)