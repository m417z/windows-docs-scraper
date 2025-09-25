# _CIP_TALK structure

## Description

This structure is used to begin transmission. The request begins isochronous transmission on the specified connection. This request will start transmitting CIP packets, whether there are any frames attached. If no frames are attached, empty CIP packets are transmitted for every isochronous cycle.

## Members

### `hConnect`

On input, the handle of the connection to begin isochronous transmission.

## Remarks

In the request, Flags can have these values:

CIP_TALK_USE_SPH_TIMESTAMP

Indicates that the timestamp within the SPH should be used to calculate the timing of transmission of isochronous packets.

CIP_TALK_DOUBLE_BUFFER

Indicates that when transmitting the attached frames should be double-buffered.

If successful, the IEC-61883 protocol driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS.

If an incorrect parameter is passed in, the protocol driver sets **Irp->IoStatus.Status** to STATUS_INVALID_PARAMETER.

If the protocol driver is unable to allocate resources, it sets **Irp->IoStatus.Status** to STATUS_INSUFFICIENT_RESOURCES.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)