# AMGetErrorTextW function

## Description

The **AMGetErrorText** function retrieves the error message for a given return code, using the current language setting.

This function converts **HRESULT** return codes to error messages. The constant MAX_ERROR_TEXT_LEN specifies the maximum number of characters in an error message.

## Parameters

### `hr`

**HRESULT** value.

### `pbuffer`

Pointer to a character buffer that receives the error message.

### `MaxLen`

Number of characters in *pBuffer*.

## Return value

Returns the number of characters returned in the buffer, or zero if an error occurred.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/DirectShow/functions)

## Remarks

> [!NOTE]
> The errors.h header defines AMGetErrorText as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).