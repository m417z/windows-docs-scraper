# _D3DKMT_SHAREDPRIMARYLOCKNOTIFICATION structure

## Description

The D3DKMT_SHAREDPRIMARYLOCKNOTIFICATION structure describes the shared primary surface that an application is about to lock.

## Members

### `AdapterLuid` [in]

The locally unique identifier ([LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)) of the graphics adapter on which the GDI shared primary surface exists.

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology on which the GDI shared primary surface exists.

### `LockRect` [in]

A [RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl) structure that indicates the upper-left and lower-right points of a rectangle on the shared primary surface; the operating system disables all sprites that intersect with this rectangle. If the OpenGL ICD specifies zero for each member of RECTL, the operating system disables all sprites on the shared primary surface.

## See also

[D3DKMTSharedPrimaryLockNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsharedprimarylocknotification)

[RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl)