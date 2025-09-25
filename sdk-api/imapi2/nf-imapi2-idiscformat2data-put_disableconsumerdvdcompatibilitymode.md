# IDiscFormat2Data::put_DisableConsumerDvdCompatibilityMode

## Description

Determines if a DVD recording session includes tasks that can increase the chance that a device can play the DVD.

## Parameters

### `value` [in]

Set to VARIANT_TRUE to skip the tasks that allow the disc to play on more consumer devices. Removing compatibility reduces the recording session time and the need for less free space on disc.

Set to VARIANT_FALSE to increase the chance that a device can play the DVD. The default is VARIANT_FALSE.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_IMAPI_DF2DATA_WRITE_IN_PROGRESS** | There is currently a write operation in progress.<br><br>Value: 0xC0AA0400 |

## Remarks

This property has no effect on CD media and DVD dash media.

For DVD+R and DVD+DL media, this property will also affect the media closing operation.

| Value of DisableConsumerDvdCompatibilityMode | Value of ForceMediaToBeClosed | Closure operation |
| --- | --- | --- |
| False | True | Closes the disc in compatible mode |
| False | False | Closes the disc in compatible mode |
| True | True | Closes the disc normally |
| True | False | Closes the session for DVD+R Closes disc normally for DVD+R DL |

## See also

[IDiscFormat2Data](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2data)

[IDiscFormat2Data::get_DisableConsumerDvdCompatibilityMode](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-get_disableconsumerdvdcompatibilitymode)