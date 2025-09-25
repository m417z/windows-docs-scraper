# IDXGIAdapter3::UnregisterVideoMemoryBudgetChangeNotification

## Description

This method stops notifying a CPU synchronization object whenever a budget change occurs. An application may switch back to polling the information regularly.

## Parameters

### `dwCookie` [in]

Type: **DWORD**

A key value for the window or event to unregister. The [IDXGIAdapter3::RegisterHardwareContentProtectionTeardownStatusEvent](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/nf-dxgi1_4-idxgiadapter3-registerhardwarecontentprotectionteardownstatusevent) method returns this value.

## Remarks

An application may switch back to polling for the information regularly.

## See also

[IDXGIAdapter3](https://learn.microsoft.com/windows/desktop/api/dxgi1_4/nn-dxgi1_4-idxgiadapter3)