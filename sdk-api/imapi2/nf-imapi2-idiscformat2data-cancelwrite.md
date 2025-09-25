# IDiscFormat2Data::CancelWrite

## Description

Cancels the current write operation.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_IMAPI_DF2DATA_WRITE_NOT_IN_PROGRESS** | There is no write operation currently in progress.<br><br>Value: 0xC0AA0401 |
| **E_FAIL** | Unspecified failure.<br><br>Value: 0x80004005 |

## Remarks

To cancel the write operation, you must call this method from the [DDiscFormat2DataEvents::Update](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-ddiscformat2dataevents-update) event handler that you implemented.

Note that calling this method does not immediately cancel the write operation on all media due to media-specific requirements. For example, when writing to a CD, the write operation can continue for up to three more minutes.

This method leaves the media in an indeterminate state. For rewriteable media, you should call the [IDiscFormat2Erase::EraseMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2erase-erasemedia) method after calling this method to prepare the media for future use.

## See also

[DWriteEngine2Events](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-dwriteengine2events)

[IDiscFormat2Data](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2data)

[IDiscFormat2Data::Write](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-write)