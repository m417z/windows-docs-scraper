# AtaPortReadPortBufferUlong function

## Description

The **AtaPortReadPortBufferUlong** routine transfers a given number of ULONG values from the HBA to a buffer.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Port` [in]

A pointer to the I/O port. The address value that is assigned to this parameter must be within the range of mapped I/O space addresses that are obtained by a call to [AtaPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportgetdevicebase).

### `Buffer` [in]

A pointer to the destination buffer.

### `Count` [in]

Specifies the number of ULONG values to read from the HBA.

## See also

[AtaPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportgetdevicebase)

[AtaPortReadPortBufferUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportreadportbufferuchar)

[AtaPortReadPortBufferUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportreadportbufferushort)