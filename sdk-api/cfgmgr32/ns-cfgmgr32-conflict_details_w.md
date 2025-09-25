# CONFLICT_DETAILS_W structure

## Description

The CONFLICT_DETAILS structure is used as a parameter to the [CM_Get_Resource_Conflict_Details](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_resource_conflict_detailsw) function.

## Members

### `CD_ulSize`

Size, in bytes, of the CONFLICT_DETAILS structure.

### `CD_ulMask`

One or more bit flags supplied by the caller of **CM_Get_Resource_Conflict_Details**. The bit flags are described in the following table.

| Flag | Description |
| --- | --- |
| CM_CDMASK_DEVINST | If set, **CM_Get_Resource_Conflict_Details** supplies a value for the **CD_dnDevInst** member. |
| CM_CDMASK_RESDES | *Not used.* |
| CM_CDMASK_FLAGS | If set, **CM_Get_Resource_Conflict_Details** supplies a value for the **CD_ulFlags** member. |
| CM_CDMASK_DESCRIPTION | If set, **CM_Get_Resource_Conflict_Details** supplies a value for the **CD_szDescription** member. |

### `CD_dnDevInst`

If CM_CDMASK_DEVINST is set in **CD_ulMask**, this member will receive a handle to a device instance that has conflicting resources. If a handle is not obtainable, the member receives -1.

### `CD_rdResDes`

*Not used.*

### `CD_ulFlags`

If CM_CDMASK_FLAGS is set in **CD_ulMask**, this member can receive bit flags listed in the following table.

| Flag | Description |
| --- | --- |
| CM_CDFLAGS_DRIVER | If set, the string contained in the **CD_szDescription** member represents a driver name instead of a device name, and **CD_dnDevInst** is -1. |
| CM_CDFLAGS_ROOT_OWNED | If set, the conflicting resources are owned by the root device (that is, the HAL), and **CD_dnDevInst** is -1. |
| CM_CDFLAGS_RESERVED | If set, the owner of the conflicting resources cannot be determined, and **CD_dnDevInst** is -1. |

### `CD_szDescription`

If CM_CDMASK_DESCRIPTION is set in **CD_ulMask**, this member will receive a NULL-terminated text string representing a description of the device that owns the resources. If CM_CDFLAGS_DRIVER is set in **CD_ulFlags**, this string represents a driver name. If CM_CDFLAGS_ROOT_OWNED or CM_CDFLAGS_RESERVED is set, the string value is **NULL**.

## See also

[CM_Get_Resource_Conflict_Details](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_resource_conflict_detailsw)

## Remarks

> [!NOTE]
> The cfgmgr32.h header defines CONFLICT_DETAILS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).