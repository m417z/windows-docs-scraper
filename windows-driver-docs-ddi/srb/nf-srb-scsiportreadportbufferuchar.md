# ScsiPortReadPortBufferUchar function

## Description

The **ScsiPortReadPortBufferUchar** routine transfers a given number of unsigned byte values from the HBA to a buffer.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Port` [in]

Pointer to the I/O port. The given *Port* must be in a mapped I/O-space range returned by **ScsiPortGetDeviceBase**.

### `Buffer` [in]

Pointer to the buffer.

### `Count` [in]

Specifies the number of bytes to be read from the HBA.

## Return value

None

## Remarks

**ScsiPortReadPortBufferUchar** ensures that the data is transferred correctly.

## See also

[ScsiPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetdevicebase)