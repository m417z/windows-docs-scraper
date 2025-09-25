# ScsiPortWriteRegisterUshort macro

## Description

The **ScsiPortWriteRegisterUshort** routine transfers a USHORT value to the HBA.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Register` [in]

Pointer to the register. The given *Register* must be in a mapped memory-space range returned by **ScsiPortGetDeviceBase**.

### `Value` [in]

Specifies the value to be written to the HBA's register.

## See also

[ScsiPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetdevicebase)