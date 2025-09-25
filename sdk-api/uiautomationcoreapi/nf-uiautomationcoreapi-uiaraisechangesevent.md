# UiaRaiseChangesEvent function

## Description

Called by providers to notify the Microsoft UI Automation core that a change has occurred.

## Parameters

### `pProvider` [in]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)***

The provider node where the change event occurred.

### `eventIdCount` [in]

The number of changes that occurred. This is the number of [UiaChangeInfo](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ns-uiautomationcore-uiachangeinfo) structures pointed to by the *pUiaChanges* parameter.

### `pUiaChanges` [in]

A collection of pointers to [UiaChangeInfo](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ns-uiautomationcore-uiachangeinfo) structures.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) value indicating success or failure.