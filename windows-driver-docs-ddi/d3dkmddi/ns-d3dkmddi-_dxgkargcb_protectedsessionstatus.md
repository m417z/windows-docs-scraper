# DXGKARGCB_PROTECTEDSESSIONSTATUS structure

## Description

The **DXGKARGCB_PROTECTEDSESSIONSTATUS** structure contains arguments used by the [**DXGKCB_SETPROTECTEDSESSIONSTATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_setprotectedsessionstatus) callback function, to set the status on a protected session.

## Members

### `hProtectedSession` [in]

A handle for the protected session that was passed to [**DxgkDdiCreateProtectedSession**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprotectedsession).

### `Status` [in]

A [**DXGK_PROTECTED_SESSION_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_protected_session_status) value that indicates the status of the protected session.

## See also

[**DXGK_PROTECTED_SESSION_STATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_protected_session_status)

[**DXGKCB_SETPROTECTEDSESSIONSTATUS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_setprotectedsessionstatus)

[**DxgkDdiCreateProtectedSession**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprotectedsession)