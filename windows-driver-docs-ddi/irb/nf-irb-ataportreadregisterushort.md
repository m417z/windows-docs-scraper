# AtaPortReadRegisterUshort function

## Description

The **AtaPortReadRegisterUshort** routine reads a USHORT value from the HBA.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `Register` [in]

A pointer to the register to be read. The address value that is assigned to this parameter must be within the range of mapped I/O space addresses that are obtained by a call to [AtaPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportgetdevicebase).

## Return value

**AtaPortReadRegisterUshort** returns a USHORT value from the HBA's register.

## See also

[AtaPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportgetdevicebase)

[AtaPortReadRegisterUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportreadregisteruchar)

[AtaPortReadRegisterUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportreadregisterulong)