# IDiscFormat2RawCD::ReleaseMedia

## Description

Closes a Disc-At-Once (DAO) writing session of a raw image and releases the lock.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_IMAPI_DF2RAW_MEDIA_IS_NOT_PREPARED** | The requested operation is only valid when media has been "prepared".<br><br>Value: 0xC0AA0602 |
| **E_IMAPI_DF2RAW_WRITE_IN_PROGRESS** | There is currently a write operation in progress.<br><br>Value: 0xC0AA0600 |

## Remarks

This method release the lock set when you called the [IDiscFormat2RawCD::PrepareMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2rawcd-preparemedia) method. You must call this method after the write operation completes or after calling [IDiscFormat2RawCD::CancelWrite](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2rawcd-cancelwrite) to cancel a writing operation.

## See also

[IDiscFormat2RawCD](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2rawcd)

IDiscFormat2RawCD::CancelWrite

[IDiscFormat2RawCD::PrepareMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2rawcd-preparemedia)