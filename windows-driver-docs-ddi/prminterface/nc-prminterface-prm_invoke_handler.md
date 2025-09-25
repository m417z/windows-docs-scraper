## Description

This routine invokes a specific PRM handler.

## Parameters

### `HandlerGuid` [in]

Pointer to a 128-bit unique identifier that specifies the PRM handler to invoke.

### `ParameterBuffer` [in]

Pointer to a caller-allocated PRM handler parameter buffer.

### `Reserved` [in]

Reserved. Set to zero.

### `EfiStatus` [out]

Pointer to a ULONG64 which, on output, contains the EFI status from the PRM handler invocation.

## Return value

This method returns NTSTATUS which contains STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

PRM_INVOKE_HANDLER is not a system routine that can be called directly by name. This routine is callable only by pointer from the address returned in a [PRM_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/prminterface/ns-prminterface-prm_interface) structure. Drivers obtain the address of this routine by calling [**ExGetPrmInterface**](https://learn.microsoft.com/windows-hardware/drivers/ddi/prminterface/nf-prminterface-exgetprminterface).

## See also

[Windows Kernel-Mode PRM Library](https://learn.microsoft.com/windows-hardware/drivers/kernel/windows-kernel-mode-prm-library)