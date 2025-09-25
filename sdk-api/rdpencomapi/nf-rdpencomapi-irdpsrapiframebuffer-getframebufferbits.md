# IRDPSRAPIFrameBuffer::GetFrameBufferBits

## Description

Gets the bits in a specified area of the frame.

## Parameters

### `x` [in]

The x coordinate of the requested area of the frame.

### `y` [in]

The y coordinate of the requested area of the frame.

### `Width` [in]

The width of the requested area of the frame.

### `Height` [in]

The height of the requested area of the frame.

### `ppBits` [out, retval]

The contents of the frame buffer in the specified area.

## Return value

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[IRDPSRAPIFrameBuffer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiframebuffer)