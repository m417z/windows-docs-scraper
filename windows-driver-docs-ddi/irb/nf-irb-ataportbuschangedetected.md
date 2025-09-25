# AtaPortBusChangeDetected function

## Description

The **AtaPortBusChangeDetected** routine notifies the port driver of changes in the device configuration on the indicated channel.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension`

A pointer to the channel extension.

## Remarks

The miniport driver uses this routine to report the arrival or removal of any device that is attached to the channel. In response, the port driver will initiate a re-scan to discover and initialize the device.