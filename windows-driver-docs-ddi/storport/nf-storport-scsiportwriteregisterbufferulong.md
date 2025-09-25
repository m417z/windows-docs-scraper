# ScsiPortWriteRegisterBufferUlong macro

## Description

The **ScsiPortWriteRegisterBufferUlong** routine transfers a given number of ULONG values from a buffer to the HBA.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Register` [in]

Pointer to the register. The given *Register* must be in a mapped memory-space range returned by **ScsiPortGetDeviceBase**.

### `Buffer` [in]

Pointer to a buffer containing the data to be written.

### `Count` [in]

Specifies the number of ULONG values to be transferred to the HBA.

## See also

[ScsiPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetdevicebase)