# PSS_HANDLE_FLAGS enumeration

## Description

Flags to specify what parts of a [PSS_HANDLE_ENTRY](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ns-processsnapshot-pss_handle_entry) structure are valid.

## Constants

### `PSS_HANDLE_NONE:0x00`

No parts specified.

### `PSS_HANDLE_HAVE_TYPE:0x01`

The **ObjectType** member is valid.

### `PSS_HANDLE_HAVE_NAME:0x02`

The **ObjectName** member is valid.

### `PSS_HANDLE_HAVE_BASIC_INFORMATION:0x04`

The **Attributes**, **GrantedAccess**, **HandleCount**, **PointerCount**, **PagedPoolCharge**, and **NonPagedPoolCharge** members are valid.

### `PSS_HANDLE_HAVE_TYPE_SPECIFIC_INFORMATION:0x08`

The **TypeSpecificInformation** member is valid (either **Process**, **Thread**, **Mutant**, **Event** or **Section**).

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)