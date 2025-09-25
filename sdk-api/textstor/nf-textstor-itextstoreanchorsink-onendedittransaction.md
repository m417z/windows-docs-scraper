# ITextStoreAnchorSink::OnEndEditTransaction

## Description

Called when an edit transaction is terminated.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_UNEXPECTED** | The reference count of the edit transaction is incorrect. |

## Remarks

This method causes the [ITfEditTransactionSink::OnEndEditTransaction](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfedittransactionsink-onendedittransaction) method to be called on all installed edit transaction sinks.

An edit transaction is a group of text changes that should be processed at one time. Calling [ITextStoreAnchorSink::OnStartEditTransaction](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchorsink-onstartedittransaction) allows a text service to queue the upcoming changes until **ITextStoreAnchorSink::OnEndEditTransaction** is called. When **ITextStoreAnchorSink::OnEndEditTransaction** is called, the text service will process all of the queued changes.

Use of edit transactions is optional.

## See also

[ITextStoreAnchorSink](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchorsink)

[ITextStoreAnchorSink::OnStartEditTransaction](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchorsink-onstartedittransaction)

[ITfEditTransactionSink::OnEndEditTransaction](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfedittransactionsink-onendedittransaction)