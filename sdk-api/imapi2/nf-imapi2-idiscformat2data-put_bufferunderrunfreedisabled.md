# IDiscFormat2Data::put_BufferUnderrunFreeDisabled

## Description

Determines if Buffer Underrun Free recording is enabled.

**Note** This method is only applicable to CDR/RW and DVD+/-R media formats.

## Parameters

### `value` [in]

Set to VARIANT_TRUE to disable Buffer Underrun Free recording; otherwise, VARIANT_FALSE. The default is VARIANT_FALSE (enabled).

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_IMAPI_DF2DATA_WRITE_IN_PROGRESS** | There is currently a write operation in progress.<br><br>Value: 0xC0AA0400 |

## Remarks

Buffer underrun can be an issue if the data stream does not enter the buffer fast enough to keep the device continuously writing. In turn, the stop and start action of writing can cause data on the disc to be unusable. Buffer Underrun Free (BUF) recording allows the laser to start and stop without damaging data already written to the disc. Disabling of BUF recording is possible only on CD-R/RW media.

## See also

[IDiscFormat2Data,IDiscFormat2Data::get_BufferUnderrunFreeDisabled](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2data)