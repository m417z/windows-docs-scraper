# ScsiPortConvertUlongToPhysicalAddress function

## Description

The **ScsiPortConvertUlongToPhysicalAddress** routine extends a given ULONG address into a value of type SCSI_PHYSICAL_ADDRESS.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `UlongAddress` [in]

Specifies a value of type ULONG.

## Return value

**ScsiPortConvertUlongToPhysicalAddress** returns the converted SCSI_PHYSICAL_ADDRESS.

## See also

[ACCESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_access_range)

[ScsiPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetdevicebase)

[ScsiPortGetVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetvirtualaddress)