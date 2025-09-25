# _FCP_SEND_REQUEST structure

## Description

This structure is used for a send request. The request sends an FCP request to the device. If the protocol driver is being used to represent a virtual device on the machine, the client driver must specify the **NodeAddress** member of FCP_SEND_REQUEST structure. This information is required in order to route the request to the proper node on the 1394 bus. If the protocol driver is being used to control a physical device, the 1394 bus driver determines the node address dynamically, and **NodeAddress** is not used.

## Members

### `NodeAddress`

On input, if the protocol driver is being used to control a virtual device, **NodeAddress** must contain the node address of the device to which this request is being sent so the protocol driver can route the request to the correct device. If the protocol driver is being used to control a physical device, **NodeAddress** is not used.

### `Length`

On input, the length of the Frame payload in bytes, including the FCP header.

### `Frame`

On input, a pointer to an [FCP_FRAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_fcp_frame) structure that contains the FCP request to send to the device.

## Remarks

If successful, the IEC-61883 protocol driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS.

If an incorrect parameter is passed in, the protocol driver sets **Irp->IoStatus.Status** to STATUS_INVALID_PARAMETER.

If the protocol driver is unable to allocate resources, it sets **Irp->IoStatus.Status** to STATUS_INSUFFICIENT_RESOURCES.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)