# IUIFramework::Destroy

## Description

Terminates and releases all objects, hooks, and references for an instance of the Windows Ribbon framework.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method must be called once for each instance of [IUIFramework](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiframework).

If [IUIFramework::Initialize](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiframework-initialize) was called, then **IUIFramework::Destroy** must be called to free resources and ensure proper dismantling of the framework. Failure to call **IUIFramework::Destroy** may cause a memory leak.

## See also

[IUIFramework](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiframework)

[Windows Ribbon Framework Samples](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-samples-entry)