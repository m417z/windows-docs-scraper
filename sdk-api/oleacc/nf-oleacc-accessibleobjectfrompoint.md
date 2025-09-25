# AccessibleObjectFromPoint function

## Description

Retrieves the address of the [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface pointer for the object displayed at a specified point on the screen.

## Parameters

### `ptScreen` [in]

Specifies, in physical screen coordinates, the point that is examined.

### `ppacc` [out]

Address of a pointer variable that receives the address of the object's [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface.

### `pvarChild` [out]

Address of a [VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure) structure that specifies whether the [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface pointer that is returned in *ppacc* belongs to the object displayed at the specified point, or to the parent of the element at the specified point. The **vt** member of the **VARIANT** is always VT_I4. If the **lVal** member is CHILDID_SELF, then the **IAccessible** interface pointer at *ppacc* belongs to the object at the point. If the **lVal** member is not CHILDID_SELF, *ppacc* is the address of the **IAccessible** interface of the child element's parent object. Clients must call [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear) on the retrieved **VARIANT** parameter when finished using it.

## Return value

If successful, returns S_OK.

If not successful, returns one of the following or another standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | An argument is not valid. |

## Remarks

This function retrieves the lowest-level accessible object in the object hierarchy at a given point. If the element at the point is not an accessible object (that is, does not support [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)), then the function retrieves the **IAccessible** interface of the parent object. The parent object must provide information about the child element through the **IAccessible** interface. Call [IAccessible::accHitTest](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-acchittest) to identify the child element at the specified screen coordinates.

As with other [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) methods and functions, clients might receive errors for **IAccessible** interface pointers because of a user action. For more information, see [Receiving Errors for IAccessible Interface Pointers](https://learn.microsoft.com/windows/desktop/WinAuto/receiving-errors-for-iaccessible-interface-pointers).

### Client Example

The following example function selects the item at a specified point on the screen. It is assumed that a single selection is wanted.

```cpp

HRESULT SelectItemAtPoint(POINT point)
{
    VARIANT varItem;
    IAccessible* pAcc;
    HRESULT hr = AccessibleObjectFromPoint(point, &pAcc, &varItem);
    if ((hr == S_OK))
    {
        hr = pAcc->accSelect((SELFLAG_TAKEFOCUS | SELFLAG_TAKESELECTION), varItem);
        VariantClear(&varItem);
        pAcc->Release();
    }
    return hr;
}

```

## See also

[AccessibleObjectFromEvent](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-accessibleobjectfromevent)

[AccessibleObjectFromWindow](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-accessibleobjectfromwindow)

[Active Accessibility and Windows Vista Screen Scaling](https://learn.microsoft.com/windows/desktop/WinAuto/active-accessibility-and-windows-vista-screen-scaling)

[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)

[VARIANT Structure](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)