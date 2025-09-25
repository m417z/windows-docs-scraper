# AtaPortRegistryControllerKeyWrite function

## Description

The **AtaPortRegistryControllerKeyWrite** routine writes the data to the indicated value name under the registry key `HKLM\CurrentControlSet\Services\\ControllerN`, where *N* is the number of the controller.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `ControllerNumber` [in]

Contains the controller number.

### `ValueName` [in]

Contains the name of the registry value to write to.

### `ValueType` [in]

Indicates the type of data that is contained in the registry value. This member should be assigned one of the values indicated in the following table.

| Value | Meaning |
| --- | --- |
| IDE_REG_DWORD | A 4-byte numeric value. |
| IDE_REG_BINARY | Binary data. |
| IDE_REG_SZ | A null-terminated, Unicode string. |

### `Buffer` [in]

A pointer to the source buffer that contains the data to write to the registry value.

### `BufferLength`

A pointer to the number of bytes of data to copy. If the operation fails, the location that is pointed to by *Length* will update the length of data that was successfully copied to the registry.

## Return value

**AtaPortRegistryControllerKeyWrite** returns **TRUE** if the operation succeeds. Otherwise, it returns **FALSE**. The routine also returns **FALSE** if the miniport driver does not call it from the correct routine.

## Remarks

The buffer should be allocated by using [AtaPortRegistryAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportregistryallocatebuffer).

The miniport driver must call **AtaPortRegistryControllerKeyWrite** during the [AtaChannelInitRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_channel_init) routine or the [IdeHwControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_control) routine.; The miniport driver cannot call **AtaPortRegistryControllerKeyWrite** from any other routine or it will return **FALSE**. Additionally, the miniport driver can only call **AtaPortRegistryControllerKeyWrite** from its **IdeHwControl** routine if its **IdeHwControl** routine was called and had a value of either **StartChannel** or **StopChannel** in its *ControlAction* parameter.

## See also

[AtaChannelInitRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_channel_init)

[AtaPortRegistryAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportregistryallocatebuffer)

[IdeHwControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_control)