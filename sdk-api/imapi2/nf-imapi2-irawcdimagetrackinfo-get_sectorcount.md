# IRawCDImageTrackInfo::get_SectorCount

## Description

Retrieves the number of user sectors in this track.

## Parameters

### `value` [out]

The number of user sectors in this track.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

The end of the track is typically the **StartingLBA** plus the **SectorCount**. The start of the next track includes both of these properties plus any required pregap or postgap.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IRawCDImageTrackInfo](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagetrackinfo)