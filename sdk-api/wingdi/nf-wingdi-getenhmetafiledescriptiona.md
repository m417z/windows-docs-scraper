# GetEnhMetaFileDescriptionA function

## Description

The **GetEnhMetaFileDescription** function retrieves an optional text description from an enhanced-format metafile and copies the string to the specified buffer.

## Parameters

### `hemf` [in]

A handle to the enhanced metafile.

### `cchBuffer` [in]

The size, in characters, of the buffer to receive the data. Only this many characters will be copied.

### `lpDescription` [out]

A pointer to a buffer that receives the optional text description.

## Return value

If the optional text description exists and the buffer pointer is **NULL**, the return value is the length of the text string, in characters.

If the optional text description exists and the buffer pointer is a valid pointer, the return value is the number of characters copied into the buffer.

If the optional text description does not exist, the return value is zero.

If the function fails, the return value is GDI_ERROR.

## Remarks

The optional text description contains two strings, the first identifying the application that created the enhanced metafile and the second identifying the picture contained in the metafile. The strings are separated by a null character and terminated with two null characters, for example, "XYZ Graphics Editor\0Bald Eagle\0\0" where \0 represents the null character.

Where text arguments must use Unicode characters, use this function as a wide-character function. Where text arguments must use characters from the Windows character set, use this function as an ANSI function.

> [!NOTE]
> The wingdi.h header defines GetEnhMetaFileDescription as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CreateEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createenhmetafilea)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)