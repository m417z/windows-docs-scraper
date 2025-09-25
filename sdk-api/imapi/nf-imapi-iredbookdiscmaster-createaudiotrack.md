# IRedbookDiscMaster::CreateAudioTrack

## Description

Begins staging a new audio track. It can be called only when there are no open audio tracks in the image.

## Parameters

### `nBlocks` [in]

Number of audio blocks to be added to this track. You can create up to 99 tracks, and the open track may consume all remaining available audio blocks.

The *nBlocks* parameter is advisory only. It does not force the track length to this size.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

After the track is open, use the
[AddAudioTrackBlocks](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-iredbookdiscmaster-addaudiotrackblocks) method to add data to the track.

## See also

[IRedbookDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-iredbookdiscmaster)