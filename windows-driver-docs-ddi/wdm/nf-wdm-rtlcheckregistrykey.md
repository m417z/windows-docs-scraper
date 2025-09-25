# RtlCheckRegistryKey function

## Description

The **RtlCheckRegistryKey** routine checks for the existence of a given named key in the registry.

## Parameters

### `RelativeTo` [in]

Specifies whether *Path* is an absolute registry path or is relative to a predefined key path as one of the following.

| Value | Meaning |
| --- | --- |
| RTL_REGISTRY_ABSOLUTE | Path is an absolute registry path. |
| RTL_REGISTRY_CONTROL | Path is relative to **\Registry\Machine\System\CurrentControlSet\Control**. |
| RTL_REGISTRY_DEVICEMAP | Path is relative to **\Registry\Machine\Hardware\DeviceMap**. |
| RTL_REGISTRY_SERVICES | Path is relative to **\Registry\Machine\System\CurrentControlSet\Services**. |
| RTL_REGISTRY_USER | Path is relative to the registry settings for the current user. (For a system process, this is **\Users\.Default**.) This is equivalent to HKEY_CURRENT_USER in user mode. |
| RTL_REGISTRY_WINDOWS_NT | Path is relative to **\Registry\Machine\Software\Microsoft\Windows NT\CurrentVersion**. |
| RTL_REGISTRY_HANDLE | This value should not be passed into this routine. Despite the redundancy of a check for the existence of an already-opened key, it has the side effect of closing the passed handle. |

### `Path` [in]

Specifies the registry path according to the *RelativeTo* value. If RTL_REGISTRY_HANDLE is set, *Path* is a handle to be used directly.

## Return value

If the given named key exists in the registry along the given relative path, **RtlCheckRegistryKey** returns STATUS_SUCCESS.

## See also

[RtlQueryRegistryValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlqueryregistryvalues)