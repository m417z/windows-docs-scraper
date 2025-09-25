# CM_Add_IDW function

## Description

The **CM_Add_ID** function appends a specified [device ID](https://learn.microsoft.com/windows-hardware/drivers/install/device-ids) (if not already present) to a [device instance's](https://learn.microsoft.com/windows-hardware/drivers/) [hardware ID](https://learn.microsoft.com/windows-hardware/drivers/install/hardware-ids) list or [compatible ID](https://learn.microsoft.com/windows-hardware/drivers/install/compatible-ids) list.

## Parameters

### `dnDevInst` [in]

Caller-supplied device instance handle that is bound to the local machine.

### `pszID` [in]

Caller-supplied pointer to a NULL-terminated device ID string.

### `ulFlags` [in]

Caller-supplied flag constant that specifies the list onto which the supplied device ID should be appended. The following flag constants are valid.

| Flag Constant | Definition |
| --- | --- |
| CM_ADD_ID_COMPATIBLE | The specified device ID should be appended to the specific device instance's compatible ID list. |
| CM_ADD_ID_HARDWARE | The specified device ID should be appended to the specific device instance's hardware ID list. |

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

The **CM_Add_ID** function can only be used when *dnDevInst* represents a root-enumerated device. For other devices, the bus driver reports hardware and compatible IDs when enumerating a child device after receiving [IRP_MN_QUERY_ID](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-id).

Each appended device ID is considered less compatible than IDs already existing in the specified list. For information about device IDs, hardware IDs, and compatible IDs, see [Device Identification Strings](https://learn.microsoft.com/windows-hardware/drivers/install/device-identification-strings).

Callers of this function must have **SeLoadDriverPrivilege**. (Privileges are described in the Microsoft Windows SDK documentation.)

For information about using device instance handles that are bound to the local machine, see [CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child).

## See also

[CM_Add_ID_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_add_id_exw)

[CM_Get_Child](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_child)