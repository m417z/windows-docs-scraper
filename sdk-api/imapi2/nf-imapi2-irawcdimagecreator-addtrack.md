# IRawCDImageCreator::AddTrack

## Description

Accepts the provided **IStream** object and saves the interface pointer as the next track in the image.

## Parameters

### `dataType` [in]

A value, defined by [IMAPI_CD_SECTOR_TYPE](https://learn.microsoft.com/windows/desktop/api/imapi2/ne-imapi2-imapi_cd_sector_type), that indicates the type of data. **IMAPI_CD_SECTOR_AUDIO** is the only value supported by the **IRawCDImageCreator::AddTrack** method.

### `data` [in, optional]

Pointer to the provided **IStream** object.

### `trackIndex` [out, retval]

A **LONG** value within a 1 to 99 range that will be associated with the new track.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

Any additional tracks must be compatible with all existing tracks. See the [IMAPI_CD_SECTOR_TYPE](https://learn.microsoft.com/windows/desktop/api/imapi2/ne-imapi2-imapi_cd_sector_type) enumeration for information on limitations.

The data stream must be at least 4 seconds (300 sectors) long. Data stream may not cause final sector to exceed LBA 398,099 (MSF 88:29:74), as leadout would then exceed the MSF 89:59:74 maximum.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IRawCDImageCreator](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagecreator)