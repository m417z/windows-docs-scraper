# IAccessible::get_accName

## Description

The **IAccessible::get_accName** method retrieves the name of the specified object. All objects support this property.

## Parameters

### `varChild` [in]

Type: **VARIANT**

Specifies whether the retrieved name belongs to the object or one of the object's child elements. This parameter is either CHILDID_SELF (to obtain information about the object) or a child ID (to obtain information about the object's child element). For more information about initializing the [VARIANT structure](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure), see [How Child IDs Are Used in Parameters](https://learn.microsoft.com/windows/desktop/WinAuto/how-child-ids-are-used-in-parameters).

### `pszName` [out, retval]

Type: **BSTR***

Address of a **BSTR** that receives a string that contains the specified object's name.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

If not successful, returns one of the values in the table that follows, or another standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values). Servers return these values, but clients must always check output parameters to ensure that they contain valid values. For more information, see [Checking IAccessible Return Values](https://learn.microsoft.com/windows/desktop/WinAuto/checking-iaccessible-return-values).

| Error | Description |
| --- | --- |
| **S_FALSE** | The specified object does not have a name. |
| **E_INVALIDARG** | An argument is not valid. |

## Remarks

Many objects such as icons, menus, check boxes, combo boxes, and other controls have labels that are displayed to users. Any label that is displayed to users is used for the object's name property. For more information, see the [Name Property](https://learn.microsoft.com/windows/desktop/WinAuto/name-property).

**Note to server developers:** If you are using menu or button text for the Name property, remove any ampersands (&) marking the keyboard access keys. Provide the access key to the client in response to [IAccessible::get_accKeyboardShortcut](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_acckeyboardshortcut).

Localize the string returned from this property.

### Server Example

The following example shows a possible implementation of this method for a custom list box control that manages its own child elements.

```cpp

// m_pStdAccessibleObject is the standard object returned by CreateStdAccessibleObject.
// m_pControl is the control object that provides this accessibility object. It maintains
// a zero-based collection of child items.

HRESULT STDMETHODCALLTYPE AccServer::get_accName(
    VARIANT varChild,
    BSTR *pszName)
{
    if (varChild.vt != VT_I4)
    {
        *pszName = NULL;
        return E_INVALIDARG;
    }
    // For the control itself, let the standard accessible object return the name
    // assigned by the application. This is either the "caption" property or, if
    // there is no caption, the text of any label.
    if (varChild.lVal == CHILDID_SELF)
    {
        return m_pStdAccessibleObject->get_accName(varChild, pszName);
    }

    // Else return the name of the item in the list.
    else
    {
        CustomListControlItem* pItem = m_pControl->GetItemAt(varChild.lVal - 1);
        if (pItem)
        {
            *pszName = SysAllocString(pItem->GetName());

        }
    }
    return S_OK;
};

```

### Client Example

The following example function displays the accessible name of a control.

```cpp

HRESULT PrintName(IAccessible* pAcc, long childId)
{
    if (pAcc == NULL)
    {
        return E_INVALIDARG;
    }
    BSTR bstrName;
    VARIANT varChild;
    varChild.vt = VT_I4;
    varChild.lVal = childId;
    HRESULT hr = pAcc->get_accName(varChild, &bstrName);
    printf("Name: %S ", bstrName);
    SysFreeString(bstrName);
    return hr;
}

```

## See also

[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)

[IAccessible::get_accKeyboardShortcut](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_acckeyboardshortcut)

[Name Property](https://learn.microsoft.com/windows/desktop/WinAuto/name-property)

[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)