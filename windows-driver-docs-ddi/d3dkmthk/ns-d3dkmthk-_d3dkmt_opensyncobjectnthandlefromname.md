# _D3DKMT_OPENSYNCOBJECTNTHANDLEFROMNAME structure

## Description

**D3DKMT_OPENSYNCOBJECTNTHANDLEFROMNAME** is used with [D3DKMTOpenSyncObjectNtHandleFromName](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopensyncobjectnthandlefromname) to open an NT handle for a named shared monitored fence object.

## Members

### `dwDesiredAccess` [in]

Access attributes for opening a shared monitored fence sync object, such as **D3DDDI_SYNC_OBJECT_WAIT**, **D3DDDI_SYNC_OBJECT_SIGNAL**, or **D3DDDI_SYNC_OBJECT_ALL_ACCESS**.

### `pObjAttrib` [in]

Object attributes for opening the object handle, including the shared object name information.

### `hNtHandle` [out]

NT handle to the sync object that can be used to open it via [D3DKMTOpenSyncObjectFromNtHandle2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopensyncobjectfromnthandle2).

## See also

[D3DKMTOpenSyncObjectFromNtHandle2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopensyncobjectfromnthandle2)

[D3DKMTOpenSyncObjectNtHandleFromName](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopensyncobjectnthandlefromname)