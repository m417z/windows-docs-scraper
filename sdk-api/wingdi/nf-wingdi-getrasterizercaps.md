# GetRasterizerCaps function

## Description

The **GetRasterizerCaps** function returns flags indicating whether TrueType fonts are installed in the system.

## Parameters

### `lpraststat` [out]

A pointer to a [RASTERIZER_STATUS](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rasterizer_status) structure that receives information about the rasterizer.

### `cjBytes` [in]

The number of bytes to be copied into the structure pointed to by the *lprs* parameter.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **GetRasterizerCaps** function enables applications and printer drivers to determine whether TrueType fonts are installed.

If the TT_AVAILABLE flag is set in the **wFlags** member of the [RASTERIZER_STATUS](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rasterizer_status) structure, at least one TrueType font is installed. If the TT_ENABLED flag is set, TrueType is enabled for the system.

The actual number of bytes copied is either the member specified in the *cb* parameter or the length of the [RASTERIZER_STATUS](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rasterizer_status) structure, whichever is less.

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[GetOutlineTextMetrics](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getoutlinetextmetricsa)

[RASTERIZER_STATUS](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rasterizer_status)