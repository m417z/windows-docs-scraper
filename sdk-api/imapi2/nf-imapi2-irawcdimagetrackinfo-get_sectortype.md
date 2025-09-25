# IRawCDImageTrackInfo::get_SectorType

## Description

Retrieves the type of data provided for the sectors in this track. For more detail on the possible sector types, see [IMAPI_CD_SECTOR_TYPE](https://learn.microsoft.com/windows/desktop/api/imapi2/ne-imapi2-imapi_cd_sector_type).

## Parameters

### `value` [out]

A pointer to a [IMAPI_CD_SECTOR_TYPE](https://learn.microsoft.com/windows/desktop/api/imapi2/ne-imapi2-imapi_cd_sector_type) enumeration that specifies the type of data provided for the sectors on the track.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IMAPI_CD_SECTOR_TYPE](https://learn.microsoft.com/windows/desktop/api/imapi2/ne-imapi2-imapi_cd_sector_type)

[IRawCDImageTrackInfo](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagetrackinfo)