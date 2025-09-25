# DXGKDDI_UPDATEMONITORLINKINFO callback function

## Description

Implemented by the client driver to allow capabilities of a monitor which are tied to the link through which it is currently attached, to be queried.

## Parameters

### `hAdapter`

Identifies the adapter upon which the display timings should be set.

### `pUpdateMonitorLinkInfoArg`

A pointer to a [DXGKARG_UPDATEMONITORLINKINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_updatemonitorlinkinfo) structure, for which the driver writes the monitor link capabilities.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values). The driver should always return a success code unless there is an error in the parameters or a failure to process the request.

## Prototype

```cpp
//Declaration

DXGKDDI_UPDATEMONITORLINKINFO DxgkddiUpdatemonitorlinkinfo;

// Definition

NTSTATUS DxgkddiUpdatemonitorlinkinfo
(
	IN_CONST_HANDLE hAdapter
	INOUT_PDXGKARG_UPDATEMONITORLINKINFO pUpdateMonitorLinkInfoArg
)
{...}

```

## Remarks

UpdateMonitorLinkCapabilities will be called after the [RecommendMonitorModes](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendmonitormodes) callback function and before mode enumeration, so that capabilities which are not dependent on the specific display configuration can be queried by the OS without adding extra information into the enumeration. Then, by the time RecommendMonitorModes has completed, the driver has fully comprehended the capabilities of the monitor and can report them to the OS. This does not necessarily imply that all such capabilities are available regardless of the display configuration, but it allows the OS to make defined assumptions.

The DXGKARG_UPDATEMONITORLINKINFO structure also passes usage hints to the driver based on OS configuration of the monitor.

This function is always called at PASSIVE level.

## See also