## Description

**STOR_SET_EVENT_LOGGING** is the structure pointed to by the **Parameters** parameter when a miniport's [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine is called with a **ControlType** of **ScsiAdapterSetEventLogging**.

## Members

### `Channel`

A [**STORPORT_ETW_EVENT_CHANNEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_etw_event_channel) value that identifies the channel.

### `Enabled`

BOOLEAN value that indicates whether the channel identified by **Channel** is enabled. **TRUE** means the channel is enabled for an adapter, and **FALSE** means the channel is disabled.

## See also

[**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)

[**STORPORT_ETW_EVENT_CHANNEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-storport_etw_event_channel)