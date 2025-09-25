# IUIAutomationProxyFactoryMapping::InsertEntry

## Description

Insert an entry into the table of proxy factories.

## Parameters

### `before` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The zero-based index at which to insert the entry.

### `factory` [in]

Type: **[IUIAutomationProxyFactoryEntry](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationproxyfactoryentry)***

The address of the entry to insert.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.