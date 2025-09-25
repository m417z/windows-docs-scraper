# _FCP_GET_REQUEST structure

## Description

This structure is used for a get request.

The request retrieves the next FCP request from the queue of requests maintained by the IEC-61883 protocol driver. FCP requests and responses from AV devices are routed to the IEC-61883 protocol driver, which queues the requests. Client drivers send requests to retrieve an FCP request from the queue.

For requests sent to a virtual device, the **NodeAddress** member of the output FCP_GET_REQUEST structure contains the node address of the device that sent the FCP request. The client driver must supply this node address with its response so the instance of the protocol driver that controls the virtual device can route the response correctly.

For requests sent by a physical device, the 1394 bus driver determines the node address dynamically, and **NodeAddress** is not used.

## Members

### `NodeAddress`

On output, if the protocol driver is controlling a virtual device, **NodeAddress** contains the node address of the device that sent the FCP request obtained with this **Av61883_GetFcpRequest** IRP. The caller must use this node address in the FCP response sent so the 1394 bus driver can route the response to the correct device.

If the protocol driver is being used to control a physical device, **NodeAddress** is not used.

### `Length`

On completion, this field will contain the actual length of the request.

### `Frame`

On input, a pointer to a caller-allocated [FCP_FRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_fcp_frame) structure to receive the FCP request. On output, the FCP frame written to the caller-allocated **FCP_FRAME** structure by the protocol driver.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)