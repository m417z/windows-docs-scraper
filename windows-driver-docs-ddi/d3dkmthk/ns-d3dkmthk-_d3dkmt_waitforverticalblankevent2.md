# _D3DKMT_WAITFORVERTICALBLANKEVENT2 structure

## Description

Describes parameters for multiple wait objects, including a vertical blank event. Supported starting with Windows 8.

## Members

### `hAdapter` [in]

A handle to the adapter.

### `hDevice` [in]

A handle to the display device. This member is optionally specified. However, if the OpenGL ICD specifies the display device, the kernel is given more optimization opportunities with regard to power usage.

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology for the VidPN source.

### `NumObjects`

The number of wait objects to wait on, which equals the size of the array specified by the **ObjectHandleArray** member.

### `ObjectHandleArray` [in]

A handle to an array of wait objects to wait on.