# IRawCDImageTrackInfo::get_TrackNumber

## Description

Retrieves the track number for this track.

## Parameters

### `value` [out]

The track number for this track.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

While this value is often identical to the **TrackIndex** property, it is possible for pure audio discs to start with a track other than track number 1. This means that the more general formula is that this value is ( TrackIndex + FirstTrackNumber - 1).

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IRawCDImageTrackInfo](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagetrackinfo)