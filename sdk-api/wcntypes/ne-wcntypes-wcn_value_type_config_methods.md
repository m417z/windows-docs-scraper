# WCN_VALUE_TYPE_CONFIG_METHODS enumeration

## Description

The **WCN_VALUE_TYPE_CONFIG_METHODS** enumeration defines the configuration methods supported by the Enrollee or Registrar. One or more of the following configuration methods must be supported.

## Constants

### `WCN_VALUE_CM_USBA:0x1`

USB-A (flash drive) configuration is supported.

**Note** Not supported in Windows 7 and later. Not supported in WPS 2.0.

### `WCN_VALUE_CM_ETHERNET:0x2`

Ethernet configuration is supported.

**Note** Not supported in Windows 7 and later. Not supported in WPS 2.0.

### `WCN_VALUE_CM_LABEL:0x4`

Label configuration is supported. To authenticate with the default password ID, call [IWCNDevice::SetPassword](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-setpassword) with the PIN password type defined by [WCN_PASSWORD_TYPE](https://learn.microsoft.com/windows/desktop/api/wcndevice/ne-wcndevice-wcn_password_type).

### `WCN_VALUE_CM_DISPLAY:0x8`

Display configuration is supported. To authenticate with the default password ID, call [IWCNDevice::SetPassword](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-setpassword) with the PIN password type defined by [WCN_PASSWORD_TYPE](https://learn.microsoft.com/windows/desktop/api/wcndevice/ne-wcndevice-wcn_password_type).

**Note** For WPS 2.0, use **WCN_VALUE_CM_VIRT_DISPLAY** or **WCN_VALUE_CM_PHYS_DISPLAY**.

### `WCN_VALUE_CM_EXTERNAL_NFC:0x10`

External near-field communication (NFC) token configuration is supported.

**Note** Not supported in Windows 7.

### `WCN_VALUE_CM_INTEGRATED_NFC:0x20`

Integrated NFC token configuration is supported.

**Note** Not supported in Windows 7.

### `WCN_VALUE_CM_NFC_INTERFACE:0x40`

NFC interface configuration is supported.

**Note** Not supported in Windows 7.

### `WCN_VALUE_CM_PUSHBUTTON:0x80`

Push button configuration is supported. To authenticate with the default password ID, call [IWCNDevice::SetPassword](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-setpassword) with the push button password type defined by [WCN_PASSWORD_TYPE](https://learn.microsoft.com/windows/desktop/api/wcndevice/ne-wcndevice-wcn_password_type).

**Note** For WPS 2.0, use **WCN_VALUE_CM_VIRT_PUSHBUTTON** or **WCN_VALUE_CM_PHYS_PUSHBUTTON**.

### `WCN_VALUE_CM_KEYPAD:0x100`

Keypad configuration is supported.

**Note** Not supported in Windows 7.

### `WCN_VALUE_CM_VIRT_PUSHBUTTON:0x280`

Virtual push button configuration is supported. To authenticate with the default password ID, call [IWCNDevice::SetPassword](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-setpassword) with the push button password type defined by [WCN_PASSWORD_TYPE](https://learn.microsoft.com/windows/desktop/api/wcndevice/ne-wcndevice-wcn_password_type).

**Note** Only available in Windows 8.

### `WCN_VALUE_CM_PHYS_PUSHBUTTON:0x480`

Physical push button configuration is supported. To authenticate with the default password ID, call [IWCNDevice::SetPassword](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-setpassword) with the push button password type defined by [WCN_PASSWORD_TYPE](https://learn.microsoft.com/windows/desktop/api/wcndevice/ne-wcndevice-wcn_password_type).

**Note** Only available in Windows 8.

### `WCN_VALUE_CM_VIRT_DISPLAY:0x2008`

Virtual display configuration is supported. To authenticate with the default password ID, call [IWCNDevice::SetPassword](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-setpassword) with the PIN password type defined by [WCN_PASSWORD_TYPE](https://learn.microsoft.com/windows/desktop/api/wcndevice/ne-wcndevice-wcn_password_type).

**Note** Only available in Windows 8.

### `WCN_VALUE_CM_PHYS_DISPLAY:0x4008`

Physical display configuration is supported. To authenticate with the default password ID, call [IWCNDevice::SetPassword](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-setpassword) with the PIN password type defined by [WCN_PASSWORD_TYPE](https://learn.microsoft.com/windows/desktop/api/wcndevice/ne-wcndevice-wcn_password_type).

**Note** Only available in Windows 8.

## See also

[WCN_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/wcntypes/ne-wcntypes-wcn_attribute_type)