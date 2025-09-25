# _D3DKMT_SHAREDPRIMARYUNLOCKNOTIFICATION structure

## Description

The D3DKMT_SHAREDPRIMARYUNLOCKNOTIFICATION structure describes the shared primary surface that an application just unlocked.

## Members

### `AdapterLuid` [in]

The locally unique identifier ([LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)) of the graphics adapter on which the GDI shared primary surface exists.

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology on which the GDI shared primary surface exists.

## See also

[D3DKMTSharedPrimaryUnLockNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsharedprimaryunlocknotification)