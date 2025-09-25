# _D3DKMT_SETVIDPNSOURCEOWNER structure

## Description

The D3DKMT_SETVIDPNSOURCEOWNER structure describes the parameters for setting or releasing the video present source in the path of a video present network (VidPN) topology that owns the VidPN.

## Members

### `hDevice` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the device that acquires or releases the VidPN source owner.

### `pType` [in]

An array of owner types. Elements of the array can contain the following values from the D3DKMT_VIDPNSOURCEOWNER_TYPE enumeration type.

|Value|Meaning|
|--- |--- |
|D3DKMT_VIDPNSOURCEOWNER_UNOWNED (0)|No owner, or GDI is the owner.|
|D3DKMT_VIDPNSOURCEOWNER_SHARED (1)|A shared owner. That is, the owner can yield to any exclusive owner. This type is not available to legacy devices.|
|D3DKMT_VIDPNSOURCEOWNER_EXCLUSIVE (2)|An exclusive owner without shared GDI primary.|
|D3DKMT_VIDPNSOURCEOWNER_EXCLUSIVEGDI (3)|An exclusive owner with shared GDI primary. This owner must exclusively own all of the VidPn sources. This type is available only to legacy devices.|

### `pVidPnSourceId` [in]

An array of zero-based identification numbers of the video present sources in paths of a video present network (VidPN) topology.

### `VidPnSourceCount`

The number of valid entries in the array that **pVidPnSourceId** specifies.

## See also

[D3DKMTSetVidPnSourceOwner](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetvidpnsourceowner)