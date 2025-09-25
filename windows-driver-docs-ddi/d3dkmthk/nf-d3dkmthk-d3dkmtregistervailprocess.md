## Description

The **D3DKMTRegisterVailProcess** function registers the current process as one that can share GPU allocations between a guest virtual machine (VM) and the host.

## Parameters

### `unnamedParam1`

[in] **VirtualMachineGuid**, which is a pointer to the GUID associated with a running VM. The VM must have at least one virtual GPU assigned.

## Return value

**D3DKMTRegisterVailProcess** returns an NTSTATUS code such as one of the following values:

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | Process registration was successful. |
| STATUS_ACCESS_DENIED | The process does not have enough privileges to call this API. Note that other status codes could be returned in this case. |
| STATUS_INVALID_PARAMETER | The value passed in **VirtualMachineGuid** is not valid. |
| STATUS_GRAPHICS_VAIL_STATE_CHANGED | The VM does not have a virtual GPU assigned. |
| STATUS_INVALID_DISPOSITION | The process does not have graphics context created. |
| STATUS_NOT_FOUND | A VM with the given GUID was not found. |

Other status codes could be returned as well.

## Remarks

The calling process must have the same privileges as the Remote Desktop (RDP) client process that was created for the VM instance specified by the **VirtualMachineGuid** parameter.