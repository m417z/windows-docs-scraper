# _CIP_CANCEL_FRAME structure

## Description

This structure is the input buffer in a cancel frame request. The request cancels an attached frame buffer. A frame can be canceled while the stream is running. If the canceled frame has already been sent, the protocol driver sets a status of STATUS_NOT_FOUND.

## Members

### `hConnect`

A handle to a connection.

### `Frame`

Pointer to a [CIP_FRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_cip_frame) structure that contains information about the frame to cancel.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)