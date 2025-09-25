# PFND3D12DDI_SET_BACKGROUND_PROCESSING_MODE_0062 callback function

## Description

When an application changes background processing mode, PFND3D12DDI_SET_BACKGROUND_PROCESSING_MODE_0062 is called to inform the UMD of the new settings.

## Parameters

### `hRTDevice` [in]

The handle of the device for the driver to use when it calls back into the runtime.

### `Mode`

A [D3D12DDI_BACKGROUND_PROCESSING_MODE_0062](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_background_processing_mode_0062) enumeration that represents the background processing mode.

### `MeasurementsAction`

A [D3D12DDI_MEASUREMENTS_ACTION_0062](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_measurements_action_0062) enumeration that represents the measurement action.

## Prototype

```
//Declaration

PFND3D12DDI_SET_BACKGROUND_PROCESSING_MODE_0062 Pfnd3d12ddiSetBackgroundProcessingMode0062;

// Definition

void Pfnd3d12ddiSetBackgroundProcessingMode0062
(
	D3D12DDI_HDEVICE hRTDevice
	D3D12DDI_BACKGROUND_PROCESSING_MODE_0062 Mode
	D3D12DDI_MEASUREMENTS_ACTION_0062 MeasurementsAction
)
{...}

```

## Remarks

Background processing work must only ever be used for optimization purposes. These work items must not affect functional correctness of the implementation.

## See also