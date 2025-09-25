# IVssWMComponent::FreeComponentInfo

## Description

The
**FreeComponentInfo** method deallocates system resources devoted to the specified component information.

## Parameters

### `pInfo` [out]

Pointer to a
[VSS_COMPONENTINFO](https://learn.microsoft.com/windows/desktop/api/vsbackup/ns-vsbackup-vss_componentinfo) structure that contains the component information.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully freed the component information data. |

## See also

[IVssWMComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivsswmcomponent)

[VSS_COMPONENTINFO](https://learn.microsoft.com/windows/desktop/api/vsbackup/ns-vsbackup-vss_componentinfo)