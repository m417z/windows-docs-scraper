# ITextStoreACPSink::OnEndEditTransaction

## Description

Called when an edit transaction is terminated.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method causes the [ITfEditTransactionSink::OnEndEditTransaction](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfedittransactionsink-onendedittransaction) method to be called on all installed edit transaction sinks.

An edit transaction is a group of text changes that should be processed at one time. Calling [ITextStoreACPSink::OnStartEditTransaction](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacpsink-onstartedittransaction) allows a text service to queue the upcoming changes until **ITextStoreACPSink::OnEndEditTransaction** is called. When **ITextStoreACPSink::OnEndEditTransaction** is called, the text service will process all of the queued changes. Use of edit transactions is optional.

## See also

[ITextStoreACPSink](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacpsink)

[ITextStoreACPSink::OnStartEditTransaction](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacpsink-onstartedittransaction)

[ITfEditTransactionSink::OnEndEditTransaction](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfedittransactionsink-onendedittransaction)