# _CIP_ATTACH_FRAME structure

## Description

This structure is used in an attach frame request. The request attaches a frame buffer to the specified plug for a subsequent Talk or Listen request. The IEC-61883 protocol driver subdivides the frames into source packets and blocks. By default, the timestamp returned is the time at completion of the frame transmission.

## Members

### `hConnect`

A handle to the connection.

### `FrameLength`

The length of the frame in bytes. The total frame length must be evenly divisible by the value in **SourceLength**.

### `SourceLength`

The length of the source packets, in bytes. The source length must be evenly divisible into the frame length.

### `Frame`

Pointer to a [CIP_FRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_cip_frame) structure that contains information about the frame and a data buffer to be sent or filled.

## Remarks

If successful, the IEC-61883 protocol driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS.

If an incorrect parameter is passed in, the protocol driver sets **Irp->IoStatus.Status** to STATUS_INVALID_PARAMETER.

If the protocol driver is unable to allocate resources, it sets **Irp->IoStatus.Status** to STATUS_INSUFFICIENT_RESOURCES.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)