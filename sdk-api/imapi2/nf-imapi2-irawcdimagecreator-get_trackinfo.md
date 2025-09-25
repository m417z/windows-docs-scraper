# IRawCDImageCreator::get_TrackInfo

## Description

Retrieves an indexed property, which takes a **LONG** value with a range of 1 to 99 as the index to determine which track the user is querying. The returned object is then queried/set for the particular per-track property of interest.

## Parameters

### `trackIndex` [in]

A **LONG** value within a 1 to 99 range that is used to specify which track is queried.

### `value` [out]

A pointer to a pointer to an [IRawCDImageTrackInfo](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagetrackinfo) object that contains information about the track associated with the specified *trackInfo* index value.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IRawCDImageCreator](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagecreator)