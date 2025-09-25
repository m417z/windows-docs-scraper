# WCN_VALUE_TYPE_CONFIGURATION_ERROR enumeration

## Description

The **WCN_VALUE_TYPE_CONFIGURATION_ERROR** enumeration defines possible error values returned to a device while attempting to configure to, and associate with, the WLAN.

## Constants

### `WCN_VALUE_CE_NO_ERROR:0`

No error. An application must be prepared to handle devices that signal 'No Error' even if the device detected an error.

### `WCN_VALUE_CE_OOB_INTERFACE_READ_ERROR:1`

Could not read the out-of-band (OOB) interface.

### `WCN_VALUE_CE_DECRYPTION_CRC_FAILURE:2`

Could not decrypt the Cyclic Redundancy Check (CRC) value.

### `WCN_VALUE_CE_2_4_CHANNEL_NOT_SUPPORTED:3`

The 2.4 GHz channel is not supported.

### `WCN_VALUE_CE_5_0_CHANNEL_NOT_SUPPORTED:4`

The 5.0 GHz channel is not supported.

### `WCN_VALUE_CE_SIGNAL_TOO_WEAK:5`

The wireless signal is not strong enough to initiate a connection.

**Note** Not supported in WPS 2.0.

### `WCN_VALUE_CE_NETWORK_AUTHENTICATION_FAILURE:6`

Network authentication failed.

**Note** Not supported in WPS 2.0.

### `WCN_VALUE_CE_NETWORK_ASSOCIATION_FAILURE:7`

Network association failed.

**Note** Not supported in WPS 2.0.

### `WCN_VALUE_CE_NO_DHCP_RESPONSE:8`

The DHCP server did not respond.

**Note** Not supported in WPS 2.0.

### `WCN_VALUE_CE_FAILED_DHCP_CONFIG:9`

DHCP configuration failed.

**Note** Not supported in WPS 2.0.

### `WCN_VALUE_CE_IP_ADDRESS_CONFLICT:10`

There was an IP address conflict.

**Note** Not supported in WPS 2.0.

### `WCN_VALUE_CE_COULD_NOT_CONNECT_TO_REGISTRAR:11`

Could not connect to the registrar.

### `WCN_VALUE_CE_MULTIPLE_PBC_SESSIONS_DETECTED:12`

Multiple push button configuration (PBC) sessions were detected.

### `WCN_VALUE_CE_ROGUE_ACTIVITY_SUSPECTED:13`

Rogue activity is suspected.

### `WCN_VALUE_CE_DEVICE_BUSY:14`

The device is busy.

### `WCN_VALUE_CE_SETUP_LOCKED:15`

Setup is locked.

### `WCN_VALUE_CE_MESSAGE_TIMEOUT:16`

The message timed out.

**Note** Not supported in WPS 2.0.

### `WCN_VALUE_CE_REGISTRATION_SESSION_TIMEOUT:17`

The registration session timed out.

**Note** Not supported in WPS 2.0.

### `WCN_VALUE_CE_DEVICE_PASSWORD_AUTH_FAILURE:18`

Device password authentication failed.

## See also

[WCN_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/wcntypes/ne-wcntypes-wcn_attribute_type)