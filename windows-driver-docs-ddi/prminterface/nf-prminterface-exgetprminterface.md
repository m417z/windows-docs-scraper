## Description

This routine fills a caller-provided structure with pointers to system-supplied routines that comprise the Platform Runtime Mechanism (PRM) interface.

## Parameters

### `Version` [in]

A ULONG value that specifies the interface version. Set to 1 for Windows 11, version 24H2.

### `InterfaceOut` [out]

A pointer to a caller-supplied [PRM_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/prminterface/ns-prminterface-prm_interface) structure which, on output, contains pointers to functions that support PRM operations.

## Return value

This method returns NTSTATUS which contains STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

## See also

* [Windows Kernel-Mode PRM Library](https://learn.microsoft.com/windows-hardware/drivers/kernel/windows-kernel-mode-prm-library)
* [Platform Runtime Mechanism specification on uefi.org](https://uefi.org/sites/default/files/resources/Platform%20Runtime%20Mechanism%20-%20with%20legal%20notice.pdf)
* [PRM sample](https://github.com/microsoft/Windows-driver-samples/tree/develop/prm/PrmFunc)