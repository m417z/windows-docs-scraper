# IAccessControl::IsAccessAllowed

## Description

Determines whether the specified trustee has access rights to the object or property.

## Parameters

### `pTrustee` [in]

A pointer to a [TRUSTEE](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-trustee_a) structure.

### `lpProperty` [in]

The name of the property. If you are using the COM implementation of [IAccessControl](https://learn.microsoft.com/windows/desktop/api/iaccess/nn-iaccess-iaccesscontrol), this parameter must be **NULL**.

### `AccessRights` [in]

The access rights on the object. If you are using the COM implementation of [IAccessControl](https://learn.microsoft.com/windows/desktop/api/iaccess/nn-iaccess-iaccesscontrol), this value must be either 0 or 1 (COM_RIGHTS_EXECUTE).

### `pfAccessAllowed` [out]

Indicates whether access is allowed.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In the system-supplied implementation of [IAccessControl](https://learn.microsoft.com/windows/desktop/api/iaccess/nn-iaccess-iaccesscontrol) (CLSID_DCOMAccessControl), **IsAccessAllowed** can be called only during a distributed COM call, and the only valid trustee name is the name of the client.

The following tables list the object-specific access permissions used with the Directory Service and storage implementation of [IAccessControl](https://learn.microsoft.com/windows/desktop/api/iaccess/nn-iaccess-iaccesscontrol).

The following permissions are specific to DS objects.

| Access permission | Description |
| --- | --- |
| ACTRL_DS_OPEN | Open a DS object |
| ACTRL_DS_CREATE_CHILD | Create a child object |
| ACTRL_DS_DELETE_CHILD | Delete a child object |
| ACTRL_DS_LIST | Enumerate an object |
| ACTRL_DS_SELF | Update a member list involving the trustee |
| ACTRL_DS_READ_PROP | Read properties |
| ACTRL_DS_WRITE_PROP | Write properties |

The following permissions are specific to file objects.

| Access permission | Description |
| --- | --- |
| ACTRL_FILE_READ | Read from a file |
| ACTRL_FILE_WRITE | Write to a file |
| ACTRL_FILE_APPEND | Append to a file |
| ACTRL_FILE_READ_PROP | Read file properties or extended attributes |
| ACTRL_FILE_WRITE_PROP | Write file properties or extended attributes |
| ACTRL_FILE_EXECUTE | Execute the file |
| ACTRL_FILE_READ_ATTRIB | Read the file attributes |
| ACTRL_FILE_WRITE_ATTRIB | Write the file attributes |

The following permissions are specific to directory objects.

| Access permission | Description |
| --- | --- |
| ACTRL_DIR_LIST | List the contents of a directory |
| ACTRL_DIR_CREATE_OBJECT | Create a child object (file) in a directory |
| ACTRL_DIR_CREATE_CHILD | Create a subdirectory |
| ACTRL_DIR_DELETE_CHILD | Delete a subdirectory |
| ACTRL_DIR_TRAVERSE | Traverse the directory |

The following permissions are specific to kernel objects.

| Access permission | Description |
| --- | --- |
| ACTRL_KERNEL_TERMINATE | Terminate a process or thread |
| ACTRL_KERNEL_THREAD | Create a thread |
| ACTRL_KERNEL_VM | Perform address space operations |
| ACTRL_KERNEL_VM_READ | Read from memory |
| ACTRL_KERNEL_VM_WRITE | Write to memory |
| ACTRL_KERNEL_DUP_HANDLE | Duplicate a handle |
| ACTRL_KERNEL_PROCESS | Create a process |
| ACTRL_KERNEL_SET_INFO | Get kernel object information or state |
| ACTRL_KERNEL_GET_INFO | Set kernel object information or state |
| ACTRL_KERNEL_CONTROL | Control a kernel object (such as suspending a thread) |
| ACTRL_KERNEL_ALERT | Alert a kernel object. |
| ACTRL_KERNEL_GET_CONTEXT | Get the thread context |
| ACTRL_KERNEL_SET_CONTEXT | Set the thread context |
| ACTRL_KERNEL_TOKEN | Set the thread token |
| ACTRL_KERNEL_IMPERSONATE | Impersonate a client |
| ACTRL_KERNEL_DIMPERSONATE | Directly impersonate a client |

The following permissions are specific to printer objects.

| Access permission | Description |
| --- | --- |
| ACTRL_PRINT_SADMIN | Administer a print server |
| ACTRL_PRINT_SLIST | Enumerate a print server |
| ACTRL_PRINT_PADMIN | Administer a printer |
| ACTRL_PRINT_PUSE | Use a printer |
| ACTRL_PRINT_JADMIN | Administer a print job |

The following permissions are specific to service objects.

| Access permission | Description |
| --- | --- |
| ACTRL_SVC_GET_INFO | Start a service |
| ACTRL_SVC_SET_INFO | Stop a service |
| ACTRL_SVC_STATUS | Pause a service |
| ACTRL_SVC_LIST | Enumerate the services |
| ACTRL_SVC_START | Start a service |
| ACTRL_SVC_STOP | Stop a service |
| ACTRL_SVC_PAUSE | Pause a service |
| ACTRL_SVC_INTERROGATE | Query the service for current status |
| ACTRL_SVC_UCONTROL | User-defined control |

The following permissions are specific to registry objects.

| Access permission | Description |
| --- | --- |
| ACTRL_REG_QUERY | Read a registry subkey |
| ACTRL_REG_SET | Write a registry subkey |
| ACTRL_REG_CREATE_CHILD | Create a registry subkey |
| ACTRL_REG_LIST | Enumerate a registry subkey |
| ACTRL_REG_NOTIFY | Create a registry notification |
| ACTRL_REG_LINK | Create a symbolic link |

The following permissions are specific to window objects.

| Access permission | Description |
| --- | --- |
| ACTRL_WIN_CLIPBRD | Enable access to the clipboard |
| ACTRL_WIN_GLOBAL_ATOMS | Enable global-atom access |
| ACTRL_WIN_CREATE | Create desktop access |
| ACTRL_WIN_LIST_DESK | Enumerate the desktops |
| ACTRL_WIN_LIST | Enumerate the window station |
| ACTRL_WIN_READ_ATTRIBS | Read the attributes |
| ACTRL_WIN_WRITE_ATTRIBS | Write the attributes |
| ACTRL_WIN_SCREEN | Enable access to the screen |
| ACTRL_WIN_EXIT | Call [ExitWindows](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindows) or [ExitWindowsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindowsex) |

## See also

[IAccessControl](https://learn.microsoft.com/windows/desktop/api/iaccess/nn-iaccess-iaccesscontrol)