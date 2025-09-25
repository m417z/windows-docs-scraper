# ScsiPortWritePortBufferUshort macro

## Description

The **ScsiPortWritePortBufferUshort** routine transfers a given number of USHORT values from a buffer to the HBA.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Port` [in]

Pointer to the I/O port. The given *Port* must be in a mapped I/O-space range returned by **ScsiPortGetDeviceBase**.

### `Buffer` [in]

Pointer to the buffer.

### `Count` [in]

Specifies the number of USHORT values to be written to the HBA.

## See also

[ScsiPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetdevicebase)