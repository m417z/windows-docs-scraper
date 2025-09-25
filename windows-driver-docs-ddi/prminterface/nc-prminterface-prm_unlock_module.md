## Description

This routine undoes the operation from [**PRM_LOCK_MODULE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prminterface/nc-prminterface-prm_lock_module) and allows the module to be updated. PRM_UNLOCK_MODULE should always be preceded by exactly one PRM_LOCK_MODULE call.

## Parameters

### `HandlerGuid` [in]

Supplies the GUID of the PRM handler whose module needs to be unlocked.

## Return value

This method returns NTSTATUS which contains STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

PRM_UNLOCK_MODULE is not a system routine that can be called directly by name. This routine is callable only by pointer from the address returned in a [PRM_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/prminterface/ns-prminterface-prm_interface) structure. Drivers obtain the address of this routine by calling [**ExGetPrmInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prminterface/nf-prminterface-exgetprminterface).

## See also

[Windows Kernel-Mode PRM Library](https://learn.microsoft.com/windows-hardware/drivers/kernel/windows-kernel-mode-prm-library)