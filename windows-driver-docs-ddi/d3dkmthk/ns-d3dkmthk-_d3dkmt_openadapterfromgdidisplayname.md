# _D3DKMT_OPENADAPTERFROMGDIDISPLAYNAME structure

## Description

The D3DKMT_OPENADAPTERFROMGDIDISPLAYNAME structure describes the mapping of the given name of a GDI device to a graphics adapter handle and monitor output.

## Members

### `DeviceName` [in]

A Unicode string that contains the name of the GDI device from which to open an adapter instance.

### `hAdapter` [out]

A handle to the graphics adapter for the GDI device that **DeviceName** specifies. The adapter handle is returned from the call to the [D3DKMTOpenAdapterFromGdiDisplayName](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenadapterfromgdidisplayname) function.

### `AdapterLuid` [out]

The locally unique identifier ([LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)) of the graphics adapter for the GDI device that **DeviceName** specifies. The LUID is returned from the [D3DKMTOpenAdapterFromGdiDisplayName](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenadapterfromgdidisplayname) call.

### `VidPnSourceId` [out]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology for the GDI device that **DeviceName** specifies. The identification number is returned from the [D3DKMTOpenAdapterFromGdiDisplayName](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenadapterfromgdidisplayname) call.

## See also

[D3DKMTOpenAdapterFromGdiDisplayName](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenadapterfromgdidisplayname)