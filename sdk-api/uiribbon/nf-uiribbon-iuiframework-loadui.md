# IUIFramework::LoadUI

## Description

Loads the Windows Ribbon framework UI resource, or compiled markup, file.

## Parameters

### `instance` [in]

Type: **HINSTANCE**

A handle to the Ribbon application instance.

### `resourceName` [in]

Type: **LPCWSTR**

The name of the resource that contains the compiled, binary markup.

**Note** To initialize the Ribbon successfully, a compiled Ribbon markup file must be available as a resource. This markup file is an integral component of the Ribbon framework; it specifies the controls to use and their layout.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IUIFramework::LoadUI** should be called upon initialization. This method can be called multiple times during the lifecycle of an application, for example, to show or hide a Ribbon, provided that [IUIFramework::Destroy](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiframework-destroy) is called in between.

[OnCreateUICommand](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiapplication-oncreateuicommand) and [OnViewChanged](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiapplication-onviewchanged)
are called during the execution of **IUIFramework::LoadUI**.

#### Examples

The following example demonstrates a basic framework initialization function.

```cpp
//
//  FUNCTION:    InitializeFramework(HWND)
//
//  PURPOSE:    Initialize the Ribbon framework and bind a Ribbon to the application.
//
//  PARAMETERS:
//                hWnd - Handle to the Ribbon host application window.
//
//  COMMENTS:
//
//    In order to get a Ribbon to display, the Ribbon framework must be initialized.
//    This involves three important steps:
//      1) Instantiate the Ribbon framework object (CLSID_UIRibbonFramework).
//      2) Pass the host HWND and IUIApplication object to the framework.
//      3) Load the binary markup compiled by the UI Command Compiler (UICC.exe).
//
//
bool InitializeFramework(HWND hWnd)
{
    // Instantiate the Ribbon framework object.
    HRESULT hr = CoCreateInstance(
        CLSID_UIRibbonFramework,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_PPV_ARGS(&g_pFramework));
    if (!SUCCEEDED(hr))
    {
        return false;
    }

    // Create the application object (IUIApplication) and call the
    // framework Initialize method, passing the application object and the
    // host HWND that the Ribbon will attach itself to.
    CComObject<CApplication> *pApplication = NULL;
    CComObject<CApplication>::CreateInstance(&pApplication);
    hr = pApplication->QueryInterface(&g_pApplication);
    if (!SUCCEEDED(hr))
    {
        return false;
    }

    hr = g_pFramework->Initialize(hWnd, g_pApplication);
    if (!SUCCEEDED(hr))
    {
        return false;
    }

    // Load the binary markup.
    // Initiate callbacks to the IUIApplication object that was
    // provided to the framework earlier and bind command handler(s)
    // to individual commands.
    hr = g_pFramework->LoadUI(GetModuleHandle(NULL), L"APPLICATION_RIBBON");
    if (!SUCCEEDED(hr))
    {
        return false;
    }
    return true;
}

```

## See also

[Compiling Ribbon Markup](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-intentcl)

[IUIFramework](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiframework)

[IUIFramework::Initialize](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiframework-initialize)

[Markup Elements](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-markup-elements)

[Windows Ribbon Framework Samples](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-samples-entry)