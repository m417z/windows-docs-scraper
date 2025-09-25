# IDWriteGlyphRunAnalysis::GetAlphaBlendParams

## Description

 Gets alpha blending properties required for ClearType blending.

## Parameters

### `renderingParams`

Type: **[IDWriteRenderingParams](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriterenderingparams)***

An object that specifies the ClearType level and enhanced contrast, gamma, pixel geometry, and rendering mode. In most cases, the values returned by the output
parameters of this method are based on the properties of this object, unless a GDI-compatible rendering mode
was specified.

### `blendGamma` [out]

Type: **FLOAT***

When this method returns, contains the gamma value to use for gamma correction.

### `blendEnhancedContrast` [out]

Type: **FLOAT***

When this method returns, contains the enhanced contrast value to be used for blending.

### `blendClearTypeLevel` [out]

Type: **FLOAT***

When this method returns, contains the ClearType level used in the alpha blending.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteGlyphRunAnalysis](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwriteglyphrunanalysis)