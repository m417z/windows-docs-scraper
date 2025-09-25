## Description

The **CREATE_REDIRECTION_ECP_CONTEXT** structure contains the extra create parameter (ECP) context that can be sent to query the redirection state of a file for a specific create operation.

## Members

### `Size`

Size of this structure, in bytes.

### `Flags`

The redirection state of the file. Can be a valid combination of the following values.

| Flag | Meaning |
| ---- | ------- |
| CREATE_REDIRECTION_FLAGS_SERVICED_FROM_LAYER | This is a redirected file from a layer that is not registered in the LayerRootLocations registry key. |
| CREATE_REDIRECTION_FLAGS_SERVICED_FROM_SCRATCH | This is a new or modified file, it is not redirected. |
| CREATE_REDIRECTION_FLAGS_SERVICED_FROM_REGISTERED_LAYER | This is a redirected file from a layer that is listed in the LayerRootLocations registry key. |
| CREATE_REDIRECTION_FLAGS_SERVICED_FROM_REMOTE_LAYER | This is a redirected file from a remote file system relative to the container. It may or may not be registered as a layer on that server. For Hyper-V containers, the remote server is the host of the Hyper-V container utility VM. |
| CREATE_REDIRECTION_FLAGS_SERVICED_FROM_USER_MODE | This is a cloud or other file that requires user-mode redirection. |

### `FileId`

The ID of the backing file.

### `VolumeGuid`

The GUID-based identifier of the disk volume where the backing file resides.

## Remarks

The system-defined GUID_ECP_CREATE_REDIRECTION value is used with this ECP context structure when calling ECP-related support routines such as [**FltAllocateExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameter) and [**FsRtlRemoveExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveextracreateparameter).

See [Introduction to extra create parameters](https://learn.microsoft.com/windows-hardware/drivers/ifs/introduction-to-extra-create-parameters) for more information.

The **WCIFS_REDIRECTION_ECP_CONTEXT** structure is defined to be the same as this structure to maintain code compatibility.