# IUIAutomationProxyFactoryMapping::GetEntry

## Description

Retrieves an entry from the proxy factory table.

## Parameters

### `index` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The zero-based index of the item to retrieve.

### `entry` [out, retval]

Type: **[IUIAutomationProxyFactoryEntry](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationproxyfactoryentry)****

Receives a pointer to the entry.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.