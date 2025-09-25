# AtaPortRegistryChannelSubkeyRead function

## Description

The **AtaPortRegistryChannelSubKeyRead** routine reads the data that is associated with the indicated value name under the registry key `HKLM\CurrentControlSet\Services\\ControllerN\ChannelM`, where *N* is the number of the controller and *M* is the number of the channel.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `ControllerNumber` [in]

Contains the controller number.

### `ValueName` [in]

Contains the name of the registry value from which to read.

### `ValueType` [in]

Indicates the type of data that is contained in the registry value. This member should be assigned one of values indicated in the following table.

| Value | Meaning |
| --- | --- |
| IDE_REG_DWORD | A 4-byte numeric value. |
| IDE_REG_BINARY | Binary data. |
| IDE_REG_SZ | A null-terminated. Unicode string. |

### `Buffer` [out, optional]

A pointer to the destination buffer where the data that is read from the registry will be written.

### `BufferLength`

A pointer to the number of bytes of data to copy. If the operation fails, the location that is pointed to by *Length* will update to the length of data that was successfully copied from the registry.

## Return value

**AtaPortRegistryChannelSubKeyRead** returns **TRUE** if the operation succeeds. Otherwise, it returns **FALSE**. The routine also returns **FALSE** if the miniport driver does not call it from the correct routine.

## Remarks

The buffer that is pointed to by *Buffer* must be allocated by using [AtaPortRegistryAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportregistryallocatebuffer).

The miniport driver must call **AtaPortRegistryChannelSubKeyRead** either during the [AtaChannelInitRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_channel_init) routine or the [IdeHwControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_control) routine or it will return **FALSE**. Additionally, the miniport driver can only call **AtaPortRegistryChannelSubKeyRead** from its ***IdeHwControl*** routine if its ***IdeHwControl*** routine was called and had a value of either **StartChannel** or **StopChannel** in its *ControlAction* parameter.

## See also

[AtaChannelInitRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_channel_init)

[AtaPortRegistryAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportregistryallocatebuffer)

[AtaPortRegistryChannelSubKeyWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportregistrychannelsubkeywrite)

[IdeHwControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_control)