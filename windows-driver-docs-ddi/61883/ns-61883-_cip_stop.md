# _CIP_STOP structure

## Description

This structure is used to stop transmission or reception. The request stops isochronous transmission or reception on the specified connection. This request will stop capturing CIP packets, whether there are any frames attached. If frames are attached and the stream is resumed, then processing of the frame is resumed on the next source packet within the frame. To resume the stream on the beginning of the frame, a driver must set **Flags** with CIP_RESET_FRAME_ON_DISCONTINUITY in the [CIP_FRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_cip_frame) structure passed with AttachFrame request.

## Members

### `hConnect`

On input, a handle to the connection on which to stop isochronous transmission or reception.

## Remarks

If successful, the IEC-61883 protocol driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS.

If an incorrect parameter is passed in, the protocol driver sets **Irp->IoStatus.Status** to STATUS_INVALID_PARAMETER.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)