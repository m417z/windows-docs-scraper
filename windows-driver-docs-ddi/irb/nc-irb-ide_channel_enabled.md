# IDE_CHANNEL_ENABLED callback function

## Description

The **AtaControllerChannelEnabled** miniport driver routine indicates whether the specified channel is enabled.

> [!NOTE]
> The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ControllerExtension`

[in] A pointer to the controller extension.

### `Channel`

[in] The channel to enable.

## Return value

**AtaControllerChannelEnabled** returns an enumerator value of type [**ATA_CHANNEL_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ne-irb-ata_channel_state), which can have any of the following values:

| Return code | Meaning |
| ----------- | ------- |
| ChannelStateEnabled | Indicates that the specified channel is enabled. |
| ChannelStateDisabled | Indicates that the specified channel is disabled. |
| ChannelStateUnKnown | Indicates that the state of the channel could not be determined.|

## Remarks

The following sequence describes how the miniport driver and the port driver interact to determine which controller channels are enabled:

1. The port driver calls the miniport driver's **AtaAdapterControl** routine with control action **IdeStart**.

2. While the miniport driver processes the **AtaAdapterControl** routine with control action **IdeStart**, it initializes the **NumberOfChannels** member of [**IDE_CONTROLLER_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_controller_configuration) to indicate the number of channels that are enabled.

3. After the **AtaAdapterControl** routine returns, the port driver calls **AtaControllerChannelEnabled** one time for every NumberOfChannels specified in the ControllerConfiguration structure that are returned by **AtaAdapterControl**.

This routine should not have steps that are critical to the operation of the controller. There are situations, such as during a crashdump operation, where this function will not be called at all. Additionally, this function is not called when a channel is restarted, only when PCIIDEx responds to a QueryDeviceRelations IRP.

**AtaControllerChannelEnabled** is an optional routine. If the miniport driver does not implement this routine, the port driver will load a default handler. If the port driver loads a default handler, all channels that are specified by NumberOfChannels in the ControllerConfiguration structure that is returned by [**AtaAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_adapter_control) when handling an IdeStart action are assumed to be enabled. This routine enables PCIIDEx to load the ATA port driver for only the channels enabled. Doing this allows for sparse channel support (for example, channel 0, channel 1, channel 3, channel 4, and channel 6, but not channel 2 and channel 5).

## See also

[**IDE_CONTROLLER_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_controller_configuration)