# AVISaveVA function

## Description

The **AVISaveV** function builds a file by combining data streams from other files or from memory.

## Parameters

### `szFile`

Null-terminated string containing the name of the file to save.

### `pclsidHandler`

Pointer to the file handler used to write the file. The file is created by calling the [AVIFileOpen](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avifileopen) function using this handler. If a handler is not specified, a default is selected from the registry based on the file extension.

### `lpfnCallback`

Pointer to a callback function used to display status information and to let the user cancel the save operation.

### `nStreams`

Number of streams to save.

### `ppavi`

Pointer to an array of pointers to the **AVISTREAM** function structures. The array uses one pointer for each stream.

### `plpOptions`

Pointer to an array of pointers to [AVICOMPRESSOPTIONS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-avicompressoptions) structures. The array uses one pointer for each stream.

## Return value

Returns AVIERR_OK if successful or an error otherwise.

## Remarks

This function is equivalent to the [AVISave](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avisavea) function except the streams are passed in an array instead of as a variable number of arguments.

This function creates a file, copies stream data into the file, closes the file, and releases the resources used by the new file. The last two parameters of this function are arrays that identify the streams to save in the file and define the compression options of those streams.

An application must allocate memory for the [AVICOMPRESSOPTIONS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-avicompressoptions) structures and the array of pointers to these structures.

The argument *ppavi* contains the address of a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

> [!NOTE]
> The vfw.h header defines AVISaveV as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)