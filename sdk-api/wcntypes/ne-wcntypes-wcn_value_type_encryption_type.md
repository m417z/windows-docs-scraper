# WCN_VALUE_TYPE_ENCRYPTION_TYPE enumeration

## Description

The **WCN_VALUE_TYPE_ENCRYPTION_TYPE** enumeration defines the supported WLAN encryption types.

## Constants

### `WCN_VALUE_ET_NONE:0x1`

Specifies support for unsecured wireless activity.

### `WCN_VALUE_ET_WEP:0x2`

Specifies support for the Wired Equivalent Privacy (WEP) encryption method.

**Note** Not available for WPS 2.0.

### `WCN_VALUE_ET_TKIP:0x4`

Specifies support for the Temporal Key Integrity Protocol (TKIP) encryption method.

**Note** Not available for WPS 2.0.

### `WCN_VALUE_ET_AES:0x8`

Specifies support for the Advanced Encryption Standard (AES) encryption method.

### `WCN_VALUE_ET_TKIP_AES_MIXED:0xc`

Specifies support for WPAPSK/WPA2PSK mixed-mode encryption.

**Note** Not supported in WPS 1.0. Only available in Windows 8.

## See also

[WCN_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/wcntypes/ne-wcntypes-wcn_attribute_type)