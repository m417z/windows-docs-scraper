## Description

A kernel-mode display miniport driver calls **DXGKCB_NOTIFYCURSORSUPPORTCHANGE** to notify the operating system that cursor support has been changed.

## Parameters

### `pArgs` [in]

Pointer to a [**DXGKARGCB_NOTIFYCURSORSUPPORTCHANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_notifycursorsupportchange) structure that contains the arguments for this callback.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS error code.

## Remarks

The kernel-mode driver can call **DXGKCB_NOTIFYCURSORSUPPORTCHANGE** either inside a DDI call from the OS or in an arbitrary thread before the adapter is stopped/removed.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the members of [**DXGKARGCB_NOTIFYCURSORSUPPORTCHANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_notifycursorsupportchange) and then call **DxgkCbNotifyCursorSupportChange** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKARGCB_NOTIFYCURSORSUPPORTCHANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_notifycursorsupportchange)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)