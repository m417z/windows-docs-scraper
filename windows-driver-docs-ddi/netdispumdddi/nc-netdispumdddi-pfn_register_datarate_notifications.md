# PFN_REGISTER_DATARATE_NOTIFICATIONS callback function

## Description

Called by the user-mode driver to register with the operating system to receive network quality of service (QoS) notifications and the current network bandwidth of the Miracast connection.The data type of this function is **PFN_REGISTER_DATARATE_NOTIFICATIONS**.

## Parameters

### `hMiracastDeviceHandle` [in]

A handle that represents a Miracast device. The Miracast user-mode driver previously obtained this handle as the *hMiracastDeviceHandle* parameter in a call to the [CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context) function.

### `pNotificationContext` [in, optional]

The context that will be passed to the [pfnDataRateNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_datarate_notification) function when the Miracast data rate changes.

### `pfnDataRateNotify` [in, optional]

A pointer to the driver routine that will be called when the bit rate of the Miracast network link has changed. See Remarks for more info.

The driver can supply a **NULL** value to unregister for notifications.

## Return value

If the operating system successfully registers or unregisters the driver for notifications, it returns **STATUS_SUCCESS**.

Otherwise, these error codes can be returned:

| **Return code** | **Description** |
|:--|:--|
| **STATUS_INVALID_PARAMETER** | One or more parameters are invalid. |
| **STATUS_NOT_SUPPORTED** | The operating system cannot support quality of service (QoS) notifications, or the call to the function is made outside of the calling thread in which the operating system called [StartMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_start_miracast_session) or [StopMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_stop_miracast_session) functions. |

## Remarks

The user-mode driver can optionally call this function to register for automatic calls to data rate notification callback functions once a second.

To unregister from notifications, the driver should supply a value of **NULL** for the *pfnDataRateNotify* parameter and for the **CurrentBitRate** member of the [MIRACAST_WFD_CONNECTION_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_wfd_connection_stats) structure
pointed to by the *pWfdConnectionStats* parameter when it calls the [StartMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_start_miracast_session) function. When the operating system receives **NULL** for both *pfnDataRateNotify* and **CurrentBitRate**, it will no longer provide notifications.

Also, if the operating system can no longer provide QoS data, it sets the *pDataRateStats* parameter to **NULL** when the [pfnDataRateNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_datarate_notification) function is called.

The function fails if the driver attempts to register while it is already registered, or if it attempts to unregister if it has already unregistered. The function fails if the call is made outside of the calling thread in which the operating system called [StartMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_start_miracast_session) or [StopMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_stop_miracast_session) functions.

## See also

[CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context)

[MIRACAST_WFD_CONNECTION_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_wfd_connection_stats)

[StartMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_start_miracast_session)

[pfnDataRateNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_datarate_notification)