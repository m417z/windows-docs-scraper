# AVIStreamOpenFromFileW function

## Description

The **AVIStreamOpenFromFile** function opens a single stream from a file.

## Parameters

### `ppavi`

Pointer to a buffer that receives the new stream handle.

### `szFile`

Null-terminated string containing the name of the file to open.

### `fccType`

Four-character code indicating the type of stream to be opened. Zero indicates that any stream can be opened. The following definitions apply to the data commonly found in AVI streams:

| Value | Description |
| --- | --- |
| streamtypeAUDIO | Indicates an audio stream. |
| streamtypeMIDI | Indicates a MIDI stream. |
| streamtypeTEXT | Indicates a text stream. |
| streamtypeVIDEO | Indicates a video stream. |

### `lParam`

Stream of the type specified in *fccType* to access. This parameter is zero-based; use zero to specify the first occurrence.

### `mode`

Access mode to use when opening the file. This function can open only existing streams, so the OF_CREATE mode flag cannot be used. For more information about the available flags for the *mode* parameter, see the **OpenFile** function.

### `pclsidHandler`

Pointer to a class identifier of the handler you want to use. If the value is **NULL**, the system chooses one from the registry based on the file extension or the file RIFF type.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

This function calls the [AVIFileOpen](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avifileopen), [AVIFileGetStream](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avifilegetstream), and [AVIFileRelease](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avifilerelease) functions.

> [!NOTE]
> The vfw.h header defines AVIStreamOpenFromFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)