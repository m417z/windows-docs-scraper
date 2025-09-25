## Description

The _CPSUICALLBACK function type is used by CPSUI applications (including printer interface DLLs) for defining a callback function intended for use as a [CPSUI message handler](https://learn.microsoft.com/windows-hardware/drivers/print/cpsui-message-handler).

## Parameters

### `pCPSUICBParam`

CPSUI-supplied pointer to a [**CPSUICBPARAM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_cpsuicbparam) structure.

## Return value

A _CPSUICALLBACK-typed callback function must return one of the values listed in the following table. Each value indicates an action that CPSUI should perform.

| Return code | Description |
|---|---|
| **CPSUICB_ACTION_ITEMS_APPLIED** | The [**CPSUICBPARAM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_cpsuicbparam) structure's **Reason** member was set to CPSUICB_REASON_APPLYNOW, and the callback function has successfully processed the current option values. |
| **CPSUICB_ACTION_NO_APPLY_EXIT** | The [**CPSUICBPARAM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_cpsuicbparam) structure's **Reason** member was set to CPSUICB_REASON_APPLYNOW, but the callback function has detected invalid or incompatible option values. The callback function must display a dialog box telling the user of the problem. |
| **CPSUICB_ACTION_NONE** | No action by CPSUI is required. |
| **CPSUICB_ACTION_OPTIF_CHANGED** | The callback function has set the OPTIF_CHANGED flag in an [OPTITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optitem) structure to indicate that the selected option has changed, or that another OPTIF-prefixed flag has changed. |
| **CPSUICB_ACTION_REINIT_ITEMS** | The callback function has set the OPTIF_CHANGED flag in an [OPTITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optitem) structure to indicate that **Flags** or **pData** members of the associated [OPTTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_opttype) or [OPTPARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optparam) structure have changed. |

## Remarks

Callback functions specified using the _CPSUICALLBACK function type are supplied by applications that use [CPSUI](https://learn.microsoft.com/windows-hardware/drivers/print/common-property-sheet-user-interface) to manage property sheet pages. If one of these callback functions is associated with a property sheet page, CPSUI calls it when user activity (such as changing the page's control focus, modifying option values, or clicking **OK**) is detected.

A _CPSUICALLBACK-typed callback function is assigned to a property sheet page by including its address in a [**COMPROPSHEETUI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_compropsheetui) structure, which is passed to CPSUI's [ComPropSheet](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfncompropsheet) function when the function code is [CPSFUNC_ADD_PCOMPROPSHEETUI](https://learn.microsoft.com/previous-versions/ff546388(v=vs.85)).

Additionally, callback functions can be assigned to extended push buttons through the use of [EXTPUSH](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_extpush) structures.

When one of these callback functions is called, it receives a pointer to a [**CPSUICBPARAM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_cpsuicbparam) structure. This structure describes the current option settings for the page and indicates the user event that caused the function to be called. The callback function is responsible for validating and processing the settings. It should display a dialog box if a setting (or a combination of settings) is invalid. The function's return value indicates to CPSUI whether the page needs to be redisplayed or reinitialized.

Callback functions specified with this function type cannot be used if the **DlgProc** member of the [**DLGPAGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_dlgpage) structure specifies an application-supplied dialog box procedure. This is because _CPSUICALLBACK-typed callbacks are called from CPSUI's dialog box procedures, which are not used if the application supplies its own procedures.