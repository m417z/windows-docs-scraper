# AtaPortWriteRegisterBufferUlong function

## Description

The **AtaPortWriteRegisterBufferUlong** routine transfers the indicated number of ULONG values from a buffer to the HBA.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Register` [in]

Contains the destination register address where the transfer should begin. This address value must be within the range of mapped I/O space addresses at are obtained by a call to [AtaPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportgetdevicebase).

### `Buffer` [in]

A pointer to the source buffer.

### `Count` [in]

Specifies the number of ULONG values to write to the HBA.

## See also

[AtaPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportgetdevicebase)

[AtaPortWriteRegisterBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportwriteregisterbufferuchar)

[AtaPortWriteRegisterBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportwriteregisterbufferushort)