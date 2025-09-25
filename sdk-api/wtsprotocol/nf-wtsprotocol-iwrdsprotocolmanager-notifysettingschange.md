# IWRdsProtocolManager::NotifySettingsChange

## Description

Notifies the protocol provider of changes in the settings within the Remote Desktop Services service.

## Parameters

### `pWRdsSettings` [in]

A pointer to a [WRDS_SETTINGS](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_settings) structure that contains the setting changes.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[IWRdsProtocolManager](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolmanager)