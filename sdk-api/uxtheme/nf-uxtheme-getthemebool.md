# GetThemeBool function

## Description

Retrieves the value of a **BOOL** property from the SysMetrics section of theme data.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's specified theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an HTHEME.

### `iPartId` [in]

Type: **int**

Value of type **int** that specifies the part containing the BOOL property. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iStateId` [in]

Type: **int**

Value of type **int** that specifies the state of the part. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iPropId` [in]

Type: **int**

Value of type **int** that specifies the property to retrieve. May be one of the following values.

| Value | Meaning |
| --- | --- |
| **TMT_TRANSPARENT** | **TRUE** if the image associated with the part and state have transparent areas. See [GetThemeColor](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-getthemecolor) for the definition of the TMT_TRANSPARENTCOLOR value that defines the transparent color. |
| **TMT_AUTOSIZE** | **TRUE** if the nonclient caption area associated with the part and state vary with text width. |
| **TMT_BORDERONLY** | **TRUE** if the image associated with the part and state should only have its border drawn. |
| **TMT_COMPOSITED** | **TRUE** if the control associated with the part and state will handle its own compositing of images. |
| **TMT_BGFILL** | **TRUE** if true-sized images associated with this part and state are to be drawn on the background fill. |
| **TMT_GLYPHTRANSPARENT** | **TRUE** if the glyph associated with this part and state have transparent areas. See [GetThemeColor](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-getthemecolor) for the definition of the TMT_GLYPHCOLOR value that defines the transparent color. |
| **TMT_GLYPHONLY** | **TRUE** if the glyph associated with this part and state should be drawn without a background. |
| **TMT_ALWAYSSHOWSIZINGBAR** | **TRUE** if the sizing bar associated with this part and state should always be shown. |
| **TMT_MIRRORIMAGE** | **TRUE** if the image associated with this part and state should be flipped if the window is being viewed in right-to-left reading mode. |
| **TMT_UNIFORMSIZING** | **TRUE** if the image associated with this part and state must have equal height and width. |
| **TMT_INTEGRALSIZING** | **TRUE** if the truesize image or border associated with this part and state must be sized to a factor of 2. |
| **TMT_SOURCEGROW** | **TRUE** if the image associated with this part and state will scale larger in size if necessary. |
| **TMT_SOURCESHRINK** | **TRUE** if the image associated with this part and state will scale smaller in size if necessary. |
| **TMT_USERPICTURE** | **TRUE** if the image associated with this part and state is based on the current user. |

### `pfVal` [out]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to a **BOOL** that receives the retrieved property value.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs)