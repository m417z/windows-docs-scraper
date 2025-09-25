# D3DDDICB_LOGUMDMARKER structure

## Description

Specifies info about the location of an Event Tracing for Windows (ETW) marker event that the user-mode display driver has defined.

## Members

### `hContext` [in]

A handle to a Direct3D context that signals ETW marker events. This is also the context that the [pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb) function will be called on.

### `APISequenceNumber`

The API sequence number that the marker event is associated with.

### `Index`

Indicates which API sequence call caused this marker event. If zero, the marker event corresponds to the latest API sequence number after a call to the [pfnSetMarker](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setmarker) function. If 1, the marker event is located at the following API sequence number. And so on.

Should be -1 if no time stamps are associated with this marker event.

### `StringIndex`

The offset, in bytes, of the string table entry pointed to by **Info**. Can be negative if the string is passed along with the marker event.

### `Info`

A custom text string embedded in the ETW packet. Can be **NULL**.

## See also

[pfnRenderCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb)

[pfnSetMarker](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setmarker)