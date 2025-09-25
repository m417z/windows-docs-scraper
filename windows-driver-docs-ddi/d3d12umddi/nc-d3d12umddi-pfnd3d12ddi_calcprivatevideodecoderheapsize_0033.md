# PFND3D12DDI_CALCPRIVATEVIDEODECODERHEAPSIZE_0033 callback function

## Description

Used to calculate the size of a video decoder heap. The D3D runtime allocates memory for storing the drivers cpu object representing the video decoder heap.

## Parameters

### `hDrvDevice`

The hardware device being processed.

### `pArgs`

The arguments used to create a video decoder heap.

## Return value

Returns the size of the heap in bytes.