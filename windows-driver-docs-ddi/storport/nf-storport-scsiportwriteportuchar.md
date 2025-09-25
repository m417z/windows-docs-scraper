# ScsiPortWritePortUchar macro

## Description

The **ScsiPortWritePortUchar** routine transfers an unsigned byte to the HBA.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Port` [in]

Pointer to the I/O port. The given *Port* must be in a mapped I/O-space range returned by **ScsiPortGetDeviceBase**.

### `Value` [in]

Specifies the value to be written to the HBA's I/O port.

## See also

[ScsiPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetdevicebase)