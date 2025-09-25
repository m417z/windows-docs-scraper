# _IRB_REQ_ISOCH_FREE_BANDWIDTH structure

## Description

This structure contains the fields necessary in order for the Bus driver to carry out an **IsochFreeBandwidth** request.

## Members

### `hBandwidth`

Specifies the bandwidth handle to release.

### `nMaxBytesPerFrameRequested`

### `fulSpeed`

### `BytesPerFrameAvailable`

### `SpeedSelected`

### `nBandwidthUnitsRequired`

## Remarks

If successful, the bus driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS, and the isochronous bandwidth is returned to the pool of available bandwidth.

A status of STATUS_INVALID_GENERATION also indicates success.

Do not resend the REQUEST_ISOCH_FREE_BANDWIDTH request in order to release isochronous bandwidth if the request failed with the STATUS_INVALID_GENERATION error code. In that case, it is safe to assume that isochronous bandwidth was released as a result of 1394 bus generation changes.