# CM_Add_ID_ExW function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Add_ID](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_idw) instead.]

The **CM_Add_ID_Ex** function appends a [device ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-ids) (if not already present) to a device instance's [hardware ID](https://learn.microsoft.com/windows-hardware/drivers/install/hardware-ids) list or [compatible ID](https://learn.microsoft.com/windows-hardware/drivers/install/compatible-ids) list, on either the local or a remote machine.

## Parameters

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the machine handle supplied by

*hMachine*

.

### `pszID` [in]

Caller-supplied pointer to a NULL-terminated device ID string.

### `ulFlags` [in]

Caller-supplied flag constant that specifies the list onto which the supplied device ID should be appended. The following flag constants are valid.

| Flag Constant | Definition |
| --- | --- |
| CM_ADD_ID_COMPATIBLE | The specified device ID should be appended to the specific device instance's compatible ID list. |
| CM_ADD_ID_HARDWARE | The specified device ID should be appended to the specific device instance's hardware ID list. |

### `hMachine` [in, optional]

Caller-supplied machine handle to which the caller-supplied device instance handle is bound.

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

Each appended device ID is considered less compatible than IDs already existing in the specified list. For information about device IDs, hardware IDs, and compatible IDs, see [Device Identification Strings](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

Callers of this function must have **SeLoadDriverPrivilege**. (Privileges are described in the Microsoft Windows SDK documentation.)

For information about using device instance handles that are bound to a local or a remote machine, see [CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex).

Functionality to access remote machines has been removed in Windows 8 and Windows Server 2012 and later operating systems thus you cannot access remote machines when running on these versions of Windows.

## See also

[CM_Add_ID](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_idw)

[CM_Get_Child_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child_ex)