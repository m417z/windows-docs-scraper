# _CMP_GET_PLUG_STATE structure

## Description

This structure is used in getting the state of a plug.The request retrieves state information for the specified plug, including its current connections and bus data format. Plug state is volatile and can change unexpectedly.

## Members

### `hPlug`

On input, the handle of the plug to retrieve state information.

### `State`

On output, the state of the plug. Can be one of the following:

CMP_PLUG_STATE_IDLE

CMP_PLUG_STATE_READY

CMP_PLUG_STATE_SUSPENDED

CMP_PLUG_STATE_ACTIVE

### `DataRate`

On output, the data rate of the plug. Can be one of the following:

CMP_SPEED_S100

CMP_SPEED_S200

CMP_SPEED_S400

### `Payload`

On output, the payload size for the plug.

### `BC_Connections`

On output, the number of broadcast connections associated with the plug.

### `PP_Connections`

On output, the number of point-to-point connections associated with the plug.

## Remarks

If successful, the IEC-61883 protocol driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS.

If an incorrect parameter is passed in, the protocol driver sets **Irp->IoStatus.Status** to STATUS_INVALID_PARAMETER.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)