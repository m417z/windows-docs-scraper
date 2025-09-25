# IRawElementProviderFragment::get_BoundingRectangle

## Description

Specifies the bounding rectangle of this element.

This property is read-only.

## Parameters

## Remarks

The bounding rectangle is defined by the location of the top left corner on the screen, and the dimensions.

No clipping is required if the element is partly obscured or partly off-screen. The IsOffscreen property should be set to indicate whether the rectangle is actually visible.

Not all points within the bounding rectangle are necessarily clickable.

#### Examples

The following example implementation by a list item provider calculates the bounding rectangle for the item
based on its height and position within the containing list box.

```cpp
HRESULT STDMETHODCALLTYPE ListItemProvider::get_BoundingRectangle(UiaRect * pRetVal)
{
    if (pRetVal == NULL) return E_INVALIDARG;

    UiaRect parentRect;
    HRESULT hr = m_parentProvider->get_BoundingRectangle(&parentRect);
    pRetVal->left = parentRect.left;
    pRetVal->top = parentRect.top + (m_pParentControl->m_itemHeight * m_itemIndex);
    pRetVal->width = parentRect.width;
    pRetVal->height = m_pParentControl->m_itemHeight;
    return S_OK;
}
```

## See also

[IRawElementProviderFragment](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementproviderfragment)