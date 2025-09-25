# _FCP_GET_RESPONSE structure

## Description

The structure is used in a request yjsy retrieves the next FCP response from the queue of requests maintained by the IEC-61883 protocol driver. FCP requests and responses from AV devices are routed to the IEC-61883 protocol driver, which queues the requests. Client drivers send **Av61883_GetFcpResponse** to retrieve an FCP response from the queue.

## Members

### `NodeAddress`

On output, if the protocol driver is being used to control a virtual device, the protocol driver supplies the node address of the device that sent the response obtained with this **Av61883_GetFcpResponse** IRP. If the protocol driver is being used to control a physical device, **NodeAddress** is not used.

### `Length`

On input, the maximum available length, in bytes, of the frame payload, including FCP header.

On completion, this field will contain the actual length of the response in bytes.

### `Frame`

On input a pointer to a caller-allocated [FCP_FRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_fcp_frame) structure to receive the FCP response.

The FCP frame written to the caller-allocated FCP_FRAME structure by the protocol driver.

## Remarks

If successful, the IEC-61883 protocol driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS.

If the request is queued, the protocol driver sets a status of STATUS_PENDING. If the request has been previously canceled, the driver sets a status of STATUS_CANCELLED.

If an incorrect parameter is passed in, the protocol driver sets **Irp->IoStatus.Status** to STATUS_INVALID_PARAMETER.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)