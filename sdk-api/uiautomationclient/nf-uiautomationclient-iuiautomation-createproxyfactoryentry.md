# IUIAutomation::CreateProxyFactoryEntry

## Description

Creates a new instance of a proxy factory object.

## Parameters

### `factory` [in]

Type: **[IUIAutomationProxyFactory](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationproxyfactory)***

A pointer to the proxy factory object.

### `factoryEntry` [out, retval]

Type: **[IUIAutomationProxyFactoryEntry](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationproxyfactoryentry)****

Receives a pointer to the newly created instance of the proxy factory object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Use the [IUIAutomationProxyFactoryMapping](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationproxyfactorymapping) interface to enter the proxy factory into the table of available proxies.

## See also

[IUIAutomation](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation)