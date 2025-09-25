# IDiscFormat2RawCD::put_RequestedSectorType

## Description

Sets the requested data sector to use for writing the stream.

## Parameters

### `value` [in]

Data sector to use for writing the stream. For possible values, see the [IMAPI_FORMAT2_RAW_CD_DATA_SECTOR_TYPE](https://learn.microsoft.com/windows/win32/api/imapi2/ne-imapi2-imapi_format2_raw_cd_data_sector_type) enumeration type. The default is **IMAPI_FORMAT2_RAW_CD_SUBCODE_IS_COOKED**.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_IMAPI_DF2RAW_WRITE_IN_PROGRESS** | There is currently a write operation in progress.<br><br>Value: 0xC0AA0600 |
| **E_IMAPI_DF2RAW_MEDIA_IS_NOT_PREPARED** | The requested operation is only valid when media has been "prepared".<br><br>Value: 0xC0AA0602 |
| **E_IMAPI_DF2RAW_DATA_BLOCK_TYPE_NOT_SUPPORTED** | The requested data block type is not supported by the current device.<br><br>Value: 0xC0AA060E |

## Remarks

For a list of supported data sector types, call the [IDiscFormat2RawCD::get_SupportedSectorTypes](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2rawcd-get_supportedsectortypes) method.

## See also

[IDiscFormat2RawCD](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2rawcd)

[IDiscFormat2RawCD::get_RequestedSectorType](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2rawcd-get_requestedsectortype)

[IDiscFormat2RawCD::get_SupportedSectorTypes](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2rawcd-get_supportedsectortypes)