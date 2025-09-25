# PFND3D12DDI_CALCPRIVATEVIDEODECODERSIZE_0032 callback function

## Description

Used to calculate the size of a video decoder. The D3D runtime allocates memory for storing the drivers CPU object representing the video decoder.

## Parameters

### `hDrvDevice`

The hardware device being processed.

### `pArgs` [in]

The arguments used to create a video decoder.

## Return value

Returns the size of the video decoder in bytes.

## Remarks

The runtime allocates memory for storing the driver CPU object that represents the video decoder. This method is used to calculate the driver object size.