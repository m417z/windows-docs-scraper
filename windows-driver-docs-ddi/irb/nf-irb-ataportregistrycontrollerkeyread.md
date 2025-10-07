# AtaPortRegistryControllerKeyRead function

## Description

The **AtaPortRegistryControllerKeyRead** routine reads the data that is associated with the indicated value name under the registry key `HKLM\CurrentControlSet\Services\<service name>\ControllerN`, where *N* is the number of the controller.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `ControllerNumber` [in]

Contains the controller number.

### `ValueName` [in]

Contains the name of the registry value to read.

### `ValueType` [in]

Indicates the type of the data that is contained in the registry value. This parameter should be assigned one of values indicated in the following table.

| Value type | Meaning |
| --- | --- |
| IDE_REG_DWORD | A 4-byte numeric value. |
| IDE_REG_BINARY | Binary data. |
| IDE_REG_SZ | A null-terminated, Unicode string. |

### `Buffer` [out, optional]

A pointer to the buffer where the results are to be copied.

### `BufferLength`

A pointer to the number of bytes of data to copy. If the operation fails because of an insufficient buffer, the location that is pointed to by *Length* will update to the actual length of the data in the registry.

## Return value

**AtaPortRegistryControllerKeyRead** returns **TRUE** if the operation succeeds. Otherwise, it returns **FALSE**. The **AtaPortRegistryControllerKeyRead** routine also returns **FALSE** if the miniport driver does not call it from the correct routine.

## Remarks

The buffer at *Buffer* must be allocated by using [AtaPortRegistryAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportregistryallocatebuffer).

The miniport driver must call **AtaPortRegistryControllerKeyRead** either in its [AtaChannelInitRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_channel_init) routine or in its [IdeHwControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_control) routine. It cannot call **AtaPortRegistryControllerKeyRead** from any other routine. Additionally, the miniport driver can only call **AtaPortRegistryControllerKeyRead** from its **IdeHwControl** routine if its **IdeHwControl** routine was called and had a value of either **StartChannel** or **StopChannel** in its *ControlAction* parameter.

## See also

[AtaChannelInitRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_channel_init)

[AtaPortRegistryAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportregistryallocatebuffer)

[IdeHwControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_control)