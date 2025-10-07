# WFD\_DISPLAY\_SINK\_NOTIFICATION\_RESULT structure

The **WFD\_DISPLAY\_SINK\_NOTIFICATION\_RESULT** structure describes the result that you can optionally set after processing a display sink notfication in the [**WFD\_DISPLAY\_SINK\_NOTIFICATION\_CALLBACK**](https://learn.microsoft.com/windows/win32/nativewifi/wfd-display-sink-notification-callback) function.

## Members

**Header**

A [**WFD\_DISPLAY\_SINK\_OBJECT\_HEADER**](https://learn.microsoft.com/windows/win32/nativewifi/wfd-display-sink-object-header) that describes the data included in the notification result.

**type**

A [**WFD\_DISPLAY\_SINK\_NOTIFICATION\_TYPE**](https://learn.microsoft.com/windows/win32/nativewifi/wfd-display-sink-notification-type) value that indicates the type of the notification result. This parameter also determines which Info to use in the union below.

**ProvisioningData**

Info about the result of a provisioning request. Use this if *type* has the value **ProvisioningRequestNotification**.

**ConfigMethod**

The method for showing UI for interactive acceptance.

**uPassKeyLength**

The number of wide characters in *Passkey*, not counting any NULL-terminator.

**Passkey**

Contains the pass key as an array of wide characters. WFD\_SINK\_WPS\_INFO\_MAX\_PASSKEY\_LENGTH is defined as the value (8).

**ReconnectData**

Info about the result of a reconnect request. Use this if *type* has the value **ReconnectRequestNotification**.

**strProfile**

A pointer to a NULL-terminated string describing the profile.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8.1 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 R2 \[desktop apps only\]<br> |
| Header<br> | Wfdsink.h |

