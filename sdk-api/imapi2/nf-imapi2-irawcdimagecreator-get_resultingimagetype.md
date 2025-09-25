# IRawCDImageCreator::get_ResultingImageType

## Description

Retrieves the value that specifies the type of image file that will be generated.

## Parameters

### `value` [out]

Pointer to an [IMAPI_FORMAT2_RAW_CD_DATA_SECTOR_TYPE](https://learn.microsoft.com/windows/win32/api/imapi2/ne-imapi2-imapi_format2_raw_cd_data_sector_type) enumeration that defines the current type set for the image file.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IRawCDImageCreator](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagecreator)

[IRawCDImageCreator::put_ResultingImageType](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-irawcdimagecreator-put_resultingimagetype)