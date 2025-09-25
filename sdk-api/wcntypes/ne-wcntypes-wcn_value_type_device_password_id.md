# WCN_VALUE_TYPE_DEVICE_PASSWORD_ID enumeration

## Description

The **WCN_VALUE_TYPE_DEVICE_PASSWORD_ID** enumeration defines values that specify the origin or 'type' of a password.

## Constants

### `WCN_VALUE_DP_DEFAULT:0`

The PIN password, obtained from the label, or
display will be used. This password may correspond to the label, display, or a user-defined password that has been
configured to replace the original device password.

To authenticate with the default password ID, call [IWCNDevice::SetPassword](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-setpassword) with the PIN password type defined by [WCN_PASSWORD_TYPE](https://learn.microsoft.com/windows/desktop/api/wcndevice/ne-wcndevice-wcn_password_type).

### `WCN_VALUE_DP_USER_SPECIFIED:0x1`

The user has overridden the default password with a manually selected value.

**Note** Not supported in Windows 7.

### `WCN_VALUE_DP_MACHINE_SPECIFIED:0x2`

The default PIN password has been overridden by a strong, machine-generated
device password value.

**Note** Not supported in Windows 7.

### `WCN_VALUE_DP_REKEY:0x3`

The 256-bit rekeying password
associated with the device will be used.

**Note** Not supported in Windows 7.

### `WCN_VALUE_DP_PUSHBUTTON:0x4`

A password entered via a push button interface will be used.

To authenticate with the default password ID, call [IWCNDevice::SetPassword](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-setpassword) with the push button password type defined by [WCN_PASSWORD_TYPE](https://learn.microsoft.com/windows/desktop/api/wcndevice/ne-wcndevice-wcn_password_type).

### `WCN_VALUE_DP_REGISTRAR_SPECIFIED:0x5`

A PIN has been obtained from the Registrar via a display or
other out-of-band method.

**Note** Not supported in Windows 7.

### `WCN_VALUE_DP_NFC_CONNECTION_HANDOVER:0x7`

### `WCN_VALUE_DP_WFD_SERVICES:0x8`

### `WCN_VALUE_DP_OUTOFBAND_MIN:0x10`

### `WCN_VALUE_DP_OUTOFBAND_MAX:0xffff`

## See also

[WCN_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/wcntypes/ne-wcntypes-wcn_attribute_type)