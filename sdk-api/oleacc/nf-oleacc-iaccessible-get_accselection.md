# IAccessible::get_accSelection

## Description

The **IAccessible::get_accSelection** method retrieves the selected children of this object. All objects that support selection must support this property.

## Parameters

### `pvarChildren` [out, retval]

Type: **VARIANT***

Address of a [VARIANT structure](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure) that receives information about which children are selected. The following table describes the information returned in *pvarChildren*.

| vt member | Value member |
| --- | --- |
| **VT_EMPTY** | No children are selected. |
| **VT_DISPATCH** | One child object is selected, and the address of its [IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface) interface is set in the **pdispVal** member. |
| **VT_I4** | **lVal** contains the child ID of the child element that is selected. If **lVal** is CHILDID_SELF, this means that the object itself is selected. |
| **VT_UNKNOWN** | Multiple child objects are selected, and the **punkVal** member contains the address of the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface. The client queries this interface for the [IEnumVARIANT](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ienumvariant) interface, which it uses to enumerate the selected objects. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

If not successful, returns one of the values in the table that follows, or another standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values). Servers return these values, but clients must always check output parameters to ensure that they contain valid values. For more information, see [Checking IAccessible Return Values](https://learn.microsoft.com/windows/desktop/WinAuto/checking-iaccessible-return-values).

| Error | Description |
| --- | --- |
| **DISP_E_MEMBERNOTFOUND** | The object does not support this property. |

## Remarks

This method must support the [IEnumVARIANT](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ienumvariant) interface.

This method returns either an [IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface) interface pointer or a child ID for the *pvarChildren* parameter. For more information about how to use the **IDispatch** interface pointer or child ID, see [How Child IDs Are Used in Parameters](https://learn.microsoft.com/windows/desktop/WinAuto/how-child-ids-are-used-in-parameters).

As with other [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) methods and functions, clients might receive errors for **IAccessible** interface pointers because of a user action. For more information, see [Receiving Errors for IAccessible Interface Pointers](https://learn.microsoft.com/windows/desktop/WinAuto/receiving-errors-for-iaccessible-interface-pointers).

**Note:** This method retrieves a selected item, not selected text.

### Server Example

The following example code shows a possible implementation of this method for a custom single-selection list box. Its **GetSelectedIndex** method returns -1 if no item is selected.

```cpp

// m_pControl is the control that returns this accessible object.

HRESULT STDMETHODCALLTYPE AccServer::get_accSelection(VARIANT *pvarChildren)
{
    int childID = m_pControl->GetSelectedIndex() + 1; // Convert from 0-based.
    if (childID <= 0)
    {
        pvarChildren->vt = VT_EMPTY;
    }
    else
    {
        pvarChildren->vt = VT_I4;
        pvarChildren->lVal = childID;
    }
    return S_OK;
};

```

## See also

[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)

[IAccessible::accSelect](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-accselect)

[IAccessible::get_accFocus](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_accfocus)

[IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface)

[Selection and Focus Properties and Methods](https://learn.microsoft.com/windows/desktop/WinAuto/selection-and-focus-properties-and-methods)

[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)