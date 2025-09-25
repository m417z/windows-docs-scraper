# _REG_RESTORE_KEY_INFORMATION structure

## Description

The **REG_RESTORE_KEY_INFORMATION** structure contains the information for a registry key that is about to be restored.

## Members

### `Object`

A pointer to a registry key object for the key that is about to be restored.

### `FileHandle`

A handle to the file from which the hive will be restored.

### `Flags`

**REG_FORCE_RESTORE**

0x00000008L

If specified, the restore operation is executed even if open handles exist at or beneath the location in the registry hierarchy to which the *hKey* parameter points.

**REG_WHOLE_HIVE_VOLATILE**

0x00000001L

If specified, a new, volatile (memory-only) set of registry information, or *hive*, is created. If REG_WHOLE_HIVE_VOLATILE is specified, the key identified by the *hKey* parameter must be either the HKEY_USERS or HKEY_LOCAL_MACHINE value.

**REG_REFRESH_HIVE**

0x00000002

If set, the location of the subtree that the *hKey* parameter points to is restored to its state immediately following the last flush. The subtree must not be lazy flushed (by calling **RegRestoreKey** with REG_NO_LAZY_FLUSH specified as the value of this parameter); the caller must have the trusted computing base (TCB) privilege; and the handle to which the *hKey* parameter refers must point to the root of the subtree.

### `CallContext`

Optional driver-defined context information that the driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can supply. This member is defined for Windows Vista and later versions of the Windows operating system.

### `ObjectContext`

A pointer to driver-defined context information, which the driver has associated with a registry object by calling [CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext). This member is defined for Windows Vista and later versions of the Windows operating system.

### `Reserved`

This member is reserved for future use. This member is defined for Windows Vista and later versions of the Windows operating system.

## Remarks

The REG_REFRESH_HIVE flag is opaque and a filter should not attempt to change it.

For more information about registry filtering operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)