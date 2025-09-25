# PFND3D12DDI_CALCPRIVATEVIDEOPROCESSORSIZE_0032 callback function

## Description

This method is used to calculate the driver object size. The D3D runtime allocates memory for storing the drivers CPU object that represents the video processor.

## Parameters

### `hDrvDevice`

The hardware device being processed.

### `pArgs`

The arguments used to create a video processor.

## Return value

Returns the size of the video processor in bytes.