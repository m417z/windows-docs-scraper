# ITfEditTransactionSink::OnEndEditTransaction

## Description

Indicates the end of an edit transaction.

## Parameters

### `pic` [in]

Pointer to the [ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext) interface involved in the transaction.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The TSF manager calls this method at the end of an edit transaction. A text service can delay reevaluation of the changing context of the transaction due to the multiple [ITfTextEditSink::OnEndEdit](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itftexteditsink-onendedit) method notifications until after receiving this callback.

## See also

[ITfContext](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcontext)

[ITfEditTransactionSink](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfedittransactionsink)

[ITfTextEditSink::OnEndEdit](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itftexteditsink-onendedit)