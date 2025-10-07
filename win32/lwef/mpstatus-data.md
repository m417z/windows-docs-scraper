# MPSTATUS\_DATA structure

Contains data about the current status of a component of the product.

## Members

**ComponentID**

Type: **[**MPCOMPONENT\_ID**](https://learn.microsoft.com/windows/win32/lwef/mpcomponent-id)**

Specific component ID for which status is reported.

**fEnable**

Type: **BOOL**

Status requested for the component. **hResult** in the callback data signifies success or failure for the request.

**ComponentStatus**

Extra status data depending on value of **ComponentID**.

> [!Note]
> Currently results in a pointer to a dummy structure for all possible values of **ComponentID**.

**p1**

Type: **PMPSTATUS\_DATAEX\_UNUSED**

When **ComponentID** == **MPCOMPONENT\_AS\_SIGNATURE**. See [**MPSTATUS\_DATAEX\_UNUSED**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-dataex-unused).

**p2**

Type: **PMPSTATUS\_DATAEX\_UNUSED**

When **ComponentID** == **MPCOMPONENT\_AV\_SIGNATURE**. See [**MPSTATUS\_DATAEX\_UNUSED**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-dataex-unused).

**p3**

Type: **PMPSTATUS\_DATAEX\_UNUSED**

When **ComponentID** == **MPCOMPONENT\_REALTIME\_MONITOR**. See [**MPSTATUS\_DATAEX\_UNUSED**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-dataex-unused).

**p4**

Type: **PMPSTATUS\_DATAEX\_UNUSED**

When **ComponentID** == **MPCOMPONENT\_ONACCESS\_PROTECTION**. See [**MPSTATUS\_DATAEX\_UNUSED**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-dataex-unused).

**p5**

Type: **PMPSTATUS\_DATAEX\_UNUSED**

When **ComponentID** == **MPCOMPONENT\_IOAV\_PROTECTION**. See [**MPSTATUS\_DATAEX\_UNUSED**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-dataex-unused).

**p6**

Type: **PMPSTATUS\_DATAEX\_UNUSED**

When **ComponentID** == **MPCOMPONENT\_BEHAVIOR\_MONITOR**. See [**MPSTATUS\_DATAEX\_UNUSED**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-dataex-unused).

**p7**

Type: **PMPSTATUS\_DATAEX\_UNUSED**

When **ComponentID** == **MPCOMPONENT\_AUTO\_SCAN**. See [**MPSTATUS\_DATAEX\_UNUSED**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-dataex-unused).

**p8**

Type: **PMPSTATUS\_DATAEX\_UNUSED**

When **ComponentID** == **MPCOMPONENT\_AUTO\_SIGUPDATE**. See [**MPSTATUS\_DATAEX\_UNUSED**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-dataex-unused).

**p9**

Type: **PMPSTATUS\_DATAEX\_UNUSED**

When **ComponentID** == **MPCOMPONENT\_IPC**. See [**MPSTATUS\_DATAEX\_UNUSED**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-dataex-unused).

**pa**

Type: **PMPSTATUS\_DATAEX\_UNUSED**

When **ComponentID** == **MPCOMPONENT\_NIS**. See [**MPSTATUS\_DATAEX\_UNUSED**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-dataex-unused).

**pb**

Type: **PMPSTATUS\_DATAEX\_UNUSED**

When **ComponentID** == **MPCOMPONENT\_ELAM**. See [**MPSTATUS\_DATAEX\_UNUSED**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-dataex-unused).

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

## See also

[**MPCOMPONENT\_ID**](https://learn.microsoft.com/windows/win32/lwef/mpcomponent-id)

[**MPSTATUS\_DATAEX\_UNUSED**](https://learn.microsoft.com/windows/win32/lwef/mpstatus-dataex-unused)

