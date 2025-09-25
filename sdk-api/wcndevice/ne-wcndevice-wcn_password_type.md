# WCN_PASSWORD_TYPE enumeration

## Description

The **WCN_PASSWORD_TYPE** enumeration defines the authentication that will be used in a WPS session.

## Constants

### `WCN_PASSWORD_TYPE_PUSH_BUTTON:0`

Indicates the device uses a WPS button interface to put the device into wireless provisioning mode. If this value is specified when calling [IWCNDevice::SetPassword](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-setpassword), set *dwPasswordLength* to zero and *pbPassword* to **NULL**.

### `WCN_PASSWORD_TYPE_PIN`

Indicates that authentication is secured via a PIN. The user must provide the PIN of the device. Usually, the PIN is a 4 or 8-digit number printed on a label attached to the device, or displayed on the screen. If this value is specified when calling [IWCNDevice::SetPassword](https://learn.microsoft.com/windows/desktop/api/wcndevice/nf-wcndevice-iwcndevice-setpassword), set *dwPasswordLength* to the number of digits in the password, and *pbPassword* to point to a buffer containing the ASCII representation of the pin.

### `WCN_PASSWORD_TYPE_PIN_REGISTRAR_SPECIFIED`

Indicates that authentication is secured via a PIN, as above, but that the PIN is specified by the registrar.

**Note** Only available in Windows 8.

### `WCN_PASSWORD_TYPE_OOB_SPECIFIED`

### `WCN_PASSWORD_TYPE_WFDS`

## See also

[WCN_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/wcntypes/ne-wcntypes-wcn_attribute_type)