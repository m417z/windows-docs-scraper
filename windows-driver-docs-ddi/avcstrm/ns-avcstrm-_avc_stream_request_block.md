## Description

The AVC_STREAM_REQUEST_BLOCK structure describes an AV/C streaming request to be processed by *avcstrm.sys*.

## Members

### `SizeOfThisBlock`

Specifies the size of the request block in bytes. Do not set this value directly. Instead, use the [INIT_AVCSTRM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/nf-avcstrm-init_avcstrm_header) macro.

### `Version`

Specifies the version of *avcstrm.sys* device driver interface (DDI) to service a request. Do not set this value directly. Instead, use the [INIT_AVCSTRM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/nf-avcstrm-init_avcstrm_header) macro.

### `Function`

Indicates the request (function code) *avcstrm.sys* services. This must be a value from the [AVCSTRM_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ne-avcstrm-_avcstrm_function) enumeration. Do not set this value directly. Instead, use the [INIT_AVCSTRM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/nf-avcstrm-init_avcstrm_header) macro.

### `Flags`

Special flags to indicate special service or deviation from standard service. This is currently not used.

### `Status`

Final status of this request.

### `AVCStreamContext`

This is context (handle) of a stream. Set this to **NULL** for the **AVCSTRM_OPEN** function code. For other function codes, this must be set to a valid value retrieved from an earlier call to AVCSTRM_OPEN.

### `Context1`

The context pointers of the client.

### `Context2`

The context pointers of the client.

### `Context3`

The context pointers of the client.

### `Context4`

The context pointers of the client.

### `Reserved`

Reserved. Do not use.

### `CommandData`

This is a union of command data to be passed to *avcstrm.sys* for service.

| Flag | Description |
|---|---|
| StreamState | Specifies the current state of the specified stream. This is used with the [AVCSTRM_GET_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-get-state) and [AVCSTRM_SET_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-set-state) function codes. |
| OpenStruct | Specifies a description of a stream to open. This is used with the [AVCSTRM_OPEN](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-open) function code. |
| BufferStruct | Specifies a description of a buffer used to read or write data from/to a specified stream. This is used with the [AVCSTRM_READ](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-read) and [AVCSTRM_WRITE](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-write) function codes. |

### `CommandData.StreamState`

Defines the **KSSTATE** member **StreamState**.

### `CommandData.OpenStruct`

Defines the **AVCSTRM_OPEN_STRUCT** member **OpenStruct**.

### `CommandData.BufferStruct`

Defines the **AVCSTRM_BUFFER_STRUCT** member **BufferStruct**.

### `_tagCommandData`

Defines the **_tagCommandData** member **_tagCommandData**.

## Remarks

The AVC_STREAM_REQUEST_BLOCK is the primary structure used by a subunit driver to interface with *avcstrm.sys*.

Every AV/C stream request is described by this structure. This structure is passed as part of the IRP to *avcstrm.sys* for service..

To use this structure, set the IRP's **Irp->Parameters->Others.Argument1** member to an allocated and initialized AVC_STREAM_REQUEST_BLOCK that describes the request (functionality) that the subunit driver wants *avcstrm.sys* to service.

## See also

[AVCSTRM_ABORT_STREAMING](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-abort-streaming)

[AVCSTRM_BUFFER_STRUCT](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ns-avcstrm-_avcstrm_buffer_struct)

[AVCSTRM_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-close)

[AVCSTRM_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ne-avcstrm-_avcstrm_function)

[AVCSTRM_GET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-get-property)

[AVCSTRM_GET_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-get-state)

[AVCSTRM_OPEN](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-open)

[AVCSTRM_OPEN_STRUCT](https://learn.microsoft.com/windows-hardware/drivers/ddi/avcstrm/ns-avcstrm-_avcstrm_open_struct)

[AVCSTRM_READ](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-read)

[AVCSTRM_SET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-set-property)

[AVCSTRM_SET_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-set-state)

[AVCSTRM_WRITE](https://learn.microsoft.com/windows-hardware/drivers/stream/avcstrm-write)

[KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate)