# _D3DDDIARG_SETSTREAMSOURCE structure

## Description

The D3DDDIARG_SETSTREAMSOURCE structure describes the portion of the vertex stream to bind to a vertex buffer.

## Members

### `Stream` [in]

The stream to bind, which is a value between zero and the maximum number of streams that are specified by the driver.

### `hVertexBuffer` [in]

A handle to the vertex buffer. If this member is zero, the stream should no longer be bound to a vertex buffer.

### `Offset` [in]

The offset in bytes into the stream.

The **Offset** value must be DWORD-aligned.

### `Stride` [in]

The size, in bytes, from one vertex to the next vertex. If **Stride** is set to zero, all of the vertices receive the same data for processing.

For example, an application might use two input source streams where the first stream contains position information and the second stream contains normal information. If stride for the second stream is set to zero, all of the vertices in the second stream use the same normal information, which is the first normal information that occurs in the second stream.

The **Stride** value must be DWORD-aligned.

## See also

[SetStreamSource](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setstreamsource)