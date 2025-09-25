# PlayEnhMetaFile function

## Description

The **PlayEnhMetaFile** function displays the picture stored in the specified enhanced-format metafile.

## Parameters

### `hdc` [in]

A handle to the device context for the output device on which the picture will appear.

### `hmf` [in]

A handle to the enhanced metafile.

### `lprect` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the coordinates of the bounding rectangle used to display the picture. The coordinates are specified in logical units.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

When an application calls the **PlayEnhMetaFile** function, the system uses the picture frame in the enhanced-metafile header to map the picture onto the rectangle pointed to by the *lpRect* parameter. (This picture may be sheared or rotated by setting the world transform in the output device before calling **PlayEnhMetaFile**.) Points along the edges of the rectangle are included in the picture.

An enhanced-metafile picture can be clipped by defining the clipping region in the output device before playing the enhanced metafile.

If an enhanced metafile contains an optional palette, an application can achieve consistent colors by setting up a color palette on the output device before calling **PlayEnhMetaFile**. To retrieve the optional palette, use the [GetEnhMetaFilePaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getenhmetafilepaletteentries) function.

An enhanced metafile can be embedded in a newly created enhanced metafile by calling **PlayEnhMetaFile** and playing the source enhanced metafile into the device context for the new enhanced metafile.

The states of the output device context are preserved by this function. Any object created but not deleted in the enhanced metafile is deleted by this function.

To stop this function, an application can call the [CancelDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-canceldc) function from another thread to terminate the operation. In this case, the function returns **FALSE**.

#### Examples

For an example, see [Opening an Enhanced Metafile and Displaying Its Contents](https://learn.microsoft.com/windows/desktop/gdi/opening-an-enhanced-metafile-and-displaying-its-contents).

## See also

[CancelDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-canceldc)

[GetEnhMetaFileHeader](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getenhmetafileheader)

[GetEnhMetaFilePaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getenhmetafilepaletteentries)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)