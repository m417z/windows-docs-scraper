# DXGKDDI_DISPLAYDETECTCONTROL callback function

## Description

Used to turn hot plug detection on and off and to initiate status polls on either a specific target or all targets.

## Parameters

### `hAdapter`

A handle that identifies the adapter.

### `pDisplayDetectControl`

A pointer to a [DXGKARG_DISPLAYDETECTCONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_displaydetectcontrol) structure that describes the detection action which is requested.

## Return value

If this routine succeeds, it returns STATUS_SUCCESS.

## Remarks

This function is always called at PASSIVE level so the supporting code should be made pageable.

The status returned only reflects the call, not the status of connectors. If the driver detects a change, it will respond by calling DxgkCbIndicateConnectorChange. If a poll of one or more targets was requested, the driver should return once the request has been submitted to hardware, rather than waiting for the poll to complete.

DXGK_DDCT_POLLONE applies only to the specified target id while DXGK_DDCT_POLLALL applies to all targets. It would be an OS error to request either of these types of detection control if HPD is not enabled so the driver can simply fail the call with STATUS_INVALID_PARAMETER.