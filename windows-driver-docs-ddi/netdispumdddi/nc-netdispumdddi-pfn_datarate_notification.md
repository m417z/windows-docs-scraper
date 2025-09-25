# PFN_DATARATE_NOTIFICATION callback function

## Description

Called by the operating system to notify the Miracast user-mode driver that the bit rate of the Miracast network link has changed. This function is registered with the operating system when the [RegisterForDataRateNotifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_register_datarate_notifications) function is called.

## Parameters

### `context` [in]

A pointer to a context block associated with a display adapter.

The context value is the value the driver passed in its call to the [RegisterForDataRateNotifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_register_datarate_notifications) function when it registered the *pfnDataRateNotify* function.

### `pDataRateStats` [in, optional]

An optional pointer to a [MIRACAST_DATARATE_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_datarate_stats) structure that contains info on the audio/video encoder bit rate and failed or retried Wi-Fi frames.

Can be **NULL** if the network has an error. For more info, see Remarks.

## Remarks

If data on the quality of service (QoS) of the network connection becomes unavailable, the *pDataRateStats* parameter will be set to **NULL**, and this function will not be called again.

## See also

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[MIRACAST_DATARATE_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_datarate_stats)

[RegisterForDataRateNotifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_register_datarate_notifications)