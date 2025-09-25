# AVIFILEINFOW structure

## Description

The **AVIFILEINFO** structure contains global information for an entire AVI file.

## Members

### `dwMaxBytesPerSec`

Approximate maximum data rate of the AVI file.

### `dwFlags`

A bitwise **OR** of zero or more flags. The following flags are defined:

| Name | Description |
| --- | --- |
| **AVIFILEINFO_HASINDEX** | The AVI file has an index at the end of the file. For good performance, all AVI files should contain an index. |
| **AVIFILEINFO_MUSTUSEINDEX** | The file index contains the playback order for the chunks in the file. Use the index rather than the physical ordering of the chunks when playing back the data. This could be used for creating a list of frames for editing. |
| **AVIFILEINFO_ISINTERLEAVED** | The AVI file is interleaved. |
| **AVIFILEINFO_WASCAPTUREFILE** | The AVI file is a specially allocated file used for capturing real-time video. Applications should warn the user before writing over a file with this flag set because the user probably defragmented this file. |
| **AVIFILEINFO_COPYRIGHTED** | The AVI file contains copyrighted data and software. When this flag is used, software should not permit the data to be duplicated. |

### `dwCaps`

Capability flags. The following flags are defined:

| Name | Description |
| --- | --- |
| **AVIFILECAPS_CANREAD** | An application can open the AVI file with the read privilege. |
| **AVIFILECAPS_CANWRITE** | An application can open the AVI file with the write privilege. |
| **AVIFILECAPS_ALLKEYFRAMES** | Every frame in the AVI file is a key frame. |
| **AVIFILECAPS_NOCOMPRESSION** | The AVI file does not use a compression method. |

### `dwStreams`

Number of streams in the file. For example, a file with audio and video has at least two streams.

### `dwSuggestedBufferSize`

Suggested buffer size, in bytes, for reading the file. Generally, this size should be large enough to contain the largest chunk in the file. For an interleaved file, this size should be large enough to read an entire record, not just a chunk.

If the buffer size is too small or is set to zero, the playback software will have to reallocate memory during playback, reducing performance.

### `dwWidth`

Width, in pixels, of the AVI file.

### `dwHeight`

Height, in pixels, of the AVI file.

### `dwScale`

Time scale applicable for the entire file. Dividing **dwRate** by **dwScale** gives the number of samples per second.

Any stream can define its own time scale to supersede the file time scale.

### `dwRate`

Rate in an integer format. To obtain the rate in samples per second, divide this value by the value in **dwScale**.

### `dwLength`

Length of the AVI file. The units are defined by **dwRate** and **dwScale**.

### `dwEditCount`

Number of streams that have been added to or deleted from the AVI file.

### `szFileType`

Null-terminated string containing descriptive information for the file type.

## See also

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[AVIFile Structures](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-structures)

## Remarks

> [!NOTE]
> The vfw.h header defines AVIFILEINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).