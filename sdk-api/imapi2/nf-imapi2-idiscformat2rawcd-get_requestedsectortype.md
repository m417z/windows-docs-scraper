# IDiscFormat2RawCD::get_RequestedSectorType

## Description

Retrieves the requested data sector to use during write of the stream.

## Parameters

### `value` [out]

Requested data sector type. For possible values, see [IMAPI_FORMAT2_RAW_CD_DATA_SECTOR_TYPE](https://learn.microsoft.com/windows/win32/api/imapi2/ne-imapi2-imapi_format2_raw_cd_data_sector_type).

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_IMAPI_DF2RAW_MEDIA_IS_NOT_PREPARED** | The requested operation is only valid when media has been "prepared".<br><br>Value: 0xC0AA0602 |

## See also

[IDiscFormat2RawCD](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2rawcd)

[IDiscFormat2RawCD::get_SupportedSectorTypes](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2rawcd-get_supportedsectortypes)

[IDiscFormat2RawCD::put_RequestedSectorType](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2rawcd-put_requestedsectortype)