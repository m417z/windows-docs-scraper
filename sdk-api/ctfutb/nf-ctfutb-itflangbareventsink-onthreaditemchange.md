# ITfLangBarEventSink::OnThreadItemChange

## Description

Called when a language bar item changes.

## Parameters

### `dwThreadId` [in]

Contains the current thread identifier. This is the same value returned from [GetCurrentThreadId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthreadid).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[GetCurrentThreadId](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthreadid)

[ITfLangBarEventSink](https://learn.microsoft.com/windows/desktop/api/ctfutb/nn-ctfutb-itflangbareventsink)