# IDropTargetProvider::get_DropTargetEffect

## Description

Retrieves a localized string that describes the effect that happens when the user drops the grabbed element on this drop target.

This property is read-only.

## Parameters

## Remarks

This property describes the default effect that happens when the user drops a grabbed element on a target, such as moving or copying the element. This property can be a short string such as "move", or a longer one such as "insert into Main group". The string is always localized.

If this property changes, the provider must notify clients by firing a [UIA_AutomationPropertyChangedEventId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids) event.

#### Examples

```cpp
IFACEMETHODIMP CRegionProvider::get_DropTargetEffect(BSTR * pDefaultDropAction)
{
    WCHAR wszDropAction[100];
    LoadString(g_hInstance, IDS_REGION_DEFAULTDROPACTION1, wszDropAction,
        ARRAYSIZE(wszDropAction));
    *pDefaultDropAction = ::SysAllocString(wszDropAction);
    return (*pDefaultDropAction == nullptr) ? E_OUTOFMEMORY : S_OK;
}

```

## See also

[IDropTargetProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-idroptargetprovider)