# IMAPI_FORMAT2_RAW_CD_DATA_SECTOR_TYPE enumeration

## Description

Defines values that indicate the type of sub-channel data.

## Constants

### `IMAPI_FORMAT2_RAW_CD_SUBCODE_PQ_ONLY:0x1`

The data contains P and Q sub-channel data.

### `IMAPI_FORMAT2_RAW_CD_SUBCODE_IS_COOKED:0x2`

The data contains corrected and de-interleaved R-W sub-channel data.

### `IMAPI_FORMAT2_RAW_CD_SUBCODE_IS_RAW:0x3`

The data contains raw P-W sub-channel data that is returned in the order received from the disc surface.

## Remarks

For details on the format of the sub-channel data, see Sub-Channel Field Formats in the latest release of the MMC specification at ftp://ftp.t10.org/t10/drafts/mmc5.

## See also

[IDiscFormat2RawCD::get_SupportedSectorTypes](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2rawcd-get_supportedsectortypes)