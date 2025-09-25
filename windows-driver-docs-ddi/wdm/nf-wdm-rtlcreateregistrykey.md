# RtlCreateRegistryKey function

## Description

The **RtlCreateRegistryKey** routine adds a key object in the registry along a given relative path.

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

### `Path` [in]

Specifies the registry path according to the *RelativeTo* value.

## Return value

**RtlCreateRegistryKey** returns STATUS_SUCCESS if the key is created.

## Remarks

**RtlCreateRegistryKey** creates only the keys that you specify. It does not create missing keys in the path to the specified key. If any keys in the path are missing, the call will fail. To ensure that all keys in the path exist, you must call **RtlCreateRegistryKey** once for each key in the path.

## See also

[RtlCheckRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcheckregistrykey)

[RtlDeleteRegistryValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtldeleteregistryvalue)

[RtlQueryRegistryValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlqueryregistryvalues)

[RtlWriteRegistryValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlwriteregistryvalue)

[ZwEnumerateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwenumeratekey)

[ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey)