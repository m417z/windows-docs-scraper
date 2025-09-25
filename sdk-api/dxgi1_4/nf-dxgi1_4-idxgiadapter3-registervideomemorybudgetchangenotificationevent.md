## Description

This method establishes a correlation between a CPU synchronization object and the budget change event.

## Parameters

### `hEvent` [in]

Type: **HANDLE**

A handle to the event object that the operating system sets when memory budgets change. The [CreateEvent](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-createeventa) and [OpenEvent](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-openeventa) functions return this handle.

### `pdwCookie` [out]

Type: **DWORD***

A pointer to a key value that you can pass to the [IDXGIAdapter3::UnregisterVideoMemoryBudgetChangeNotification](https://learn.microsoft.com/windows/win32/api/dxgi1_4/nf-dxgi1_4-idxgiadapter3-unregistervideomemorybudgetchangenotification) method to unregister the notification event that *hEvent* specifies.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## Remarks

Instead of calling [QueryVideoMemoryInfo](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/nf-dxgi1_4-idxgiadapter3-queryvideomemoryinfo) regularly, applications can use CPU synchronization objects to efficiently wake threads when budget changes occur.

## See also

[IDXGIAdapter3](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/nn-dxgi1_4-idxgiadapter3)