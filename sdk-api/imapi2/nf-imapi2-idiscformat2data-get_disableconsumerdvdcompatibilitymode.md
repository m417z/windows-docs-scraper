# IDiscFormat2Data::get_DisableConsumerDvdCompatibilityMode

## Description

Determines if a DVD recording session includes tasks that can increase the chance that a device can play the DVD.

## Parameters

### `value` [out]

Is VARIANT_TRUE if the session skips the tasks that allow the disc to play on more consumer devices

Is VARIANT_FALSE if the media will be written to maximize read compatibility with consumer devices.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## Remarks

This property has no effect on CD media.

## See also

[IDiscFormat2Data](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2data)

[IDiscFormat2Data::put_DisableConsumerDvdCompatibilityMode](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-put_disableconsumerdvdcompatibilitymode)