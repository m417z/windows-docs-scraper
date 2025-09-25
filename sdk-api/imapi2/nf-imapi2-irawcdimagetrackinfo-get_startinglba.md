# IRawCDImageTrackInfo::get_StartingLba

## Description

Retrieves the LBA of the first user sectors in this track.

## Parameters

### `value` [out]

The LBA of the first user sectors in this track.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

 Most tracks also include a pregap and postgap, which are not included in this value.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IRawCDTrackInfo](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagetrackinfo)