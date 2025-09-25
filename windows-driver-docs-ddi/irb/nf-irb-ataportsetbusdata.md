# AtaPortSetBusData function

## Description

The **AtaPortSetBusData** routine stores the data at **Buffer** in the indicated device's PCI configuration space at an offset that is specified in **ConfigDataOffset**.

> [!NOTE]
> The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ControllerExtension`

[in] A pointer to the controller extension.

### `Buffer`

[in] A pointer to the buffer that contains the data to write to the device's PCI bus configuration space.

### `ConfigDataOffset`

[in] Specifies an offset into the device's PCI bus configuration data space where the data is updated.

### `BufferLength`

[in] Specifies the length, in bytes, of the buffer that **Buffer** points to.

## Return value

**AtaPortSetBusData** returns the amount of the data that was written in bytes.

## Remarks

**AtaPortSetBusData** completes a bitwise OR, one byte at a time, of the current PCI configuration space data with the new data in **Buffer**. Only those bits not indicated by **DataMask** are left untouched. The byte of data that follows **ConfigDataOffset**, therefore, is updated as follows:

``` C
ConfigDataOffest[i] =
    (ConfigDataOffest[i] & ~DataMask[i]) |
    (DataMask[i] & Buffer[i])
```

## See also

[**AtaPortGetBusData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportgetbusdata)