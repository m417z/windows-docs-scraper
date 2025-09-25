# ScsiPortReadRegisterUshort function

## Description

The **ScsiPortReadRegisterUshort** routine reads a USHORT value from the HBA.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Register` [in]

Pointer to the register. The given *Register* must be in a mapped memory-space range returned by **ScsiPortGetDeviceBase**.

## Return value

**ScsiPortReadRegisterUshort** returns a USHORT value from the HBA's register.

## Remarks

**ScsiPortReadRegisterUshort** ensures that the data is transferred correctly.

## See also

[ScsiPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetdevicebase)