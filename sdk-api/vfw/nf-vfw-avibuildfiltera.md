# AVIBuildFilterA function

## Description

The **AVIBuildFilter** function builds a filter specification that is subsequently used by the [GetOpenFileName](https://learn.microsoft.com/windows/win32/api/commdlg/nf-commdlg-getopenfilenamea) or [GetSaveFileName](https://learn.microsoft.com/windows/win32/api/commdlg/nf-commdlg-getsavefilenamea) function.

## Parameters

### `lpszFilter`

Pointer to the buffer containing the filter string.

### `cbFilter`

Size, in characters, of buffer pointed to by *lpszFilter*.

### `fSaving`

Flag that indicates whether the filter should include read or write formats. Specify **TRUE** to include write formats or **FALSE** to include read formats.

## Return value

Returns AVIERR_OK if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **AVIERR_BUFFERTOOSMALL** | The buffer size *cbFilter* was smaller than the generated filter specification. |
| **AVIERR_MEMORY** | There was not enough memory to complete the read operation. |

## Remarks

This function accesses the registry for all filter types that the AVIFile library can use to open, read, or write multimedia files. It does not search the hard disk for filter DLLs and formats.

> [!NOTE]
> The vfw.h header defines AVIBuildFilter as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)