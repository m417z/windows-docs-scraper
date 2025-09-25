# WCN_VALUE_TYPE_WI_FI_PROTECTED_SETUP_STATE enumeration

## Description

The **WCN_VALUE_TYPE_WI_FI_PROTECTED_SETUP_STATE** enumeration defines values that indicate if a device is configured.

## Constants

### `WCN_VALUE_SS_RESERVED00:0`

This value is reserved.

### `WCN_VALUE_SS_NOT_CONFIGURED:0x1`

The device is not configured.

### `WCN_VALUE_SS_CONFIGURED:0x2`

The device is configured.

## Remarks

A device is considered 'not configured' if it is using factory default wireless settings. If the wireless settings have been customized by the user, the device is considered to be 'configured'. A factory reset will restore the device to a 'not configured' state.

## See also

[WCN_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/wcntypes/ne-wcntypes-wcn_attribute_type)