# AVISaveA function

## Description

The **AVISave** function builds a file by combining data streams from other files or from memory.

## Parameters

### `szFile`

Null-terminated string containing the name of the file to save.

### `pclsidHandler`

Pointer to the file handler used to write the file. The file is created by calling the [AVIFileOpen](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avifileopen) function using this handler. If a handler is not specified, a default is selected from the registry based on the file extension.

### `lpfnCallback`

Pointer to a callback function for the save operation.

### `nStreams`

Number of streams saved in the file.

### `pfile`

Pointer to an AVI stream. This parameter is paired with *lpOptions*. The parameter pair can be repeated as a variable number of arguments.

### `lpOptions`

Pointer to an application-defined [AVICOMPRESSOPTIONS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-avicompressoptions) structure containing the compression options for the stream referenced by *pavi*. This parameter is paired with pavi. The parameter pair can be repeated as a variable number of arguments.

### `...`

## Return value

Returns AVIERR_OK if successful or an error otherwise.

## Remarks

This function creates a file, copies stream data into the file, closes the file, and releases the resources used by the new file. The last two parameters of this function identify a stream to save in the file and define the compression options of that stream. When saving more than one stream in an AVI file, repeat these two stream-specific parameters for each stream in the file.

A callback function (referenced by using *lpfnCallback*) can display status information and let the user cancel the save operation. The callback function uses the following format:

```cpp

LONG PASCAL SaveCallback(int nPercent)

```

The *nPercent* parameter specifies the percentage of the file saved.

The callback function should return AVIERR_OK if the operation should continue and AVIERR_USERABORT if the user wishes to abort the save operation.

The argument *pavi* is a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

> [!NOTE]
> The vfw.h header defines AVISave as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)