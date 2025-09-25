# _D3DKMT_QUERYREMOTEVIDPNSOURCEFROMGDIDISPLAYNAME structure

## Description

Describes information that is required to map a GDI display name to a remote video present network (VidPN) source ID.

## Members

### `DeviceName` [in]

The name of the GDI device on which to open an adapter instance.

### `VidPnSourceId` [out]

The zero-based video present network (VidPN) source identifier for the display device that is represented by the **DeviceName** member.

## See also

[D3DKMTQueryRemoteVidPnSourceFromGdiDisplayName](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryremotevidpnsourcefromgdidisplayname)