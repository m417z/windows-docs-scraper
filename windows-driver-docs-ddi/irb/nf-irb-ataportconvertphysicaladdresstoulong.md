# AtaPortConvertPhysicalAddressToUlong function

## Description

The **AtaPortConvertPhysicalAddressToUlong** routine truncates an address of type IDE_PHYSICAL_ADDRESS to a ULONG.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Address` [in]

Specifies a value of type IDE_PHYSICAL_ADDRESS.

## Return value

**AtaPortConvertPhysicalAddressToUlong** returns the lower order part of the given IDE_PHYSICAL_ADDRESS value.

## Remarks

A miniport driver must not use this routine to truncate a 64-bit physical address.

## See also

[AtaPortConvertUlongToPhysicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportconvertulongtophysicaladdress)