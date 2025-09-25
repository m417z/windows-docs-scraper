# IWRdsProtocolManager::Initialize

## Description

Initializes the protocol manager.

## Parameters

### `pIWRdsSettings` [in]

A pointer to an object that implements the [IWRdsProtocolSettings](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolsettings) interface.

### `pWRdsSettings` [in]

A pointer to a [WRDS_SETTINGS](https://learn.microsoft.com/windows/desktop/api/wtsdefs/ns-wtsdefs-wrds_settings) structure that contains the settings to use.

## Return value

When you are implementing this method, return **S_OK** if the function succeeds. If it fails, return an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

A possible use for this method is to add a reference to the interface object pointer and to make a copy of the settings structure.

## See also

[IWRdsProtocolManager](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolmanager)