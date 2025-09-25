# PFND3D12DDI_CREATEVIDEOPROCESSOR_0043 callback function

## Description

The *pfnCreateVideoProcessor* callback function creates a video processor.

## Parameters

### `hDrvDevice`

A handle to the display device (graphics context).

### `pArgs`

The arguments used to create a video processor.

### `hDrvVideoProcessor`

The video processor.

## Return value

Returns STATUS_SUCCESS if completed successfully.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATEVIDEOPROCESSOR_0043 Pfnd3d12ddiCreatevideoprocessor0043;

// Definition

HRESULT Pfnd3d12ddiCreatevideoprocessor0043
(
	D3D12DDI_HDEVICE hDrvDevice
	CONST D3D12DDIARG_CREATE_VIDEO_PROCESSOR_0043 *pArgs
	D3D12DDI_HVIDEOPROCESSOR_0020 hDrvVideoProcessor
)
{...}

PFND3D12DDI_CREATEVIDEOPROCESSOR_0043

```

## Remarks

Register your implementation of this callback function by setting the appropriate member of D3D12DDIARG_CREATE_VIDEO_PROCESSOR_0043 and then calling Pfnd3d12ddiCreatevideoprocessor0043.

## See also