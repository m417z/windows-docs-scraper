# ITextStoreACPSink::OnStartEditTransaction

## Description

Called when an edit transaction is started.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method causes the [ITfEditTransactionSink::OnStartEditTransaction](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfedittransactionsink-onstartedittransaction) method to be called on all installed edit transaction sinks.

An edit transaction is a group of text changes that should be processed at one time. Calling this method allows a text service to queue the upcoming changes until [ITextStoreACPSink::OnEndEditTransaction](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacpsink-onendedittransaction) is called. When **ITextStoreACPSink::OnEndEditTransaction** is called, the text service will process all queued changes. Use of edit transactions is optional.

## See also

[ITextStoreACPSink](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacpsink)

[ITextStoreACPSink::OnEndEditTransaction](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacpsink-onendedittransaction)

[ITfEditTransactionSink::OnStartEditTransaction](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfedittransactionsink-onstartedittransaction)