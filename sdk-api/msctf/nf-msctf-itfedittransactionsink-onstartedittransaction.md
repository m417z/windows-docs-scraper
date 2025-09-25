# ITfEditTransactionSink::OnStartEditTransaction

## Description

Indicates the start of an edit transaction.

## Parameters

### `pic` [in]

Pointer to the [ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext) interface involved in the transaction.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The TSF manager calls this method at the start of an edit transaction. A text service might delay reevaluation of the changing context of the transaction due to the multiple [ITfTextEditSink::OnEndEdit](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itftexteditsink-onendedit) notifications until after receiving the corresponding [ITfEditTransactionSink::OnEndEditTransaction](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfedittransactionsink-onendedittransaction) callback.

## See also

[ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext)

[ITfEditTransactionSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfedittransactionsink)

[ITfEditTransactionSink::OnEndEditTransaction](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfedittransactionsink-onendedittransaction)

[ITfTextEditSink::OnEndEdit](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itftexteditsink-onendedit)