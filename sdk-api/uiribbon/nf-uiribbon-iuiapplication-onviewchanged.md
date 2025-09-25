# IUIApplication::OnViewChanged

## Description

Called when the state of a [View](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-application-views) changes.

## Parameters

### `viewId` [in]

Type: **UINT32**

The ID for the View.
Only a value of 0 is valid.

### `typeID` [in]

Type: **[UI_VIEWTYPE](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_viewtype)**

The [UI_VIEWTYPE](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_viewtype) hosted by the application.

### `view` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the View interface.

### `verb` [in]

Type: **[UI_VIEWVERB](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_viewverb)**

The [UI_VIEWVERB](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_viewverb) (or action) performed by the View.

### `uReasonCode` [in]

Type: **INT32**

Not defined.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This callback notification is sent by the framework to the host application on each View state change.

**Important** This callback only occurs for the [Ribbon View](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-ribbon) with a *viewId* of 0.

**IUIApplication::OnViewChanged** is useful for initializing Ribbon properties when the host application starts, modifying Ribbon properties based on user actions, such as resizing the application window, and querying Ribbon properties when the application closes.

#### Examples

The following example demonstrates a basic implementation of the **IUIApplication::OnViewChanged** method.

```cpp
//
//  FUNCTION: OnViewChanged(UINT, UI_VIEWTYPE, IUnknown*, UI_VIEWVERB, INT)
//
//  PURPOSE: Called when the state of a View (Ribbon is a view) changes - like created/destroyed/resized.
//
//  PARAMETERS:
//                viewId - The View identifier.
//                typeID - The View type.
//                pView - Pointer to the View interface.
//                verb - The action performed by the View.
//                uReasonCode - Not defined.
//
//  COMMENTS:
//
//    For this sample, return the same command handler for all commands
//    specified in the .xml file.
//
//
STDMETHODIMP CApplication::OnViewChanged(
    UINT viewId,
    UI_VIEWTYPE typeId,
    IUnknown* pView,
    UI_VIEWVERB verb,
    INT uReasonCode)
{
    HRESULT hr = E_NOTIMPL;

    // Checks to see if the view that was changed was a Ribbon view.
    if (UI_VIEWTYPE_RIBBON == typeId)
    {
        switch (verb)
        {
            // The view was newly created.
            case UI_VIEWVERB_CREATE:
                _cwprintf(L"IUIApplication::OnViewChanged called with verb=CREATE\r\n");

                if (NULL == g_pRibbon)
                {
                    // Retrieve and store the IUIRibbon
                    hr = pView->QueryInterface(&g_pRibbon);
                }
                break;

            // The view was resized.
            // In the case of the Ribbon view, the application should call
            // GetHeight() to determine the height of the Ribbon.
            case UI_VIEWVERB_SIZE:
                _cwprintf(L"IUIApplication::OnViewChanged called with verb=SIZE\r\n");
                // Call to the framework to determine the height of the Ribbon.
                if (NULL != g_pRibbon)
                {
                    UINT uRibbonHeight;
                    hr = g_pRibbon->GetHeight(&uRibbonHeight);
                }
                if (!SUCCEEDED(hr))
                {
                    //_cwprintf(L"IUIRibbon::GetHeight() failed with hr=0x%X\r\n", hr);
                }
                break;

            // The view was destroyed.
            case UI_VIEWVERB_DESTROY:
                //_cwprintf(L"IUIApplication::OnViewChanged called with verb=DESTROY\r\n");
                g_pRibbon = NULL;
                hr = S_OK;
                break;
        }
    }
    return hr;
}

```

## See also

[IUIApplication](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiapplication)

[Windows Ribbon Framework Samples](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-samples-entry)