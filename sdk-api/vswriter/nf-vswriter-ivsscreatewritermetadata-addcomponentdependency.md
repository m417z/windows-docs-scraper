# IVssCreateWriterMetadata::AddComponentDependency

## Description

The
**AddComponentDependency** method allows a writer to indicate that a component it manages has an explicit writer-component dependency; that is, another component in another writer must be backed up and restored with it.

## Parameters

### `wszForLogicalPath` [in]

A null-terminated wide character string containing the logical path of the component (managed by the current writer) that requires a dependency.

### `wszForComponentName` [in]

A null-terminated wide character string containing the component (managed by the current writer) that requires a dependency.

### `onWriterId` [in]

The class ID or
[VSS_ID](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-data-types) (GUID) of the writer managing the component on which the current component depends.

### `wszOnLogicalPath` [in]

The logical path of the component (managed by the writer identified by *onWriterId*) on which the current component depends.

### `wszOnComponentName` [in]

The name of the component (managed by the writer identified by *onWriterId*) on which the current component depends.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND** | The component specified by *wszForLogicalPath* and *wszForComponentName* does not exist. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

Dependencies upon components managed by the current writer are not permitted.

A dependency requires that both the target of the dependency and the component that depends on the target be restored and backed up together. It does not indicate a priority between the components, although a requester may choose to implement that.

Because the combination of logical name and component name must be unique across all instances of a writer class, the fact that several writers may have the same class ID is not a problem.

This method can be used to declare remote dependencies. A writer can declare a remote dependency by prepending "\\*RemoteComputerName*\", where *RemoteComputerName* is the name of the computer where the remote component resides, to the logical path in the *wszOnLogicalPath* parameter. The value of *RemoteComputerName* can be an IP address or a computer name returned by the [GetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getcomputernameexa) function.

If the remote component resides on a cluster, the writer must report the virtual name for the cluster, and it is the requester's responsibility to map the virtual name to the physical name of a cluster node before a volume shadow copy can be created.

To determine whether a dependency is local or remote, the requester must examine the component name returned in the *pbstrComponentName* parameter. If the component name begins with "\\", the requester must assume that it specifies a remote dependency and that the first component following "\\" is the *RemoteComputerName* that was specified by the writer. If the component name does not begin with "\\", the requester should assume that it specifies a local dependency.

**Windows Server 2003:** This method cannot be used to declare remote dependencies until Windows Server 2003 with Service Pack 1 (SP1).