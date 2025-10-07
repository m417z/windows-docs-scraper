# WFDDisplaySinkStart function

Performs the necessary initialization to allow the calling app to become a Miracast display sink. Your app should call this once on startup.

## Parameters

*uDeviceCategory* \[in\]

The device category.

*uSubCategory* \[in\]

The device subcategory.

*pCallbackContext* \[in, optional\]

An optional context pointer which is passed to the callback function specified in the *pfnCallback* parameter.

*pfnCallback* \[in\]

A pointer to the callback function to be called whenever there is a notification for the app. Notifications that can be sent are described in [**WFD\_DISPLAY\_SINK\_NOTIFICATION\_CALLBACK**](https://learn.microsoft.com/windows/win32/nativewifi/wfd-display-sink-notification-callback).

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
|------------------------------------------------------------------------------------------------------|----------------------------------------------------------------|
| **ERROR\_NOT\_SUPPORTED** | The display sink is not supported on this hardware.<br> |

## Remarks

This function performs the following tasks:

- Makes the PC discoverable
- Sets the P2P device info to reflect the category and sub category specified
- Sets the Miracast IEs on all Wi-Fi Direct frames with the device type as the sink
- Registers the specified callback to be invoked whenever there is an incoming connection

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8.1 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 R2 \[desktop apps only\]<br> |
| End of client support<br> | Windows 10<br> |
| End of server support<br> | Windows Server 2016<br> |
| Header<br> | Wfdsink.h |
| Library<br> | Wifidisplay.lib |
| DLL<br> | Wifidisplay.dll |

## See also

[**WFD\_DISPLAY\_SINK\_NOTIFICATION\_CALLBACK**](https://learn.microsoft.com/windows/win32/nativewifi/wfd-display-sink-notification-callback)

