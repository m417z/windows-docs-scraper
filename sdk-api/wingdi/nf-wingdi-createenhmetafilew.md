## Description

The **CreateEnhMetaFile** function creates a device context for an enhanced-format metafile. This device context can be used to store a device-independent picture.

## Parameters

### `hdc` [in]

A handle to a reference device for the enhanced metafile. This parameter can be **NULL**; for more information, see Remarks.

### `lpFilename` [in]

A pointer to the file name for the enhanced metafile to be created. If this parameter is **NULL**, the enhanced metafile is memory based and its contents are lost when it is deleted by using the [DeleteEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteenhmetafile) function.

### `lprc` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the dimensions (in .01-millimeter units) of the picture to be stored in the enhanced metafile.

### `lpDesc` [in]

A pointer to a string that specifies the name of the application that created the picture, as well as the picture's title. This parameter can be **NULL**; for more information, see Remarks.

## Return value

If the function succeeds, the return value is a handle to the device context for the enhanced metafile.

If the function fails, the return value is **NULL**.

## Remarks

Where text arguments must use Unicode characters, use the **CreateEnhMetaFile** function as a wide-character function. Where text arguments must use characters from the Windows character set, use this function as an ANSI function.

The system uses the reference device identified by the *hdc* parameter to record the resolution and units of the device on which a picture originally appeared. If the *hdc* parameter is **NULL**, it uses the current display device for reference.

The **left** and **top** members of the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure pointed to by the *lprc* parameter must be less than the **right** and **bottom** members, respectively. Points along the edges of the rectangle are included in the picture. If *lprc* is **NULL**, the graphics device interface (GDI) computes the dimensions of the smallest rectangle that surrounds the picture drawn by the application. The *lprc* parameter should be provided where possible.

The string pointed to by the *lpDesc* parameter must contain a null character between the application name and the picture name and must terminate with two null characters, for example, "XYZ Graphics Editor\0Bald Eagle\0\0", where \0 represents the null character. If *lpDesc* is **NULL**, there is no corresponding entry in the enhanced-metafile header.

Applications use the device context created by this function to store a graphics picture in an enhanced metafile. The handle identifying this device context can be passed to any GDI function.

After an application stores a picture in an enhanced metafile, it can display the picture on any output device by calling the [PlayEnhMetaFile](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-playenhmetafile) function. When displaying the picture, the system uses the rectangle pointed to by the *lprc* parameter and the resolution data from the reference device to position and scale the picture.

The device context returned by this function contains the same default attributes associated with any new device context.

Applications must use the [GetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getwinmetafilebits) function to convert an enhanced metafile to the older Windows metafile format.

The file name for the enhanced metafile should use the `.emf` extension.

## Examples

For an example, see [Creating an Enhanced Metafile](https://learn.microsoft.com/windows/desktop/gdi/creating-an-enhanced-metafile).

> [!NOTE]
> The wingdi.h header defines CreateEnhMetaFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CloseEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-closeenhmetafile)

[DeleteEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteenhmetafile)

[GetEnhMetaFileDescription](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getenhmetafiledescriptiona)

[GetEnhMetaFileHeader](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getenhmetafileheader)

[GetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getwinmetafilebits)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[PlayEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-playenhmetafile)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)