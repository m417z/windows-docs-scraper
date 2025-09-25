# AtaPortWriteRegisterUchar function

## Description

The **AtaPortWriteRegisterUchar** routine transfers an unsigned byte to the HBA.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Register` [in]

A pointer to the destination register. The address value that is assigned to this parameter must be within the range of mapped I/O space addresses that are obtained by a call to [AtaPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportgetdevicebase).

### `Value` [in]

Specifies the value to write to the register for the HBA.

## See also

[AtaPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportgetdevicebase)

[AtaPortWriteRegisterUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportwriteregisterulong)

[AtaPortWriteRegisterUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportwriteregisterushort)