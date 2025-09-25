# IRawCDImageCreator::AddSpecialPregap

## Description

Accepts the provided **IStream** object and saves the associated pointer to be used as data for the pre-gap for track 1.

## Parameters

### `data` [in, optional]

Pointer to the provided **IStream** object.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

This method can only be called prior to adding any tracks to the image. The *data* stream must be at least 2 seconds (or 150 sectors) long.

The *data* stream should not result final sector exceeding LBA 397,799 (MSF 88:25:74), as the minimal-sized track plus leadout would then exceed the MSF 89:59:74 maximum. Additionally, it is recommended that the [IMAPI_CD_SECTOR_TYPE](https://learn.microsoft.com/windows/desktop/api/imapi2/ne-imapi2-imapi_cd_sector_type) value for the first track is implicitly defined as "Audio". The resulting audio can then only be heard by playing the first track and "rewinding" back to the start of the audio disc.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IRawCDImageCreator](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagecreator)