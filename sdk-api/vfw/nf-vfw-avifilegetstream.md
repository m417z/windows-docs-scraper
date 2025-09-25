# AVIFileGetStream function

## Description

The **AVIFileGetStream** function returns the address of a stream interface that is associated with a specified AVI file.

## Parameters

### `pfile`

Handle to an open AVI file.

### `ppavi`

Pointer to the new stream interface.

### `fccType`

Four-character code indicating the type of stream to open. Zero indicates any stream can be opened. The following definitions apply to the data commonly found in AVI streams.

| Value | Description |
| --- | --- |
| streamtypeAUDIO | Indicates an audio stream. |
| streamtypeMIDI | Indicates a MIDI stream. |
| streamtypeTEXT | Indicates a text stream. |
| streamtypeVIDEO | Indicates a video stream. |

### `lParam`

Count of the stream type. Identifies which occurrence of the specified stream type to access.

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **AVIERR_NODATA** | The file does not contain a stream corresponding to the values of *fccType* and *lParam*. |
| **AVIERR_MEMORY** | Not enough memory. |

## Remarks

The argument *pfile* is a pointer to an [IAVIFile](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavifile) interface. The argument *ppavi* is a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)