# GetEnhMetaFilePaletteEntries function

## Description

The **GetEnhMetaFilePaletteEntries** function retrieves optional palette entries from the specified enhanced metafile.

## Parameters

### `hemf` [in]

A handle to the enhanced metafile.

### `nNumEntries` [in]

The number of entries to be retrieved from the optional palette.

### `lpPaletteEntries` [out]

A pointer to an array of [PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85)) structures that receives the palette colors. The array must contain at least as many structures as there are entries specified by the *cEntries* parameter.

## Return value

If the array pointer is **NULL** and the enhanced metafile contains an optional palette, the return value is the number of entries in the enhanced metafile's palette; if the array pointer is a valid pointer and the enhanced metafile contains an optional palette, the return value is the number of entries copied; if the metafile does not contain an optional palette, the return value is zero. Otherwise, the return value is GDI_ERROR.

## Remarks

An application can store an optional palette in an enhanced metafile by calling the [CreatePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpalette) and [SetPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpaletteentries) functions before creating the picture and storing it in the metafile. By doing this, the application can achieve consistent colors when the picture is displayed on a variety of devices.

An application that displays a picture stored in an enhanced metafile can call the **GetEnhMetaFilePaletteEntries** function to determine whether the optional palette exists. If it does, the application can call the **GetEnhMetaFilePaletteEntries** function a second time to retrieve the palette entries and then create a logical palette (by using the [CreatePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpalette) function), select it into its device context (by using the [SelectPalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectpalette) function), and then realize it (by using the [RealizePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-realizepalette) function). After the logical palette has been realized, calling the [PlayEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-playenhmetafile) function displays the picture using its original colors.

## See also

[CreatePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpalette)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85))

[PlayEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-playenhmetafile)

[RealizePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-realizepalette)

[SelectPalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectpalette)