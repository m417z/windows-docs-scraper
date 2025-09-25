# IDockProvider::get_DockPosition

## Description

Indicates the current docking position of this element.

This property is read-only.

## Parameters

## Remarks

A docking container is a control that allows the arrangement of child elements, both horizontally and vertically, relative to the boundaries of the docking container and other elements in the container.

#### Examples

The following example shows how to return the DockPosition property.

```cpp

    // dockPosition is a global variable of type DockPosition.

    HRESULT STDMETHODCALLTYPE BucketControl::get_DockPosition(DockPosition *pRetVal)
    {
        if (pRetVal == NULL)
        {
            return E_INVALIDARG;
        }
        *pRetVal = dockPosition;
        return S_OK;
    }

```

## See also

[IDockProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-idockprovider)

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)