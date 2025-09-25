# EditStreamSetInfoA function

## Description

The **EditStreamSetInfo** function changes characteristics of an editable stream.

## Parameters

### `pavi`

Handle to an open stream.

### `lpInfo`

Pointer to an [AVISTREAMINFO](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-avistreaminfoa) structure containing new information.

### `cbInfo`

Size, in bytes, of the structure pointed to by *lpInfo*.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

You must supply information for the entire [AVISTREAMINFO](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-avistreaminfoa) structure, including the members you will not use. You can use the [AVIStreamInfo](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avistreaminfoa) function to initialize the structure and then update selected members with your data.

This function does not change the following members:

* **dwCaps**
* **dwEditCount**
* **dwFlags**
* **dwInitialFrames**
* **dwLength**
* **dwSampleSize**
* **dwSuggestedBufferSize**
* **fccHandler**
* **fccType**

The function changes the following members:

* **dwRate**
* **dwQuality**
* **dwScale**
* **dwStart**
* **rcFrame**
* **szName**
* **wLanguage**
* **wPriority**

> [!NOTE]
> The vfw.h header defines EditStreamSetInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)