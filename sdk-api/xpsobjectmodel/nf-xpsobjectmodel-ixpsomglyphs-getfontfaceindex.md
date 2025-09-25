# IXpsOMGlyphs::GetFontFaceIndex

## Description

Gets the index of the font face to be used.

This value is only used when [GetFontResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-getfontresource) returns an [IXpsOMFontResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomfontresource) interface that represents a **TrueType** font collection.

## Parameters

### `fontFaceIndex` [out, retval]

The index value of the font face. If the font face has not been set, –1 is returned.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *fontFaceIndex* is **NULL**. |

## Remarks

The font resource is obtained by calling the [GetFontResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-getfontresource) method.

If a font face has not been set or is not supported by the font, a value of –1 is returned in *fontFaceIndex*. When the glyph is loaded from an existing XPS document file, a *fontFaceIndex* value of –1 indicates that the **FontUri** attribute did not include a **#index** fragment.

In the following markup of a FixedPage, the **FontUri** attribute of the **Glyphs** element has a value of `../Resources/Fonts/Font.TTF#1`. In this case, **GetFontFaceIndex** would return a value of 1 in *fontFaceIndex*.

``` syntax
    <FixedPage Height="1056" Width="816" xml:lang="en-US"
    xmlns="http://schemas.microsoft.com/xps/2005/06">
      <Glyphs
      OriginX="96"
      OriginY="96"
      UnicodeString="This is Page 1!"
      FontUri="../Resources/Fonts/Font.TTF#1"
      FontRenderingEmSize="16" />
    </FixedPage>
```

## See also

[GetFontResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-getfontresource)

[IXpsOMFontResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomfontresource)

[IXpsOMGlyphs](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphs)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))