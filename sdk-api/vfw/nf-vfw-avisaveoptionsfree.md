# AVISaveOptionsFree function

## Description

The **AVISaveOptionsFree** function frees the resources allocated by the [AVISaveOptions](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avisaveoptions) function.

## Parameters

### `nStreams`

Count of the [AVICOMPRESSOPTIONS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-avicompressoptions) structures referenced in *plpOptions*.

### `plpOptions`

Pointer to an array of pointers to [AVICOMPRESSOPTIONS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-avicompressoptions) structures. These structures hold the compression options set by the dialog box. The resources allocated by [AVISaveOptions](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-avisaveoptions) for each of these structures will be freed.

## Return value

Returns AVIERR_OK.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)