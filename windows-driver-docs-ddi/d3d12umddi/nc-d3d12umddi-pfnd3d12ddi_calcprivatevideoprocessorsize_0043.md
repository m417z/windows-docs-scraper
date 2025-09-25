# PFND3D12DDI_CALCPRIVATEVIDEOPROCESSORSIZE_0043 callback function

## Description

This method is used to calculate the driver object size. The Direct3D runtime allocates memory for storing the drivers CPU object that represents the video processor.

## Parameters

### `hDrvDevice`

A handle to the display device (graphics context).

### `pArgs`

The arguments used to create a video processor.

## Return value

Returns the size of the video processor in bytes.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALCPRIVATEVIDEOPROCESSORSIZE_0043 Pfnd3d12ddiCalcprivatevideoprocessorsize0043;

// Definition

SIZE_T Pfnd3d12ddiCalcprivatevideoprocessorsize0043
(
	D3D12DDI_HDEVICE hDrvDevice
	CONST D3D12DDIARG_CREATE_VIDEO_PROCESSOR_0043 *pArgs
)
{...}

PFND3D12DDI_CALCPRIVATEVIDEOPROCESSORSIZE_0043

```

## Remarks

## See also