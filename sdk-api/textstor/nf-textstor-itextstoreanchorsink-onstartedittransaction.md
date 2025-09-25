# ITextStoreAnchorSink::OnStartEditTransaction

## Description

Called when an edit transaction is started.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method will be called on all installed edit transaction sinks.

An edit transaction is a group of text changes that should be processed at one time. Calling this method allows a text service to queue the upcoming changes until [ITextStoreAnchorSink::OnEndEditTransaction](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchorsink-onendedittransaction) is called. When **ITextStoreAnchorSink::OnEndEditTransaction** is called, the text service will process all queued changes.

Use of edit transactions is optional.

## See also

[ITextStoreAnchorSink](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchorsink)

[ITextStoreAnchorSink::OnEndEditTransaction](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchorsink-onendedittransaction)

[ITfEditTransactionSink::OnStartEditTransaction](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfedittransactionsink-onstartedittransaction)