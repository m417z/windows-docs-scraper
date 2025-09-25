# EngDeviceIoControl function

## Description

The **EngDeviceIoControl** function sends a control code to the specified video miniport driver, causing the device to perform the specified operation.

## Parameters

### `hDevice` [in]

Handle to the device that is to perform the operation.

### `dwIoControlCode` [in]

Specifies the control code for the operation. The I/O controls are listed and described in full in [Video Miniport Driver I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/).

### `lpInBuffer` [in, optional]

Pointer to a buffer containing data required to perform the operation. This parameter can be **NULL** if the control code specifies an operation that does not require input data.

### `nInBufferSize` [in]

Specifies the size, in bytes, of *lpInBuffer*.

### `lpOutBuffer` [out, optional]

Pointer to a buffer in which the operation's output data is returned. This parameter can be **NULL** if the control code specifies an operation that does not produce output data.

### `nOutBufferSize` [in]

Specifies the size, in bytes, of *lpOutBuffer*.

### `lpBytesReturned` [out]

Pointer to a DWORD that specifies the actual size, in bytes, of the data returned in *lpOutBuffer*.

## Return value

The return value is a 32-bit Win32 API-defined error code.

## Remarks

**EngDeviceIoControl** is used by a display driver to communicate I/O requests to its corresponding miniport driver. This function provides the only communication channel between a display and video miniport driver.

## See also

[VIDEO_REQUEST_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/video/ns-video-_video_request_packet)