# _IRB_REQ_ISOCH_FREE_RESOURCES structure

## Description

This structure contains the fields necessary to carry out a IsochFreeResources request.

## Members

### `hResource`

Specifies the resource handle to release.

## Remarks

The bus driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS on success. All isochronous buffers that were attached to this resource must be detached prior to issuing this call. If a device driver attempts to free a resource handle with isochronous buffers still attached to it, the handle is not freed and the bus driver returns STATUS_ACCESS_DENIED instead.