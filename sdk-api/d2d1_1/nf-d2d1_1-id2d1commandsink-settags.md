# ID2D1CommandSink::SetTags

## Description

Sets the tags that correspond to the tags in the command sink.

## Parameters

### `tag1`

Type: **[D2D1_TAG](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-tag)**

The first tag to associate with the primitive.

### `tag2`

Type: **[D2D1_TAG](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-tag)**

The second tag to associate with the primitive.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## See also

[ID2D1CommandList::Stream](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1commandlist-stream)

[ID2D1CommandSink](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandsink)

[ID2D1RenderTarget::SetTags](https://learn.microsoft.com/windows/desktop/api/d2d1/nf-d2d1-id2d1rendertarget-settags)