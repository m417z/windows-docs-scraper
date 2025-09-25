# IRawElementProviderFragmentRoot::ElementProviderFromPoint

## Description

Retrieves the provider of the element that is at the specified point in this fragment.

## Parameters

### `x` [in]

Type: **double**

The horizontal screen coordinate.

### `y` [in]

Type: **double**

The vertical screen coordinate.

### `pRetVal` [out, retval]

Type: **[IRawElementProviderFragment](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementproviderfragment)****

Receives a pointer to the provider of the element at (x, y), or **NULL** if none exists. This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The returned provider should correspond to the element that would receive mouse input at the specified point.

If the point is on this element but not on any child element, either **NULL** or the provider of the fragment root is returned. If the point is on an element in another framework that is hosted by this fragment, the method returns the element that hosts that fragment (as indicated by [IRawElementProviderFragment::GetEmbeddedFragmentRoots](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-irawelementproviderfragment-getembeddedfragmentroots)).

#### Examples

The following example shows an implementation for a list box hosted in an **HWND**
whose handle is *m_controlHwnd*.
IndexFromY retrieves the index of the list item at the cursor position,
and GetItemByIndex retrieves
the UI Automation provider for that item.

```cpp
HRESULT STDMETHODCALLTYPE ListProvider::ElementProviderFromPoint(double x, double y, IRawElementProviderFragment** pRetVal)
{
    if (pRetVal == NULL)
    {
        return E_INVALIDARG;
    }
    POINT pt;
    pt.x = (LONG)x;
    pt.y = (LONG)y;
    ScreenToClient(m_controlHwnd, &pt);
    int itemIndex = this->m_pControl->IndexFromY(m_controlHwnd, pt.y);
    ListItemProvider* pItem = GetItemByIndex(itemIndex);
    if (pItem != NULL)
    {
        *pRetVal = (IRawElementProviderFragment*)pItem;
        pItem->AddRef();
    }
    else
    {
        pRetVal = (IRawElementProviderFragment*)this;
        pItem->AddRef();
    }

    return S_OK;
}
```

## See also

[IRawElementProviderFragmentRoot](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementproviderfragmentroot)