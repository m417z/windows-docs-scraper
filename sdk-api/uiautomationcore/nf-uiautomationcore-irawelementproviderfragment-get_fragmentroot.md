# IRawElementProviderFragment::get_FragmentRoot

## Description

Specifies the root node of the fragment.

This property is read-only.

## Parameters

## Remarks

A provider for a fragment root should return a pointer to its own implementation of
[IRawElementProviderFragmentRoot](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementproviderfragmentroot).

#### Examples

The following example implementation for a list item provider returns the provider for the parent list box.

```cpp
HRESULT STDMETHODCALLTYPE ListItemProvider::get_FragmentRoot(IRawElementProviderFragmentRoot** pRetVal)
{
    if (pRetVal == NULL) return E_INVALIDARG;
    IRawElementProviderFragmentRoot* pRoot = static_cast<IRawElementProviderFragmentRoot*>(m_parentProvider);
    pRoot->AddRef();
    *pRetVal = pRoot;
    return S_OK;
}
```

## See also

[IRawElementProviderFragment](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementproviderfragment)