## Description

The **LVGroupCompare** function is an application-defined callback function used with the [LVM_INSERTGROUPSORTED](https://learn.microsoft.com/windows/desktop/Controls/lvm-insertgroupsorted) and [LVM_SORTGROUPS](https://learn.microsoft.com/windows/desktop/Controls/lvm-sortgroups) messages. It defines the ordering of the groups, based on the ID. The
**LVGROUPCOMPARE** type defines a pointer to this callback function. **LVGroupCompare** is a placeholder for the application-defined function name.

## Parameters

### `unnamedParam1`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The ID of the first group.

### `unnamedParam2`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The ID of the second group.

### `unnamedParam3`

Type: **[VOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to the application-defined information. This comes from the message that was called; for [LVM_INSERTGROUPSORTED](https://learn.microsoft.com/windows/desktop/Controls/lvm-insertgroupsorted) it is [LVINSERTGROUPSORTED.pvData](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvinsertgroupsorted), and for [LVM_SORTGROUPS](https://learn.microsoft.com/windows/desktop/Controls/lvm-sortgroups) it is the *plv* parameter.

## Return value

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns a negative value if the data for *Group1_ID* is less than the data for *Group2_ID*, a positive value if it is greater, or zero if it is the same.

## See also

[LVINSERTGROUPSORTED](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvinsertgroupsorted)

[LVM_INSERTGROUPSORTED](https://learn.microsoft.com/windows/desktop/Controls/lvm-insertgroupsorted)

[LVM_SORTGROUPS](https://learn.microsoft.com/windows/desktop/Controls/lvm-sortgroups)