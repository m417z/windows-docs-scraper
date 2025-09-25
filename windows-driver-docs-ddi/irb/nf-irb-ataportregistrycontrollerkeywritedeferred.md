# AtaPortRegistryControllerKeyWriteDeferred function

## Description

The **AtaPortRegistryControllerKeyWriteDeferred** routine writes the data asynchronously to the indicated value name under the registry key `HKLM\CurrentControlSet\Services\\ControllerN`, where *N* is the number of the controller.

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
| IDE_REG_SZ | A null-terminated, Unicode string. |

### `Buffer` [in]

A pointer to the source buffer that contains the data to write to the registry value.

### `BufferLength`

A pointer to the number of bytes of data to copy. If the operation fails, the location pointed to by *Length* will update to the length of data that was successfully copied to the registry.

## Return value

**AtaPortRegistryControllerKeyWriteDeferred** returns **TRUE** if the operation succeeds. Otherwise, it returns **FALSE**. The routine also returns **FALSE** if the miniport driver does not call it from the correct routine.

## Remarks

If the value name is not present, the **AtaPortRegistryControllerKeyWriteDeferred** routine creates an entry for the value name and stores the input data under the newly created value name.

The miniport driver can call the **AtaPortRegistryControllerKeyWriteDeferred** routine from any of the routines that are defined in the channel interface.

The buffer pointed to by *Buffer* must be allocated by using [AtaPortRegistryAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportregistryallocatebuffer). The miniport driver must not reuse this buffer after it calls **AtaPortRegistryControllerKeyWriteDeferred** because the port driver delays writing the key data. If the miniport driver reuses the buffer, it might overwrite the data in the buffer before the port driver has an opportunity to store it in the registry key. The port driver flushes the buffer when the miniport driver calls [AtaPortRegistryFreeBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportregistryfreebuffer) to free the buffer.

## See also

[AtaPortRegistryAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportregistryallocatebuffer)

[AtaPortRegistryFreeBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportregistryfreebuffer)