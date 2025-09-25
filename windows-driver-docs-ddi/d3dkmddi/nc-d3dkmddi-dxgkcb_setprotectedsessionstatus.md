## Description

A kernel-mode display miniport driver calls **DXGKCB_SETPROTECTEDSESSIONSTATUS** to set the status of a protected session.

## Parameters

### `pProtectedSessionStatus` [in]

Pointer to a [**DXGKARGCB_PROTECTEDSESSIONSTATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_protectedsessionstatus) structure that identifies the protected session and its status.

## Return value

**DXGKCB_SETPROTECTEDSESSIONSTATUS** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the members of [**DXGKARGCB_PROTECTEDSESSIONSTATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_protectedsessionstatus) and call **DxgkCbSetProtectedSessionStatus** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKARGCB_PROTECTEDSESSIONSTATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_protectedsessionstatus)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)