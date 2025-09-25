## Description

The **WifiAdapterReportWakeReason** function reports to the framework the reason that a Wi-Fi device has generated a wake-up event.

## Parameters

### `Adapter`

[_In_] A handle to a NETADAPTER object that the client driver obtained from a previous call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `Reason`

[_In_] A [**WIFI_WAKE_REASON_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ne-wificx-wifi_wake_reason_type) value that describes the reason for the wake-up event.

## Remarks

## See also

[**WIFI_WAKE_REASON_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ne-wificx-wifi_wake_reason_type)