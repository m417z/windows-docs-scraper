## Description

This routine locks a PRM module in memory and prevents it from being updated by the OS runtime.

## Parameters

### `HandlerGuid` [in]

Supplies the GUID of the PRM handler whose module needs to be locked.

## Return value

This method returns NTSTATUS which contains STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

PRM_LOCK_MODULE is not a system routine that can be called directly by name. This routine is callable only by pointer from the address returned in a [PRM_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/prminterface/ns-prminterface-prm_interface) structure. Drivers obtain the address of this routine by calling [**ExGetPrmInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prminterface/nf-prminterface-exgetprminterface).

## See also

[Windows Kernel-Mode PRM Library](https://learn.microsoft.com/windows-hardware/drivers/kernel/windows-kernel-mode-prm-library)