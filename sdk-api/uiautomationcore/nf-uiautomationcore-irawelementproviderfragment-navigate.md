# IRawElementProviderFragment::Navigate

## Description

Retrieves the Microsoft UI Automation element in a specified direction within the UI Automation tree.

## Parameters

### `direction` [in]

Type: **[NavigateDirection](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-navigatedirection)**

The direction in which to navigate.

### `pRetVal` [out, retval]

Type: **[IRawElementProviderFragment](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementproviderfragment)****

Receives a pointer to the provider of the
UI Automation element in the specified direction, or **NULL** if there is no element in that direction.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The UI Automation server's implementations of this method define the structure of the UI Automation tree.

Navigation must be supported upward to the parent, downward to the first and last child, and laterally to the next and previous siblings, as applicable.

Each child node has only one parent and must be placed in the chain of siblings reached from the parent by **NavigateDirection_FirstChild** and **NavigateDirection_LastChild**.

Relationships among siblings must be identical in both directions: if A is B's previous sibling (**NavigateDirection_PreviousSibling**), then B is A's next sibling (**NavigateDirection_NextSibling**). A first child (**NavigateDirection_FirstChild**) has no previous sibling, and a last child (**NavigateDirection_LastChild**) has no next sibling.

Fragment roots do not enable navigation to a parent or siblings; navigation among fragment roots is handled by the default window providers. Elements in fragments must navigate only to other elements within that fragment.

#### Examples

The following example shows an implementation for a list item provider. The member variables for the parent,
previous sibling, and next sibling providers were initialized when the list was created.

```cpp
HRESULT STDMETHODCALLTYPE ListItemProvider::Navigate(NavigateDirection direction, IRawElementProviderFragment ** pRetVal)
{
    if (pRetVal == NULL)
    {
        return E_INVALIDARG;
    }

    IRawElementProviderFragment* pFrag = NULL;
    switch(direction)
    {
        case NavigateDirection_Parent:
            pFrag = (IRawElementProviderFragment*)m_parentProvider;
            break;

        case NavigateDirection_NextSibling:
            pFrag = (IRawElementProviderFragment*)m_nextSiblingProvider;
            break;

        case NavigateDirection_PreviousSibling:
            pFrag = (IRawElementProviderFragment*)m_previousSiblingProvider;
            break;
    }
    *pRetVal = pFrag;
    if (pFrag != NULL)
    {
        pFrag->AddRef();
    }
    return S_OK;
}
```

## See also

[IRawElementProviderFragment](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementproviderfragment)