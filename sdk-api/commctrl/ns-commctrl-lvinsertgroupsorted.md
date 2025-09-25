# LVINSERTGROUPSORTED structure

## Description

Used to sort groups. It is used with [LVM_INSERTGROUPSORTED](https://learn.microsoft.com/windows/desktop/Controls/lvm-insertgroupsorted).

## Members

### `pfnGroupCompare`

Type: **PFNLVGROUPCOMPARE**

Pointer to application-defined function [LVGroupCompare](https://learn.microsoft.com/windows/desktop/api/commctrl/nc-commctrl-pfnlvgroupcompare) that is used to sort the groups.

### `pvData`

Type: **[LPVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Data to sort; this is application-defined.

### `lvGroup`

Type: **[LVGROUP](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvgroup)**

Group to sort; this is application-defined.

## See also

[LVGroupCompare](https://learn.microsoft.com/windows/desktop/api/commctrl/nc-commctrl-pfnlvgroupcompare)

[LVM_INSERTGROUPSORTED](https://learn.microsoft.com/windows/desktop/Controls/lvm-insertgroupsorted)

**Reference**