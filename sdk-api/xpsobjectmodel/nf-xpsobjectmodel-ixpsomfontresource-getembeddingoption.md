# IXpsOMFontResource::GetEmbeddingOption

## Description

Gets the embedding option that will be applied when the resource is serialized.

## Parameters

### `embeddingOption` [out, retval]

The stream's embedding option.

The [XPS_FONT_EMBEDDING](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_font_embedding) value describes how the resource is obfuscated. The following possible values are returned in this parameter:

| Value | Meaning |
| --- | --- |
| **XPS_FONT_EMBEDDING_NORMAL** | Font resource is neither obfuscated nor restricted. |
| **XPS_FONT_EMBEDDING_OBFUSCATED** | Font resource is obfuscated but not restricted. |
| **XPS_FONT_EMBEDDING_RESTRICTED** | Font resource is both obfuscated and restricted. |

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

## See also

[IXpsOMFontResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomfontresource)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS_FONT_EMBEDDING](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_font_embedding)