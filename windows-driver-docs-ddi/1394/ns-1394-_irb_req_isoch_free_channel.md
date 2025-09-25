# _IRB_REQ_ISOCH_FREE_CHANNEL structure

## Description

This structure contains the fields required to carry out an IsochFreeChannel request.

## Members

### `nChannel`

Specifies which allocated channel to release.

## Remarks

If successful, the bus driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS, and the isochronous channel is returned to the pool of available channels.