# D3DKMTSharedPrimaryLockNotification function

## Description

The **D3DKMTSharedPrimaryLockNotification** function notifies the operating system about an upcoming lock to a shared primary surface.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_SHAREDPRIMARYLOCKNOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_sharedprimarylocknotification) structure that describes the shared primary surface that an application will lock.

## Return value

**D3DKMTSharedPrimaryLockNotification** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | Notification about an upcoming lock to a shared primary surface was successfully performed. |
| STATUS_NO_MEMORY | **D3DKMTSharedPrimaryLockNotification** could not complete because of insufficient memory. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values that are defined in Ntstatus.h.

## Remarks

The OpenGL ICD calls the **D3DKMTSharedPrimaryLockNotification** function to inform the operating system that an application is about to lock the GDI shared primary surface that exists on the graphics adapter and video present source that the *AdapterLuid* and *VidPnSourceId* members of the [D3DKMT_SHAREDPRIMARYLOCKNOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_sharedprimarylocknotification) structure specify. The OpenGL ICD must call **D3DKMTSharedPrimaryLockNotification** before it calls the [D3DKMTLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtlock) function for the GDI shared primary surface to ensure that the operating system disables all sprites that intersect with the lock region that the *LockRect* member of [D3DKMT_SHAREDPRIMARYLOCKNOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_sharedprimarylocknotification) specifies.

## See also

[D3DKMTLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtlock)

[D3DKMT_SHAREDPRIMARYLOCKNOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_sharedprimarylocknotification)