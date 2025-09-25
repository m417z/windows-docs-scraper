# AtaPortReadRegisterBufferUlong function

## Description

The **AtaPortReadRegisterBufferUlong** routine transfers a specified number of ULONG values from the HBA to a buffer.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Register` [in]

Contains the register address where the transfer should begin. This address value must be within the range of mapped I/O space addresses that are obtained by a call to [AtaPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportgetdevicebase).

### `Buffer` [in]

A pointer to the destination buffer.

### `Count` [in]

Specifies the number of ULONG values to read from the HBA.

## See also

[AtaPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportgetdevicebase)

[AtaPortReadRegisterBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportreadregisterbufferuchar)

[AtaPortReadRegisterBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportreadregisterbufferushort)