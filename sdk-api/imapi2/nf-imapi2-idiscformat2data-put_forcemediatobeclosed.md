# IDiscFormat2Data::put_ForceMediaToBeClosed

## Description

Determines if further additions to the file system are prevented.

## Parameters

### `value` [in]

Set to VARIANT_TRUE to mark the disc as closed to prohibit additional writes when the next write session ends.

Set to VARIANT_FALSE to keep the disc open for subsequent write sessions. The default is VARIANT_FALSE.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_IMAPI_DF2DATA_WRITE_IN_PROGRESS** | There is currently a write operation in progress.<br><br>Value: 0xC0AA0400 |

## Remarks

When the free space on a disc reaches 2% or less, the write process marks the disc closed, regardless of the value of this property. This action ensures that a disc has enough free space to record a file system in a write session.

You can erase a rewritable disc that is marked closed.

Note that the [IDiscFormat2Data::put_DisableConsumerDvdCompatibilityMode](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-put_disableconsumerdvdcompatibilitymode) property may supersede this property. Please refer to **put_DisableConsumerDvdCompatibilityMode** for details.

## See also

[IDiscFormat2Data](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2data)

[IDiscFormat2Data::get_ForceMediaToBeClosed](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-get_forcemediatobeclosed)