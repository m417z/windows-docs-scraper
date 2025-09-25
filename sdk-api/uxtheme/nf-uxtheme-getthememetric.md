# GetThemeMetric function

## Description

Retrieves the value of a metric property.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's specified theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an HTHEME.

### `hdc` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

HDC. This parameter may be set to **NULL**.

### `iPartId` [in]

Type: **int**

Value of type **int** that specifies the part that contains the metric property. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iStateId` [in]

Type: **int**

Value of type **int** that specifies the state of the part. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iPropId` [in]

Type: **int**

Value of type **int** that specifies the property to retrieve. Can be one of the following values.

| Value | Meaning |
| --- | --- |
| **TMT_ALPHALEVEL** | The alpha value (0-255) used for [DrawThemeIcon](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-drawthemeicon). |
| **TMT_ALPHATHRESHOLD** | The minimum alpha value (0-255) that a pixel must be to be considered opaque. |
| **TMT_BORDERSIZE** | The thickness of the border drawn if this part uses a border fill. |
| **TMT_GLYPHINDEX** | The character index into the selected font that will be used for the glyph, if the part uses a font-based glyph. |
| **TMT_GRADIENTRATIO1** | The amount of the first gradient color to use in drawing the part. This value can be from 0 to 255, but this value plus the values of each of the GRADIENTRATIO values must add up to 255. See the TMT_GRADIENTCOLOR1 value of [GetThemeColor](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-getthemecolor). |
| **TMT_GRADIENTRATIO2** | The amount of the second gradient color to use in drawing the part. |
| **TMT_GRADIENTRATIO3** | The amount of the third gradient color to use in drawing the part. |
| **TMT_GRADIENTRATIO4** | The amount of the fourth gradient color to use in drawing the part. |
| **TMT_GRADIENTRATIO5** | The amount of the fifth gradient color to use in drawing the part. |
| **TMT_HEIGHT** | The height of the part. |
| **TMT_IMAGECOUNT** | The number of state images present in an image file. |
| **TMT_MINDPI1** | The minimum dpi that the first image file was designed for. See [GetThemeFilename](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-getthemefilename). |
| **TMT_MINDPI2** | The minimum dpi that the second image file was designed for. |
| **TMT_MINDPI3** | The minimum dpi that the third image file was designed for. |
| **TMT_MINDPI4** | The minimum dpi that the fourth image file was designed for. |
| **TMT_MINDPI5** | The minimum dpi that the fifth image file was designed for. |
| **TMT_PROGRESSCHUNKSIZE** | The size of the progress control "chunk" shapes that define how far an operation has progressed. |
| **TMT_PROGRESSSPACESIZE** | The total size of all of the progress control "chunks". |
| **TMT_ROUNDCORNERWIDTH** | The roundness (0-100%) of the part's corners. |
| **TMT_ROUNDCORNERHEIGHT** | The roundness (0-100%) of the part's corners. |
| **TMT_SATURATION** | The amount of saturation (0-255) to apply to an icon drawn using [DrawThemeIcon](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-drawthemeicon). |
| **TMT_TEXTBORDERSIZE** | The thickness of the border drawn around text characters. |
| **TMT_TRUESIZESTRETCHMARK** | The percentage of a true-size image's original size at which the image will be stretched. |
| **TMT_WIDTH** | The width of the part. |

### `piVal` [out]

Type: **int***

Pointer to an **int** that receives the metric property value.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs)