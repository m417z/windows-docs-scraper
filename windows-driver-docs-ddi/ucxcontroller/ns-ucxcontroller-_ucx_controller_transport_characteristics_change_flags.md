# _UCX_CONTROLLER_TRANSPORT_CHARACTERISTICS_CHANGE_FLAGS structure

## Description

Defines flags for the transport characteristics changes. This structure is used in the [EVT_UCX_CONTROLLER_SET_TRANSPORT_CHARACTERISTICS_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nc-ucxcontroller-evt_ucx_controller_set_transport_characteristics_change_notification) callback function.

## Members

### `AsUlong32`

Reserved.

### `Flags`

### `Flags.CurrentRoundtripLatencyChanged`

### `Flags.CurrentTotalBandwidthChanged`

### `CurrentRoundtripLatencyChanged`

Contains the current round-trip delay in milliseconds from the time a non-isochronous transfer is received by the USB driver stack to the time that the transfer is completed.

For MA-USB, the underlying network could be WiFi, WiGig, Ethernet etc. The delay can vary depending on the underlying network conditions. A client driver should query the latency periodically or whenever it is notified of a change.

### `CurrentTotalBandwidthChanged`

Contains the total bandwidth of the host controller’s shared transport.

For MA-USB, the underlying network transport could be WiFi, WiGig, Ethernet etc. The total available bandwidth can vary depending on several factors such as the negotiation WiFi channel. A client driver should query the total bandwidth periodically or whenever it is notified of a change.

## See also

[EVT_UCX_CONTROLLER_SET_TRANSPORT_CHARACTERISTICS_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nc-ucxcontroller-evt_ucx_controller_set_transport_characteristics_change_notification)