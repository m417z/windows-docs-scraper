# _STATUS_BLOCK structure

## Description

The STATUS_BLOCK structure is a substructure within the VIDEO_REQUEST_PACKET structure. A miniport driver's [HwVidStartIO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_start_io) function must set the status block of each [VRP](https://learn.microsoft.com/windows-hardware/drivers/) that it gets.

## Members

### `Status`

Indicates the result of the requested operation. This member might be one of the following status codes:

#### ERROR_INSUFFICIENT_BUFFER

Either the VRP **InputBuffer** is too small to provide the data required to process the given request or the **OutputBuffer** is too small to return the requested data.

#### ERROR_INVALID_FUNCTION

The miniport driver does not handle this request.

#### ERROR_INVALID_PARAMETER

A parameter in the VRP is invalid.

#### ERROR_IO_PENDING

An operation has not yet completed.

#### ERROR_MORE_DATA

The driver has additional data to be returned but has already filled the given VRP **OutputBuffer**.

#### ERROR_NOT_ENOUGH_MEMORY

There is insufficient memory to process the request.

#### NO_ERROR

The requested operation has been carried out and completed successfully.

### `Pointer`

Should be ignored by the miniport driver. This member of the union exists to guarantee field alignment across 32- and 64-bit systems.

### `Information`

Supplies additional information about the completed operation. The meaning of the value varies according to VRP. Generally, this member is used to return the minimum size required for the input buffer if the VRP passes data in the **InputBuffer**. Alternatively, it contains the number of bytes of data transferred if the requested operation returns data in the VRP **OutputBuffer**.

## See also

[HwVidStartIO](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_start_io)

[VIDEO_REQUEST_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_video_request_packet)