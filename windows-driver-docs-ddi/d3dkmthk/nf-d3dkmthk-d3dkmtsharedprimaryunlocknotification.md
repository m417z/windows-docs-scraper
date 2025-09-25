# D3DKMTSharedPrimaryUnLockNotification function

## Description

The **D3DKMTSharedPrimaryUnLockNotification** function notifies the operating system that a shared primary surface was unlocked.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_SHAREDPRIMARYUNLOCKNOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_sharedprimaryunlocknotification) structure that describes the shared primary surface that was unlocked.

## Return value

**D3DKMTSharedPrimaryUnLockNotification** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | Notification about unlocking a shared primary surface was successfully performed. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## Remarks

The OpenGL ICD calls the **D3DKMTSharedPrimaryUnLockNotification** function to inform the operating system that an application just unlocked the GDI shared primary surface that exists on the graphics adapter and video present source that the *AdapterLuid* and *VidPnSourceId* members of the [D3DKMT_SHAREDPRIMARYUNLOCKNOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_sharedprimaryunlocknotification) structure specify. The OpenGL ICD should call **D3DKMTSharedPrimaryUnLockNotification** after it calls the [D3DKMTUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtunlock) function to unlock the GDI shared primary surface.

## See also

[D3DKMTUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtunlock)

[D3DKMT_SHAREDPRIMARYUNLOCKNOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_sharedprimaryunlocknotification)