# IWTSProtocolConnection::GetUserData

## Description

[**IWTSProtocolConnection::GetUserData** is no longer available for use as of Windows Server 2012. Instead, use [IWRdsProtocolSettings::MergeSettings](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolsettings-mergesettings).]

Sends merged policy settings to the protocol and requests user policy settings from the protocol.

## Parameters

### `pPolicyData` [in]

A pointer to a [WTS_POLICY_DATA](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_policy_data) structure that contains the merged Group Policy values.

### `pClientData` [in, out]

A pointer to a [WTS_USER_DATA](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wts_user_data) structure that contains client property information.

## Remarks

The Remote Desktop Services service merges all policy data, including listener settings, client-provided data, and Group Policy data, before calling this method.

## See also

[IWTSProtocolConnection](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwtsprotocolconnection)