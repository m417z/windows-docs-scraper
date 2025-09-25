# IXpsOMFontResource::SetContent

## Description

Sets the read-only stream to be associated with this resource.

## Parameters

### `sourceStream` [in]

The read-only stream to be associated with this resource.

### `embeddingOption` [in]

The [XPS_FONT_EMBEDDING](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_font_embedding) value that describes how the resource is to be obfuscated.

| Value | Meaning |
| --- | --- |
| **XPS_FONT_EMBEDDING_NORMAL** | Font resource is neither obfuscated nor restricted. |
| **XPS_FONT_EMBEDDING_OBFUSCATED** | Font resource is obfuscated but not restricted. |
| **XPS_FONT_EMBEDDING_RESTRICTED** | Font resource is both obfuscated and restricted. |

### `partName` [in]

The part name to be assigned to this resource.

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## Remarks

The calling method should treat this stream as a single-threaded apartment (STA) model object and not re-enter any of the stream interface's methods.

The stream assigned to this resource should not be obfuscated. Obfuscation of the font resource takes place during serialization.

Providing an obfuscated font stream while setting the *embeddingOption* to XPS_FONT_EMBEDDING_OBFUSCATED will result in a font that is not obfuscated in the serialized XPS document.

*partName* resets the part name for this object and is checked against the value of *embeddingOption* for the proper obfuscation syntax.

Because [GetStream](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomfontresource-getstream) gets a clone of the stream that is set by this method, the provided stream should have an efficient cloning method. A stream with an inefficient cloning method will reduce the performance of **GetStream**.

## See also

[IOpcPartUri](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nn-msopc-iopcparturi)

[IXpsOMFontResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomfontresource)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS_FONT_EMBEDDING](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_font_embedding)