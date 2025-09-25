# AtaPortGetDeviceBase function

## Description

The **AtaPortGetDeviceBase** routine returns a mapped logical base address that is used to communicate with an HBA.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `IoAddress` [in]

Specifies the base address to map.

### `NumberOfBytes` [in]

Specifies the size, in bytes, of the range that the mappings should cover. The value for this parameter can be obtained from the **IdeAccessRange** member of the [IDE_MINIPORT_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_miniport_resources) structure.

## Return value

**AtaPortGetDeviceBase** returns a mapped logical base address if the operation succeeds. Otherwise, it returns **NULL**.

## Remarks

Miniport drivers must use logical addresses that have been mapped into system space by **AtaPortGetDeviceBase** instead of bus-relative addresses to communicate with its HBA. Calls to the **AtaPort...Port/Register***Xxx* routines require mapped logical addresses.

## See also

[AtaPortReadPortUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportreadportuchar)

[AtaPortReadPortUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportreadportulong)

[AtaPortReadPortUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportreadportushort)