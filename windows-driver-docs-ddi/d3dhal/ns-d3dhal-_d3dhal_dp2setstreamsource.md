# _D3DHAL_DP2SETSTREAMSOURCE structure

## Description

 DirectX 8.0 and later versions only.

The D3DHAL_DP2SETSTREAMSOURCE structure is used to bind a vertex stream source to a vertex buffer for [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

## Members

### `dwStream`

Specifies the stream being bound. It has a value between zero and the maximum number of streams specified by the driver.

### `dwVBHandle`

Specifies the vertex buffer handle. It is legal for the vertex buffer handle to be zero, in which case the stream is no longer bound to a vertex buffer.

### `dwStride`

Specifies the vertex size in bytes.

## Remarks

A driver is notified of the binding of a vertex buffer to a particular stream through a new DP2 token, D3DDP2OP_SETSTREAMSOURCE.

The debug runtime validates that **dwStream** is within the legal range but the retail version does not, so validation must be present in the driver. DirectX 8.0 does not define the behavior of the driver or hardware in the error case where the stream index given is larger than the maximum stream supported by the hardware (as reported through **MaxStreams** in D3DCAPS8) beyond requiring that the driver and hardware combination not fault or hang in this case and that, on restoration of correct state the driver and hardware combination should continue to operate normally. Debug versions of your display driver should display messages in the debug output stream indicating when this problem has been detected.

The runtime does not validate that the streams accessed by the current vertex shader are non-NULL. It is the responsibility of the driver writer to ensure the driver/hardware does not crash when this error case arises. Debug versions of your display driver should display messages in the debug output stream to indicate when this problem has been detected.

Only a single stream source is set by a [D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command) structure. That is, the **wStateCount** field of the D3DHAL_DP2COMMAND is always one when **bCommand** is D3DDP2OP_SETSTREAMSOURCE.

## See also

D3DDP2OP_SETSTREAMSOURCE

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3DHAL_DP2SETSTREAMSOURCEUM](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2setstreamsourceum)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)