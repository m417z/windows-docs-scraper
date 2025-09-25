# ITfCompositionSink::OnCompositionTerminated

## Description

Called when a composition is terminated.

## Parameters

### `ecWrite` [in]

Contains a [TfEditCookie](https://learn.microsoft.com/windows/desktop/TSF/tfeditcookie) value that identifies the edit context. This is the same value passed for *ecWrite* in the call to [ITfContextComposition::StartComposition](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextcomposition-startcomposition).

### `pComposition` [in]

Pointer to the [ITfComposition](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcomposition) object terminated.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

There is no required action for the TSF text service when this method is called. The TSF text service can use this notification to revert partially composed text into readable text or erase the composition entirely. The TSF manager will automatically clear the GUID_PROP_COMPOSING property value over the affected text.

## See also

[ITfComposition interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcomposition), [ITfCompositionSink interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcompositionsink), [ITfContextComposition::StartComposition](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcontextcomposition-startcomposition), [TfEditCookie](https://learn.microsoft.com/windows/desktop/TSF/tfeditcookie)