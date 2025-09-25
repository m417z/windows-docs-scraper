# ID2D1CommandSink::EndDraw

## Description

Indicates when [ID2D1CommandSink](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandsink) processing has completed.

## Return value

Type: **HRESULT**

If the method/function succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

The **HRESULT** active at the end of the command list will be returned.

 It allows the calling function or method to indicate a failure back to the stream implementation.

## See also

[ID2D1CommandList::Stream](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1commandlist-stream)

[ID2D1CommandSink](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandsink)

[ID2D1RenderTarget::EndDraw](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-enddraw)