# IWSDAsyncResult::SetWaitHandle

## Description

Specifies a wait handle to set when the operation completes.

## Parameters

### `hWaitHandle` [in]

The wait handle to set.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *hWaitHandle* is **NULL**. |
| **E_FAIL** | The method failed. |

## Remarks

Do not close *hWaitHandle* until after the asynchronous operation has completed.

## See also

[IWSDAsyncResult](https://learn.microsoft.com/windows/desktop/api/wsdclient/nn-wsdclient-iwsdasyncresult)