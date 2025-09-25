# EditStreamSetNameW function

## Description

The **EditStreamSetName** function assigns a descriptive string to a stream.

## Parameters

### `pavi`

Handle to an open stream.

### `lpszName`

Null-terminated string containing the description of the stream.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

This function updates the **szName** member of the **AVISTREAMINFO** structure.

> [!NOTE]
> The vfw.h header defines EditStreamSetName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)