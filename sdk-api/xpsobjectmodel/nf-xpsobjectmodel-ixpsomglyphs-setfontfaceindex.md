# IXpsOMGlyphs::SetFontFaceIndex

## Description

Sets the index of the font face to be used.

This value is only used when [GetFontResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nf-xpsobjectmodel-ixpsomglyphs-getfontresource) returns an [IXpsOMFontResource](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomfontresource) interface that represents a **TrueType** font collection.

## Parameters

### `fontFaceIndex` [in]

The index value of the font face to be used.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For information about XPS document API return values that are not listed in this table, see [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The value of *fontFaceIndex* is not valid; it must be an integer that is greater than or equal to –1. |

## Remarks

The default value of the font face index property is –1, which means that a font index has not been set or the font resource is not a **TrueType** font collection.

If this value is specified and is not –1, "#\<Index>" is appended to the Font URI during serialization. Here, \<Index> is the value that is set by **SetFontFaceIndex**.

The following markup of a FixedPage shows the result of setting the *fontFaceIndex* to 1. Notice that the **FontUri** attribute of the **Glyphs** element has a value of `../Resources/Fonts/Font.TTF#1`, which includes the index of the font face.

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

[IXpsOMGlyphs](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel/nn-xpsobjectmodel-ixpsomglyphs)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))