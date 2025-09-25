# AtaPortStallExecution function

## Description

The **AtaPortStallExecution** stalls in the miniport driver.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Delay` [in]

Specifies the delay interval, in microseconds.

## Remarks

Miniport drivers should rarely call the **AtaPortStallExecution** routine. The total stall time in any miniport driver routine must always be less than one millisecond. Because this call ties up a processor, the processor does no useful work while it stalls in the driver.

Typically, a miniport driver should call **AtaPortStallExecution** only if the driver must wait for some sort of state change on the HBA that is unable to cause an interrupt, or if the driver must delay for a very short interval between accesses to the HBA.

Miniport drivers should use the [AtaPortRequestTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportrequesttimer) routine for delays longer than 1 millisecond.

## See also

[AtaPortRequestTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportrequesttimer)