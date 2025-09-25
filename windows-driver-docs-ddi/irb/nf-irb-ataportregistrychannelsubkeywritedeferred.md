# AtaPortRegistryChannelSubkeyWriteDeferred function

## Description

The **AtaPortRegistryChannelSubKeyWriteDeferred** routine writes data asynchronously to the indicated value name under the registry key `HKLM\CurrentControlSet\Services\\ControllerN\ChannelM`, where *N* is the number of the controller and *M* is the number of the channel.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `ControllerNumber` [in]

Contains the controller number.

### `ValueName` [in]

Contains the name of the registry value to write to.

### `ValueType` [in]

Indicates the type of data that is contained in the registry value. This member should be assigned one of values indicated in the following table.

| Value | Meaning |
| --- | --- |
| IDE_REG_DWORD | A 4-byte numeric value. |
| IDE_REG_BINARY | Binary data. |
| IDE_REG_SZ | A null-terminated. Unicode string. |

### `Buffer` [in]

Pointer to the source buffer that contains the data to be written to the registry.

### `BufferLength`

A pointer to the number of bytes of data to copy. If the operation fails, the location that is pointed to by *Length* will update to the length of the data that was successfully written to the registry.

## Return value

**AtaPortRegistryChannelSubKeyWriteDeferred** returns **TRUE** if the operation. Otherwise, it returns **FALSE**. The routine also returns **FALSE** if the miniport driver does not call it from the correct routine.

## Remarks

If the value name is not present, **AtaPortRegistryChannelSubKeyWriteDeferred** creates an entry for the value and the data is stored in the newly created value.

The buffer that is pointed to by *Buffer* must be allocated by using [AtaPortRegistryAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportregistryallocatebuffer).

The miniport driver can call **AtaPortRegistryChannelSubKeyWriteDeferred** from any of the key routines that belong to its channel interface.

The miniport driver must not reuse the buffer that is pointed to by *Buffer* after the initial call to **AtaPortRegistryChannelSubKeyWriteDeferred**. Because the call is asynchronous, *Buffer* might still point to data that has not been flushed to the registry. The port driver flushes the data in the buffer to the registry when the miniport driver calls [AtaPortRegistryFreeBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportregistryfreebuffer).

## See also

[AtaPortRegistryAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportregistryallocatebuffer)

[AtaPortRegistryFreeBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportregistryfreebuffer)