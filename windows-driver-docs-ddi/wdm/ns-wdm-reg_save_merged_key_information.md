## Description

The **REG_SAVE_MERGED_KEY_INFORMATION** structure contains the information about the two registry subtrees for which a merged view is to be saved to a file.

## Members

### `Object`

Set to NULL.

### `FileHandle`

Supplies a file handle with write access to the target file.

### `HighKeyObject`

Supplies a pointer to the registry key object that represents the root of the higher precedence tree. When a key is present in both the trees headed by the two keys, the key underneath this tree prevails. The specified node is included in the data written out.

### `LowKeyObject`

Supplies a pointer to the registry key object that represents the root of the "second choice" tree. Keys from this tree are saved when there is no equivalent key in the tree headed by **HighKeyObject**.

### `CallContext`

Optional driver-defined context information that the driver's [*RegistryCallback*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can supply. This member is defined for Windows Vista and later versions of the Windows operating system.

### `ObjectContext`

A pointer to driver-defined context information that the driver has associated with a registry object by calling [**CmSetCallbackObjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext). This member is defined for Windows Vista and later versions of the Windows operating system.

### `Reserved`

This member is reserved for future use. This member is defined for Windows Vista and later versions of the Windows operating system.

## Remarks

For more information about registry filtering operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).
These are mostly useful for watching for unexpected updates to critical hives and consumers should avoid attempting to modify the merge operations.

## See also

[**CmSetCallbackObjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext)

[*RegistryCallback*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)