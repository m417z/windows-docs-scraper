# IAccessible::accNavigate

## Description

The **IAccessible::accNavigate** method traverses to another UI element within a container and retrieves the object. This method is optional.

**Note** The **accNavigate** method is deprecated and should not be used. Clients should use other methods and properties such as [AccessibleChildren](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-accessiblechildren), [get_accChild](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_accchild), [get_accParent](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_accparent), and [IEnumVARIANT](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ienumvariant).

## Parameters

### `navDir` [in]

Type: **long**

Specifies the direction to navigate. This direction is in *spatial* order, such as left or right, or *logical* order, such as next or previous. This value is one of the [navigation constants](https://learn.microsoft.com/windows/desktop/WinAuto/navigation-constants).

### `varStart` [in]

Type: **VARIANT**

Specifies whether the starting object of the navigation is the object itself or one of the object's children. This parameter is either CHILDID_SELF (to start from the object) or a child ID (to start from one of the object's child elements). For more information about initializing the [VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure), see [How Child IDs Are Used in Parameters](https://learn.microsoft.com/windows/desktop/WinAuto/how-child-ids-are-used-in-parameters).

### `pvarEndUpAt` [out, retval]

Type: **VARIANT***

[out, retval] Address of a [VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure) structure that receives information about the destination object. The following table describes the information that is returned in *pvarEnd*.

| vt member | Value member |
| --- | --- |
| **VT_EMPTY** | None. There was no UI element in the specified direction. |
| **VT_I4** | **lVal** contains the child ID of the UI element. |
| **VT_DISPATCH** | **pdispVal** contains the address of the UI element's [IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface). |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

If not successful, returns one of the values in the table that follows, or another standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values). Servers return these values, but clients must always check output parameters to ensure that they contain valid values. For more information, see [Checking IAccessible Return Values](https://learn.microsoft.com/windows/desktop/WinAuto/checking-iaccessible-return-values) and Return Values.

| Error | Description |
| --- | --- |
| **S_FALSE** | No screen element was found in the specified direction. |
| **DISP_E_MEMBERNOTFOUND** | The object does not support this method. |
| **E_INVALIDARG** | An argument is not valid. |

## Remarks

Navigation, both spatial and logical, is always restricted to the UI elements within a container. With spatial navigation, clients navigate only to a sibling of the starting object (*varStart*). Depending on the navigational flag used with logical navigation, clients navigate to either a child or to a sibling of the starting object.

The **accNavigate** method retrieves UI elements that have a defined screen location, and invisible objects that do not have a defined screen location.

This method does not change the selection or focus. To change the focus or to select an object, use [IAccessible::accSelect](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-accselect).

To prevent looping when traversing screen elements, **accNavigate** returns S_FALSE with VT_EMPTY when you specify [NAVDIR_NEXT](https://learn.microsoft.com/windows/desktop/WinAuto/navigation-constants) on the last element, or [NAVDIR_PREVIOUS](https://learn.microsoft.com/windows/desktop/WinAuto/navigation-constants) on the first element.

As with other [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) methods and functions, clients might receive errors for **IAccessible** interface pointers because of a user action. For more information, see [Receiving Errors for IAccessible Interface Pointers](https://learn.microsoft.com/windows/desktop/WinAuto/receiving-errors-for-iaccessible-interface-pointers).

Some system-defined UI elements such as menus, menu items, and pop-up menus allow navigation to invisible objects. However, other system-defined UI elements do not support this. Servers can choose whether to support navigating to invisible objects and can either skip over or expose them.

Client applications must return post-process return values when using **accNavigate** to navigate between objects. The goal of the post-processing steps is to give clients an [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface pointer and a child ID so that they can use the **IAccessible** methods and properties for a UI element.

The following tables describe possible scenarios for **IAccessible::accNavigate**, based on the following criteria:

* A defined starting point (whether you are starting with a full object or a simple element)
* The result returned (an [IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface) or a VT_I4 child ID)
* The post-processing that client applications will need to perform to have an [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface pointer and a child ID

For these tables, assume that *startID* and *endID* are VT_I4 child IDs (simple elements), and *pStartAcc* and *pEndAcc* are VT_I4 with CHILDID_SELF (full objects).

This table describes the following NAVDIR_ flags: NEXT, PREVIOUS, LEFT, RIGHT, UP, and DOWN. For more information about navigation flags, see [Navigation Constants](https://learn.microsoft.com/windows/desktop/WinAuto/navigation-constants).

| Starting point | Result returned | Post-processing for the return value |
| --- | --- | --- |
| *pStartAcc, startID* | VT_I4 *endID* | Call [get_accChild](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_accchild) on *pStartAcc* passing *endID*. Follow normal procedures outlined in **get_accChild**. |
| *pStartAcc, startID* | VT_DISPATCH *pEndAcc* | Use the standard procedures for converting an [IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface) interface pointer to an [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface pointer for *pEndAcc*. |
| *pStartAcc*, CHILDID_SELF | VT_I4 *endID* | Call [get_accParent](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_accparent) on *pStartAcc*, passing CHILDID_SELF to get the [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface pointer of the parent for *endID*. Then, call [get_accChild](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_accchild) on that **IAccessible** interface pointer, passing *endID*. Follow normal procedures outlined in **get_accChild**. |
| *pStartAcc*, CHILDID_SELF | VT_DISPATCH *pEndAcc* | Use the standard procedures for converting an [IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface) interface pointer to an [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface pointer for *pEndAcc*. |

The following table describes navigation flags [NAVDIR_FIRSTCHILD](https://learn.microsoft.com/windows/desktop/WinAuto/navigation-constants) and [NAVDIR_LASTCHILD](https://learn.microsoft.com/windows/desktop/WinAuto/navigation-constants). It does not include entries for navigating to a first or last child when the starting point is a simple element because simple elements cannot have children.

| Starting point | Result returned | Post-processing for the return value |
| --- | --- | --- |
| *pStartAcc*, CHILDID_SELF | VT_I4 *endID* | Call [get_accChild](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_accchild) on *pStartAcc*, passing endID. Follow normal procedures outlined in **get_accChild**. |
| *pStartAcc*, CHILDID_SELF | VT_DISPATCH *pEndAcc* | Use the standard procedures for converting an [IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface) interface pointer to an [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface pointer for *pEndAcc*. |

For more information, see [Object Navigation Properties and Methods](https://learn.microsoft.com/windows/desktop/WinAuto/object-navigation-properties-and-methods).

### Server Example

The following example shows a possible implementation of the method for a custom list box whose list items are child elements.

```cpp

// m_pControl is the control that returns this accessible object.
// m_pStdAccessibleObject is the standard accessible object for the window
//    that contains the control.

HRESULT STDMETHODCALLTYPE AccServer::accNavigate(
    long navDir,
    VARIANT varStart,
    VARIANT *pvarEndUpAt)
{
    // Default value.
    pvarEndUpAt->vt = VT_EMPTY;

    if (varStart.vt != VT_I4)
    {
        return E_INVALIDARG;
    }

    switch (navDir)
    {
    case NAVDIR_FIRSTCHILD:
        if (varStart.lVal == CHILDID_SELF)
        {
            pvarEndUpAt->vt = VT_I4;
            pvarEndUpAt->lVal = 1;
        }
        else  // Starting with child.
        {
            return S_FALSE;
        }
        break;

    case NAVDIR_LASTCHILD:
        if (varStart.lVal == CHILDID_SELF)
        {
            pvarEndUpAt->vt = VT_I4;
            pvarEndUpAt->lVal = m_pControl->GetCount();
        }
        else  // Starting with child.
        {
            return S_FALSE;
        }
        break;

    case NAVDIR_NEXT:
    case NAVDIR_DOWN:
        if (varStart.lVal != CHILDID_SELF)
        {
            pvarEndUpAt->vt = VT_I4;
            pvarEndUpAt->lVal = varStart.lVal + 1;
            // Out of range.
            if (pvarEndUpAt->lVal > m_pControl->GetCount())
            {
                pvarEndUpAt->vt = VT_EMPTY;
                return S_FALSE;
            }
        }
        else  // Call through to method on standard object.
        {
            return m_pStdAccessibleObject->accNavigate(navDir, varStart, pvarEndUpAt);
        }
        break;

    case NAVDIR_PREVIOUS:
    case NAVDIR_UP:
        if (varStart.lVal != CHILDID_SELF)
        {
            pvarEndUpAt->vt = VT_I4;
            pvarEndUpAt->lVal = varStart.lVal - 1;
            // Out of range.
            if (pvarEndUpAt->lVal <1)
            {
                pvarEndUpAt->vt = VT_EMPTY;
                return S_FALSE;
            }
        }
        else  // Call through to method on standard object.
        {
            return m_pStdAccessibleObject->accNavigate(navDir, varStart, pvarEndUpAt);
        }
        break;

     // Unsupported directions.
    case NAVDIR_LEFT:
    case NAVDIR_RIGHT:
        if (varStart.lVal == CHILDID_SELF)
        {
            return m_pStdAccessibleObject->accNavigate(navDir, varStart, pvarEndUpAt);
        }
        else
        {
            pvarEndUpAt->vt = VT_EMPTY;
            return S_FALSE;
        }
        break;
    }
    return S_OK;
};

```

## See also

[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)

[IAccessible::accSelect](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-accselect)

[IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface)

[Object Navigation Properties and Methods](https://learn.microsoft.com/windows/desktop/WinAuto/object-navigation-properties-and-methods)

[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)