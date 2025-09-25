## Description

The PRM_INTERFACE structure provides a set of pointers to functions that control the operation of a PRM interface.

## Members

### `Version`

Specifies the version of this structure.

### `UnlockModule`

A pointer to a system-defined routine to unlock a PRM module. For more information, see [PRM_UNLOCK_MODULE](https://learn.microsoft.com/windows-hardware/drivers/ddi/prminterface/nc-prminterface-prm_unlock_module).

### `LockModule`

A pointer to a system-defined routine to lock a PRM module. For more information, see [PRM_LOCK_MODULE](https://learn.microsoft.com/windows-hardware/drivers/ddi/prminterface/nc-prminterface-prm_lock_module).

### `InvokeHandler`

A pointer to a system-defined routine to invoke a specific PRM handler. For more information, see [PRM_INVOKE_HANDLER](https://learn.microsoft.com/windows-hardware/drivers/ddi/prminterface/nc-prminterface-prm_invoke_handler).

### `QueryHandler`

A pointer to a system-defined routine to query for the presence of a specific PRM handler. For more information, see [PRM_QUERY_HANDLER](https://learn.microsoft.com/windows-hardware/drivers/ddi/prminterface/nc-prminterface-prm_query_handler).

## Remarks

All members of this structure, with the exception of Version, are pointers to functions that drivers use to perform PRM operations. Drivers obtain these pointers by calling the [**ExGetPrmInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prminterface/nf-prminterface-exgetprminterface) routine.

## See also

[Windows Kernel-Mode PRM Library](https://learn.microsoft.com/windows-hardware/drivers/kernel/windows-kernel-mode-prm-library)