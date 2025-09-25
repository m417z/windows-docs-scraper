# MapFileAndCheckSumW function

## Description

Computes the checksum of the specified file.

## Parameters

### `Filename` [in]

The file name of the file for which the checksum is to be computed.

### `HeaderSum` [out]

A pointer to a variable that receives the original checksum from the image file, or zero if there is an error.

### `CheckSum` [out]

A pointer to a variable that receives the computed checksum.

## Return value

If the function succeeds, the return value is CHECKSUM_SUCCESS (0).

If the function fails, the return value is one of the following.

| Return code/value | Description |
| --- | --- |
| **CHECKSUM_MAP_FAILURE**<br><br>2 | Could not map the file. |
| **CHECKSUM_MAPVIEW_FAILURE**<br><br>3 | Could not map a view of the file. |
| **CHECKSUM_OPEN_FAILURE**<br><br>1 | Could not open the file. |
| **CHECKSUM_UNICODE_FAILURE**<br><br>4 | Could not convert the file name to Unicode. |

## Remarks

The
**MapFileAndCheckSum** function computes a new checksum for the file and returns it in the *CheckSum* parameter. This function is used by any application that creates or modifies an executable image. Checksums are required for kernel-mode drivers and some system DLLs. The linker computes the original checksum at link time, if you use the appropriate linker switch. For more details, see your linker documentation.

It is recommended that all images have valid checksums. It is the caller's responsibility to place the newly computed checksum into the mapped image and update the on-disk image of the file.

Passing a *Filename* parameter that does not point to a valid executable image will produce unpredictable results. Any user of this function is encouraged to make sure that a valid executable image is being passed.

All ImageHlp functions, such as this one, are single threaded. Therefore, calls from more than one thread to this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize all concurrent calls from more than one thread to this function.

**Note** The Unicode implementation of this function calls the ASCII implementation and as a result, the function can fail if the codepage does not support the characters in the path. For example, if you pass a non-English Unicode file path, and the default codepage is English, the unrecognized non-English wide chars are converted to "??" and the file cannot be opened (the function returns CHECKSUM_OPEN_FAILURE).

> [!NOTE]
> The imagehlp.h header defines MapFileAndCheckSum as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CheckSumMappedFile](https://learn.microsoft.com/windows/desktop/api/imagehlp/nf-imagehlp-checksummappedfile)

[ImageHlp Functions](https://learn.microsoft.com/windows/desktop/Debug/imagehlp-functions)