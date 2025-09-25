# ScsiPortReadRegisterBufferUshort macro

## Description

The **ScsiPortReadRegisterBufferUshort** routine transfers a specified number of USHORT values from the HBA to a buffer.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Register` [in]

Pointer to the register. The given *Register* must be in a mapped memory-space range returned by **ScsiPortGetDeviceBase**.

### `Buffer` [in]

Pointer to the buffer.

### `Count` [in]

Specifies the number of USHORT values to be read from the HBA.

## Remarks

**ScsiPortReadRegisterBufferUshort** ensures that the data has been transferred correctly.

## See also

[ScsiPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetdevicebase)