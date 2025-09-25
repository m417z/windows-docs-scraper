# IRedbookDiscMaster::AddAudioTrackBlocks

## Description

Adds blocks of audio data to the currently open track. This method can be called repeatedly until there is no space available or the track is full.

## Parameters

### `pby` [in]

Pointer to an array of track blocks. The format is 44.1 KHz 16-bit stereo RAW audio samples, in the same format as used by WAV in the data section.

### `cb` [in]

Size of the array, in bytes. This count must be a multiple of the audio block size.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

After all blocks are added, call the
[CloseAudioTrack](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-iredbookdiscmaster-closeaudiotrack) method to finish the track.

If a call to this method would overrun the number of available audio blocks, then the method will return IMAPI_E_DISCFULL and keep as much of the audio data as it can. In contrast, the
[IJolietDiscMaster::AddData](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-ijolietdiscmaster-adddata) method does not keep any of the data, so there are no bad files.

## See also

[IRedbookDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-iredbookdiscmaster)