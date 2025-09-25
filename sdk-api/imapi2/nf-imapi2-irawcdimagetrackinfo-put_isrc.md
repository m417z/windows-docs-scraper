# IRawCDImageTrackInfo::put_ISRC

## Description

Sets the International Standard Recording Code (ISRC) currently associated with the track. This property value defaults to **NULL** (or a zero-length string) and may only be set for tracks containing audio data.

## Parameters

### `value` [in]

The ISRC to associate with the track.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

 The format of the ISRC is provided to the caller formatted per ISRC standards (DIN-31-621) recommendations, such as "US-K7Y-98-12345". When set, the provided string may optionally exclude all the '-' characters.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IRawCDImageTrackInfo](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagetrackinfo)