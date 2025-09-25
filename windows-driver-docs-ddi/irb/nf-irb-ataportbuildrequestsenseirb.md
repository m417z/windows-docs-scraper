# AtaPortBuildRequestSenseIrb function

## Description

The **AtaPortBuildRequestSenseIrb** routine builds and returns an IRB for operation code SCSIOP_REQUEST_SENSE.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `Irb` [in]

A pointer to a structure of type [IDE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_request_block) that defines the failed IDE request block (IRB) for which the request sense will be issued.

## Return value

If the operation succeeds, the **AtaPortBuildRequestSenseIrb** routine returns a pointer to the request sense IRB that it allocated. If the operation fails, **AtaPortBuildRequestSenseIrb** returns **NULL**.

## Remarks

If the device does not support auto request sense, the miniport driver must build an IRB to gather sense data by using **AtaPortBuildRequestSenseIrb** and then sending it to the device. The miniport driver must not complete the original IRB until the corresponding request sense IRB has completed. Be aware that no request sense data is required for ATA devices.

For an explanation of the SCSIOP_REQUEST_SENSE command, see the *SCSI-3* specification.

The miniport driver can have only one outstanding request sense IRB per logical unit.

## See also

[AtaPortReleaseRequestSenseIrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportreleaserequestsenseirb)