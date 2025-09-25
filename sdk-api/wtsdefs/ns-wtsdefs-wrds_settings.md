# WRDS_SETTINGS structure

## Description

Contains policy-related setting information for a remote session.

This structure is used in the [IWRdsProtocolSettings](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolsettings) interface and the [Initialize](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwrdsprotocolmanager-initialize) method of the [IWRdsProtocolManager](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nn-wtsprotocol-iwrdsprotocolmanager) interface.

## Members

### `WRdsSettingType`

The category of settings contained (machine group policy, user group policy, or user security accounts manager).

### `WRdsSettingLevel`

The setting level.

### `WRdsSetting`

A structure that contains the policy setting states and values.

A structure that contains the policy setting states and values.