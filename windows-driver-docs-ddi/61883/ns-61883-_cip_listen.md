# _CIP_LISTEN structure

## Description

This structure is used for a listen request. The request begins isochronous reception on the specified connection. This request will start capturing CIP packets, whether the packets have frames attached.

## Members

### `hConnect`

On input, the handle of the connection to begin isochronous reception.

## Remarks

If successful, the IEC-61883 protocol driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS.

If an incorrect parameter is passed in, the protocol driver sets **Irp->IoStatus.Status** to STATUS_INVALID_PARAMETER.

If the protocol driver is unable to allocate resources, it sets **Irp->IoStatus.Status** to STATUS_INSUFFICIENT_RESOURCES.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)