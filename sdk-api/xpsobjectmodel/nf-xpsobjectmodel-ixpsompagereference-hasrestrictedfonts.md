# IXpsOMPageReference::HasRestrictedFonts

## Description

Gets a Boolean value that indicates whether the document sub-tree of the referenced page includes any Glyphs that have a font resource whose **EmbeddingOption** property is set to [XPS_FONT_EMBEDDING_RESTRICTED](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_font_embedding).

## Parameters

### `restrictedFonts` [out, retval]

A Boolean value that indicates whether the document sub-tree of the referenced page includes any [IXpsOMGlyphs](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphs) interfaces that have a font resource whose **EmbeddingOption** property is set to [XPS_FONT_EMBEDDING_RESTRICTED](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_font_embedding).

| Value | Meaning |
| --- | --- |
| ****TRUE**** | If the referenced page is loaded, the page references at least one font resource whose **EmbeddingOption** property is set to [XPS_FONT_EMBEDDING_RESTRICTED](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_font_embedding).<br><br>If the referenced page is not loaded, it has a relationship with at least one font resource whose **EmbeddingOption** property is set to [XPS_FONT_EMBEDDING_RESTRICTED](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_font_embedding). |
| ****FALSE**** | If the referenced page is loaded, the page does not reference any font resources whose **EmbeddingOption** property is set to [XPS_FONT_EMBEDDING_RESTRICTED](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_font_embedding).<br><br>If the referenced page is not loaded, it does not have a relationship with a font resource whose **EmbeddingOption** property is set to [XPS_FONT_EMBEDDING_RESTRICTED](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_font_embedding). |

## Return value

If the method succeeds, it returns S_OK; otherwise, it returns an **HRESULT** error code.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *restrictedFonts* is **NULL**. |

## Remarks

This value is not updated automatically. If fonts or glyphs are added or removed such that the value changes, **HasRestrictedFonts** must be called again to get the current value.

## See also

[IXpsOMPageReference](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsompagereference)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS_FONT_EMBEDDING_RESTRICTED](https://learn.microsoft.com/windows/win32/api/xpsobjectmodel/ne-xpsobjectmodel-xps_font_embedding)