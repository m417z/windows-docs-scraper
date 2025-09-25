# AtaPortGetBusData function

## Description

The **AtaPortGetBusData** routine retrieves data from the location that is specified by *ConfigDataOffset* within the device's PCI configuration space.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ControllerExtension` [in]

A pointer to the HBA controller extension.

### `Buffer` [in]

A pointer to the buffer where the retrieved data is returned.

### `ConfigDataOffset` [in]

Specifies an offset into the device's PCI bus configuration space where the return value is found.

### `BufferLength` [in]

Specifies the length, in bytes, of the buffer.

## Return value

**AtaPortGetBusData** returns the amount of the retrieved data in bytes.

## Remarks

**AtaPortGetBusData** retrieves data from the specified offset in the device's PCI bus configuration space and returns it in the buffer that is provided.

## See also

[AtaPortSetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportsetbusdata)