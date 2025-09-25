# DXGKDDI_CONTROLMODEBEHAVIOR callback function

## Description

The **DxgkDdiControlModeBehavior** function requests high-level mode enumeration and settings behaviors.

## Parameters

### `hAdapter` [in]

Handle to the WDDM display miniport adapter being queried.

### `pControlModeBehaviorArg` [in/out]

Pointer to a [DXGKARG_CONTROLMODEBEHAVIOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_controlmodebehavior) structure that contains the display mode behaviors that the OS is requesting from the driver as input, and the results of the request as output.

## Return value

**DxgkDdiCreateContext** returns one of the following values:

| Return code | Description |
|------------ | ----------- |
| STATUS_SUCCESS | The request has been successfully completed. |
| STATUS_NO_MEMORY | There is insufficient memory to complete this request. |
| STATUS_GRAPHICS_*XXX* | One of the invalid parameter codes that can be returned by the OS via DXGDDI_VIDPN* interfaces. These codes should occur only during development since they indicate a bug in the driver or OS. |

## Prototype

```cpp
//Declaration

DXGKDDI_CONTROLMODEBEHAVIOR DxgkddiControlmodebehavior;

// Definition

NTSTATUS DxgkddiControlmodebehavior
(
    IN_CONST_HANDLE hAdapter,
    INOUT_PDXGKARG_CONTROLMODEBEHAVIOR pControlModeBehaviorArg
)
{...}

```

## Remarks

## See also

[DXGKARG_CONTROLMODEBEHAVIOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_controlmodebehavior)