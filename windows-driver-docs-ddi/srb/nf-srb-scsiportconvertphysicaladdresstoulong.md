# ScsiPortConvertPhysicalAddressToUlong function

## Description

The **ScsiPortConvertPhysicalAddressToUlong** routine truncates a SCSI_PHYSICAL_ADDRESS to a ULONG.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Address` [in]

Specifies a value of type SCSI_PHYSICAL_ADDRESS.

## Return value

**ScsiPortConvertPhysicalAddressToUlong** returns the low-order part of the given SCSI_PHYSICAL_ADDRESS value. A miniport driver cannot call this routine to truncate a 64-bit physical address. Such addresses should be used as quadword values, which contain all 64 bits.

## See also

[ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_access_range)

[ScsiPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetdevicebase)

[ScsiPortGetPhysicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetphysicaladdress)