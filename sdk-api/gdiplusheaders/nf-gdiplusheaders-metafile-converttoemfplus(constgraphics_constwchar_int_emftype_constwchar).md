## Description

The [Metafile::ConvertToEmfPlus](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-metafile-converttoemfplus(inconstgraphics_inconstwchar_inoutint_inemftype_inconstwchar)) method converts this [Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile) object to the EMF+ format.

## Parameters

### `refGraphics` [in]

Type: **const [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)***

Pointer to a [Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) object whose state (settings for antialiasing, interpolation, and the like) is applied to the records stored in the converted metafile.

### `filename` [in]

Type: **const WCHAR***

Pointer to a null-terminated wide-character string that specifies the name of a file to which the converted metafile is saved.

### `conversionFailureFlag`

TBD

### `emfType` [in]

Type: **[EmfType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emftype)**

Optional. Element of the [EmfType](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-emftype) enumeration that specifies whether the converted file has the **EmfTypeEmfPlusOnly** format or the **EmfTypeEmfPlusDual** format. Do not pass **EmfTypeEmfOnly**. The default value is **EmfTypeEmfPlusOnly**.

### `description` [in]

Type: **const WCHAR***

Optional. Pointer to a null-terminated wide-character string that is stored in the header of the converted metafile. The default value is **NULL**.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns OK, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

This method replaces the records originally in the [Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile) object with the converted records. To retain a copy of the original **Metafile** object, call the [Clone](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-clone) method.

If you set the *emfType* parameter to **EmfTypeEmfPlusDual**, the converted metafile contains an Enhanced Metafile (EMF) representation and an EMF+ representation. The EMF representation is the original set of EMF records rather than EMF records converted back from the newly created EMF+ records.

It is possible for the return value to be **Ok** and the value returned in *conversionSuccess* to be **FALSE**. Sometimes the overall conversion is considered to be successful even if a few individual records failed to convert with complete accuracy. For example, the original metafile might have records or operations that are not supported by Windows GDI+ (or EMF+), in which case those records or operations are emulated.