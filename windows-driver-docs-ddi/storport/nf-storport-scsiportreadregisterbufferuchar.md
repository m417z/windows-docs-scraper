# ScsiPortReadRegisterBufferUchar macro

## Description

The **ScsiPortReadRegisterBufferUchar** routine transfers a specified number of unsigned bytes from the HBA to a buffer.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Register` [in]

Pointer to the register. The given *Register* must be in a mapped memory-space range returned by **ScsiPortGetDeviceBase**.

### `Buffer` [in]

Pointer to the buffer.

### `Count` [in]

Specifies the number of bytes to be read from the HBA.

## Remarks

**ScsiPortReadRegisterBufferUchar** ensures that the data is transferred correctly.

## See also

[ScsiPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetdevicebase)