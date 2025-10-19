# GetObjectA function

## Description

The **GetObject** function retrieves information for the specified graphics object.

## Parameters

### `hgdiobj` [in]

A handle to the graphics object of interest. This can be a handle to one of the following: a logical bitmap, a brush, a font, a palette, a pen, or a device independent bitmap created by calling the [CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection) function.

### `cbBuffer` [in]

The number of bytes of information to be written to the buffer.

### `lpvObject` [out]

A pointer to a buffer that receives the information about the specified graphics object.

The following table shows the type of information the buffer receives for each type of graphics object you can specify with *hgdiobj*.

| Object type | Data written to buffer |
| --- | --- |
| **HBITMAP** | [BITMAP](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmap) |
| **HBITMAP returned from a call to [CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection)** | [DIBSECTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-dibsection), if *cbBuffer* is set to `sizeof (DIBSECTION)`, or [BITMAP](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmap), if *cbBuffer* is set to `sizeof (BITMAP)`. |
| **HPALETTE** | A **WORD** count of the number of entries in the logical palette |
| **HPEN returned from a call to [ExtCreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreatepen)** | [EXTLOGPEN](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-extlogpen) |
| **HPEN** | [LOGPEN](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logpen) |
| **HBRUSH** | [LOGBRUSH](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logbrush) |
| **HFONT** | [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) |

If the *lpvObject* parameter is **NULL**, the function return value is the number of bytes required to store the information it writes to the buffer for the specified graphics object.

The address of *lpvObject* must be on a 4-byte boundary; otherwise, **GetObject** fails.

## Return value

If the function succeeds, and *lpvObject* is a valid pointer, the return value is the number of bytes stored into the buffer.

If the function succeeds, and *lpvObject* is **NULL**, the return value is the number of bytes required to hold the information the function would store into the buffer.

If the function fails, the return value is zero.

## Remarks

The buffer pointed to by the *lpvObject* parameter must be sufficiently large to receive the information about the graphics object. Depending on the graphics object, the function uses a [BITMAP](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmap), [DIBSECTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-dibsection), [EXTLOGPEN](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-extlogpen), [LOGBRUSH](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logbrush), [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta), or [LOGPEN](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logpen) structure, or a count of table entries (for a logical palette).

If *hgdiobj* is a handle to a bitmap created by calling [CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection), and the specified buffer is large enough, the **GetObject** function returns a [DIBSECTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-dibsection) structure. In addition, the **bmBits** member of the [BITMAP](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmap) structure contained within the **DIBSECTION** will contain a pointer to the bitmap's bit values.

If *hgdiobj* is a handle to a bitmap created by any other means, **GetObject** returns only the width, height, and color format information of the bitmap. You can obtain the bitmap's bit values by calling the [GetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdibits) or [GetBitmapBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbitmapbits) function.

If *hgdiobj* is a handle to a logical palette, **GetObject** retrieves a 2-byte integer that specifies the number of entries in the palette. The function does not retrieve the [LOGPALETTE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logpalette) structure defining the palette. To retrieve information about palette entries, an application can call the [GetPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getpaletteentries) function.

If *hgdiobj* is a handle to a font, the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) that is returned is the **LOGFONT** used to create the font. If Windows had to make some interpolation of the font because the precise **LOGFONT** could not be represented, the interpolation will not be reflected in the **LOGFONT**. For example, if you ask for a vertical version of a font that doesn't support vertical painting, the **LOGFONT** indicates the font is vertical, but Windows will paint it horizontally.

#### Examples

For an example, see [Storing an Image](https://learn.microsoft.com/windows/desktop/gdi/storing-an-image).

> [!NOTE]
> The wingdi.h header defines GetObject as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[BITMAP](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmap)

[CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection)

[DIBSECTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-dibsection)

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[EXTLOGPEN](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-extlogpen)

[GetBitmapBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbitmapbits)

[GetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdibits)

[GetPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getpaletteentries)

[GetRegionData](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getregiondata)

[LOGBRUSH](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logbrush)

[LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta)

[LOGPALETTE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logpalette)

[LOGPEN](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logpen)