# INIT_AVCSTRM_HEADER macro

## Description

The **INIT_AVCSTRM_HEADER** macro initializes the **SizeOfThisBlock**, **Version** and **Function** members of the [AVC_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ns-avcstrm-_avc_stream_request_block) structure.

## Parameters

### `AVCStrm` [in]

Points to a caller-allocated AVC_STREAM_REQUEST_BLOCK structure.

### `Request` [in]

Indicates the type of the request (function code) from the [AVCSTRM_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ne-avcstrm-_avcstrm_function) enumeration. Each function code is documented under the [IOCTL_AVCSTRM_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ni-avcstrm-ioctl_avcstrm_class) topic.

## Remarks

The macro is defined as follows:

```cpp
#define INIT_AVCSTRM_HEADER( AVCStrm, Request ) \
    (AVCStrm)->;SizeOfThisBlock = sizeof(AVC_STREAM_REQUEST_BLOCK); \
    (AVCStrm)->;Function = Request;                    \
    (AVCStrm)->;Version  = CURRENT_AVCSTRM_DDI_VERSION;
```

## See also

[AVCSTRM_ABORT_STREAMING](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-abort-streaming)

[AVCSTRM_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-close)

[AVCSTRM_GET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-get-property)

[AVCSTRM_GET_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-get-state)

[AVCSTRM_OPEN](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-open)

[AVCSTRM_READ](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-read)

[AVCSTRM_SET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-set-property)

[AVCSTRM_SET_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-set-state)

[AVCSTRM_WRITE](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-write)

[AVC_STREAM_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ns-avcstrm-_avc_stream_request_block)

[IOCTL_AVCSTRM_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ni-avcstrm-ioctl_avcstrm_class)