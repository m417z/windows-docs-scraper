# RtlDeleteRegistryValue function

## Description

The **RtlDeleteRegistryValue** routine removes the specified entry name and the associated values from the registry along the given relative path.

## Parameters

### `RelativeTo` [in]

Specifies whether *Path* is an absolute registry path or is relative to a predefined key path as one of the following.

| Value | Meaning |
| --- | --- |
| RTL_REGISTRY_ABSOLUTE | Path is an absolute registry path. |
| RTL_REGISTRY_SERVICES | Path is relative to **\Registry\Machine\System\CurrentControlSet\Services**. |
| RTL_REGISTRY_CONTROL | Path is relative to **\Registry\Machine\System\CurrentControlSet\Control**. |
| RTL_REGISTRY_WINDOWS_NT | Path is relative to **\Registry\Machine\Software\Microsoft\Windows NT\CurrentVersion**. |
| RTL_REGISTRY_DEVICEMAP | Path is relative to **\Registry\Machine\Hardware\DeviceMap**. |
| RTL_REGISTRY_USER | Path is relative to **\Registry\User\CurrentUser**. (For a system process, this is **\Users\.Default**.) |
| RTL_REGISTRY_HANDLE | Specifies that the *Path* parameter is actually a registry handle to use. This value is optional. |

### `Path` [in]

Specifies the registry path according to the *RelativeTo* value. If RTL_REGISTRY_HANDLE is set, *Path* is a handle to be used directly.

### `ValueName` [in]

Pointer to the value name to be removed from the registry.

## Return value

**RtlDeleteRegistryValue** returns STATUS_SUCCESS if the value entry was deleted.

Note that if *RelativeTo* is set to RTL_REGISTRY_HANDLE, the following occurs:

* On Windows 98/Me and Windows NT 4.0, the routine closes the specified handle before returning.
* On Windows 2000 and later versions of Windows, the routine leaves the handle open.

## See also

[RtlCheckRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcheckregistrykey)

[RtlQueryRegistryValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlqueryregistryvalues)

[RtlWriteRegistryValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlwriteregistryvalue)

[ZwEnumerateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratekey)

[ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey)