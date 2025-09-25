# AtaPortReleaseRequestSenseIrb function

## Description

The **AtaPortReleaseRequestSenseIrb** routine frees the request sense IRB that is allocated by using [AtaPortBuildRequestSenseIrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportbuildrequestsenseirb).

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `Irb` [in]

A pointer to a structure of type [IDE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_request_block) that defines the request sense IRB.

## Remarks

The **AtaPortReleaseRequestSenseIrb** routine releases the IRB to the port driver and copies the sense data to the buffer that is pointed to by the **SenseInfoBuffer** member of the original (failed) request's IRB. The miniport driver can then complete the original request by using [AtaPortCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportcompleterequest). The miniport driver must not touch the request sense IRB after it has been released to the port driver.

The miniport driver must call **AtaPortReleaseRequestSenseIrb** for every allocated IRB that is allocated by using [AtaPortBuildRequestSenseIrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportbuildrequestsenseirb).

## See also

[AtaPortBuildRequestSenseIrb](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportbuildrequestsenseirb)

[AtaPortCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportcompleterequest)