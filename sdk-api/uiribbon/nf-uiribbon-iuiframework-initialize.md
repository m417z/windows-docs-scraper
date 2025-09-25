# IUIFramework::Initialize

## Description

Connects the host application to the Windows Ribbon framework.

## Parameters

### `frameWnd` [in]

Type: **HWND**

Handle to the top-level window that will contain the Ribbon.

### `application` [in]

Type: **[IUIApplication](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiapplication)***

Pointer to the IUIApplication implementation of the host application.

## Return value

Type: **HRESULT**

Returns S_OK if successful; otherwise, an error value from the following list.

| Value | Description |
| --- | --- |
| HRESULT_FROM_WIN32(ERROR_INVALID_WINDOW_HANDLE) | *frameWnd* is **NULL**, does not point to an existing window, or is not a top-level window of the desktop.<br><br>**Note** This error is also returned if *frameWnd* is a child window (WS_CHILD), is declared as a tool window (WS_EX_TOOLWINDOW), or it lacks a caption property (WS_CAPTION is mandatory). |
| HRESULT_FROM_WIN32(ERROR_WINDOW_OF_OTHER_THREAD) | *frameWnd* is not owned by the execution thread. |
| E_POINTER | *application* is **NULL** or an invalid pointer. |

## Remarks

This method must be called by the host application for each top-level window that requires a ribbon.

This method is used to set up the hooks that enable the Ribbon framework to invoke callbacks in the host application.

To initialize the Ribbon successfully, a compiled Ribbon markup file must be available as a resource and specified in a subsequent call to [IUIFramework::LoadUI](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiframework-loadui). This markup file is an integral component of the framework; it specifies the controls to be used and their layout.

If **IUIFramework::Initialize** returns successfully:

* To eliminate inconsistency, redundancy, and incompatibility between Ribbon and traditional command models, the Ribbon framework removes the standard menu bar of the top-level window in the host application.
* The framework removes references to the WS_EX_CLIENTEDGE style.

  **Note** The WS_EX_CLIENTEDGE style specifies that a window has a border with a sunken edge. This style visually interferes with the integration of the Ribbon and the host application.
* The framework requires that the WS_SYSMENU style be enabled. If WS_SYSMENU is not enabled, the framework does not provide alternate functionality and unpredictable rendering of the Ribbon may result.

  **Note** The WS_SYSMENU style specifies that the application window has a system menu on its title bar. By association, the WS_CAPTION style must also be specified (see ERROR_INVALID_WINDOW_HANDLE in **Return Values** above).

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

[IUIFramework](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiframework)

[IUIFramework::LoadUI](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiframework-loadui)

[Markup Elements](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-markup-elements)

[Windows Ribbon Framework Samples](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-samples-entry)