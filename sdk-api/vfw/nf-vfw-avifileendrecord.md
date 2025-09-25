# AVIFileEndRecord function

## Description

The **AVIFileEndRecord** function marks the end of a record when writing an interleaved file that uses a 1:1 interleave factor of video to audio data. (Each frame of video is interspersed with an equivalent amount of audio data.)

## Parameters

### `pfile`

Handle to an open AVI file.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

The [AVISave](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avisavea) function uses this function internally. In general, applications should not need to use this function.

The argument *pfile* is a pointer to an [IAVIFile](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavifile) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)