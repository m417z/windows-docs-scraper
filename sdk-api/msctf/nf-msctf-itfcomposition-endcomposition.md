# ITfComposition::EndComposition

## Description

Terminates a composition.

## Parameters

### `ecWrite` [in]

Contains an edit cookie that identifies the edit context obtained from [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_UNEXPECTED** | This value results when:<br><br>* The composition terminated.<br>* The caller is inside another composition write operation.<br>* The caller does not own the composition. |
| **TF_E_NOLOCK** | The edit context identified by *ecWrite* does not have a read/write lock. |

## Remarks

This method does not release the composition object, but the [ITfComposition](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfcomposition) methods will fail with E_UNEXPECTED after this method is called.

Context owners should use the [ITFContextOwnerCompositionServices::TerminateComposition](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfcontextownercompositionservices-terminatecomposition) method to terminate a composition.

This method causes the GUID_PROP_COMPOSING property to be removed from the text covered by the composition.

## See also

[ITfContextOwnerCompositionServices::TerminateComposition](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfcontextownercompositionservices-terminatecomposition), [ITfComposition interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcomposition), [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/win32/api/msctf/nf-msctf-itfeditsession-doeditsession)