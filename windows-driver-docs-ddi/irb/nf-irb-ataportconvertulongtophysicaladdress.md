# AtaPortConvertUlongToPhysicalAddress function

## Description

The **AtaPortConvertUlongToPhysicalAddress** routine converts a given ULONG address into a value of type IDE_PHYSICAL_ADDRESS.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `UlongAddress` [in]

Specifies a value of type ULONG.

## Return value

**AtaPortConvertUlongToPhysicalAddress** returns the converted IDE_PHYSICAL_ADDRESS value.

## See also

[AtaPortConvertPhysicalAddressToUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportconvertphysicaladdresstoulong)