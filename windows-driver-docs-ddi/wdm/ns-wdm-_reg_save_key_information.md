# _REG_SAVE_KEY_INFORMATION structure

## Description

The **REG_SAVE_KEY_INFORMATION** structure contains the information for a registry key that is about to be saved.

## Members

### `Object`

A pointer to a registry key object for the key whose information is about to be saved.

### `FileHandle`

A handle to the file to which the hive information will be saved.

### `Format`

The format in which the key or hive is saved. This member can have one of the following values.

| Value | Meaning |
| --- | --- |
| REG_STANDARD_FORMAT | Save in standard format. The standard format is the only format supported by Windows 2000. |
| REG_LATEST_FORMAT | Save in the latest format. The latest format is supported starting with Windows XP. After the key is saved in this format, it cannot be loaded on an earlier version of Windows. |
| REG_NO_COMPRESSION | Save with no compression, for faster save operations. The registry key object must represent the root of a hive. |

### `CallContext`

Optional driver-defined context information that the driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can supply. This member is defined starting with Windows Vista.

### `ObjectContext`

A pointer to driver-defined context information, which the driver has associated with a registry object by calling [CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext). This member is defined starting with Windows Vista.

### `Reserved`

This member is reserved for future use. This member is defined starting with Windows Vista.

## Remarks

For more information about registry filtering operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)