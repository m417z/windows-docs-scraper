# UiaRaiseAsyncContentLoadedEvent function

## Description

Called by a provider to notify the Microsoft UI Automation core that content is being loaded asynchronously.

## Parameters

### `pProvider` [in]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)***

The provider node where the content is being loaded.

### `asyncContentLoadedState` [in]

Type: **[AsyncContentLoadedState](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ne-uiautomationcoreapi-asynccontentloadedstate)**

The current state of loading.

### `percentComplete` [in]

Type: **double**

The percentage of content that has been loaded.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.