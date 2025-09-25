# IUIAutomationPatternHandler::CreateClientWrapper

## Description

Creates an object that enables a client application to interact with a custom *control pattern*.

## Parameters

### `pPatternInstance` [in]

Type: **[IUIAutomationPatternInstance](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iuiautomationpatterninstance)***

A pointer to the instance of the control pattern that will be used by the wrapper.

### `pClientWrapper` [out, retval]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

Receives a pointer to the wrapper object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The wrapper object exposes methods and properties of the *control pattern*. The implementation of the wrapper class passes these calls to Microsoft UI Automation by calling [CallMethod](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-iuiautomationpatterninstance-callmethod) and [GetProperty](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-iuiautomationpatterninstance-getproperty).

## See also

[IUIAutomationPatternHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iuiautomationpatternhandler)