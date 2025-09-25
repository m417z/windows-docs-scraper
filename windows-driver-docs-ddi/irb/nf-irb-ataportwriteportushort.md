# AtaPortWritePortUshort function

## Description

The **AtaPortWritePortUshort** routine transfers a USHORT value to the HBA.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Port` [in]

A pointer to the I/O port. The address value that is assigned to this parameter must be within the range of mapped I/O space addresses that are obtained by a call to [AtaPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportgetdevicebase).

### `Value` [in]

Specifies the value to write to the HBA's I/O port.

## See also

[AtaPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportgetdevicebase)

[AtaPortWritePortUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportwriteportuchar)

[AtaPortWritePortUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportwriteportulong)