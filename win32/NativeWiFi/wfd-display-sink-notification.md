# WFD\_DISPLAY\_SINK\_NOTIFICATION structure

The **WFD\_DISPLAY\_SINK\_NOTIFICATION** structure describes the notification passed to the [**WFD\_DISPLAY\_SINK\_NOTIFICATION\_CALLBACK**](https://learn.microsoft.com/windows/win32/nativewifi/wfd-display-sink-notification-callback) function.

## Members

**Header**

A [**WFD\_DISPLAY\_SINK\_OBJECT\_HEADER**](https://learn.microsoft.com/windows/win32/nativewifi/wfd-display-sink-object-header) that describes the data included in the notification.

**type**

A [**WFD\_DISPLAY\_SINK\_NOTIFICATION\_TYPE**](https://learn.microsoft.com/windows/win32/nativewifi/wfd-display-sink-notification-type) value that indicates the type of the notification. This parameter also determines which Info to use in the union below.

**strRemoteDeviceName**

Contains a NULL-terminated string containing the name of the remote device. WFD\_SINK\_MAX\_DEVICE\_NAME\_LENGTH is defined as the value (32).

**RemoteDeviceAddress**

A [**DOT11\_MAC\_ADDRESS**](https://learn.microsoft.com/windows/win32/nativewifi/dot11-mac-address-type) that contains the BSSID of the remote device.

**ProvisioningRequestInfo**

Info about a provisioning request. Use this if *type* has the value **ProvisioningRequestNotification**.

**hSessionHandle**

The session handle.

**PossibleConfigMethods**

Possible methods for showing UI for interactive acceptance.

**ReconnectRequestInfo**

Info about a reconnect request. Use this if *type* has the value **ReconnectRequestNotification**.

**GroupID**

The group id.

**ConnectedInfo**

Info about a connected notification. Use this if *type* has the value **ConnectedNotification**.

**hSessionHandle**

The session handle.

**guidSessionInterface**

A GUID indicating the session interface.

**GroupID**

The group id.

**strProfile**

A pointer to a NULL-terminated string describing the profile.

**LocalAddress**

The local address.

**RemoteAddress**

The remote address.

**uRTSPPort**

The RTSP port.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8.1 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 R2 \[desktop apps only\]<br> |
| Header<br> | Wfdsink.h |

