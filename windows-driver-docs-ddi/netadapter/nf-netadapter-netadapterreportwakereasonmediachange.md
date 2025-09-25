# NetAdapterReportWakeReasonMediaChange function

## Description

The **NetAdapterReportWakeReasonMediaChange** function reports to the framework that a net adapter generated a wake-up event because of a media change.

## Parameters

### `Adapter` [_In_]

A handle to the NETADAPTER object.

### `Reason` [_In_]

A [**NET_IF_MEDIA_CONNECT_STATE**](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_media_connect_state) value that specifies the network interface connection state that triggered the wake-up event.

## Remarks

## See also

[Configuring power management](https://learn.microsoft.com/windows-hardware/drivers/netcx/configuring-power-management)

[**NET_IF_MEDIA_CONNECT_STATE**](https://learn.microsoft.com/windows/win32/api/ifdef/ne-ifdef-net_if_media_connect_state)