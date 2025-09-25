# IAccessible::get_accHelp

## Description

The **IAccessible::get_accHelp** method retrieves the **Help** property string of an object. Not all objects support this property.

## Parameters

### `varChild` [in]

Type: **VARIANT**

Specifies whether the retrieved help information belongs to the object or one of the object's child elements. This parameter is either CHILDID_SELF (to obtain information about the object) or a child ID (to obtain information about one of the object's child elements). For more information about initializing the [VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure), see [How Child IDs Are Used in Parameters](https://learn.microsoft.com/windows/desktop/WinAuto/how-child-ids-are-used-in-parameters).

### `pszHelp` [out, retval]

Type: **BSTR***

Address of a **BSTR** that receives the localized string containing the help information for the specified object, or **NULL** if no help information is available.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

If not successful, returns one of the values in the table that follows, or another standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values). Servers return these values, but clients must always check output parameters to ensure that they contain valid values. For more information, see [Checking IAccessible Return Values](https://learn.microsoft.com/windows/desktop/WinAuto/checking-iaccessible-return-values).

| Error | Description |
| --- | --- |
| **S_FALSE** | No help information is available. |
| **E_INVALIDARG** | An argument is not valid. |
| **DISP_E_MEMBERNOTFOUND** | The object does not support this property. |

## Remarks

None of the predefined and common controls support this property.

**Note to server developers:** Localize the string returned from this property.

This property returns a string, whereas [IAccessible::get_accHelpTopic](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_acchelptopic) provides access to a Help topic in [WinHelp](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-winhelpa). Objects are not required to support both **IAccessible::get_accHelp** and **IAccessible::get_accHelpTopic**, but they must support at least one. If they easily return a string, they must support **IAccessible::get_accHelp** ; otherwise they must support **IAccessible::get_accHelpTopic**. If both are supported, **IAccessible::get_accHelpTopic** provides more detailed information.

### Server Example

The following example code shows one possible implementation of this method for a custom list box. Different text is displayed depending on the status of the contact in the list. For simplicity, the example does not localize the returned string.

```cpp

// m_pControl is the custom control that returns this accessible object.
// 'online' is an enumerated value.

HRESULT STDMETHODCALLTYPE AccServer::get_accHelp(
    VARIANT varChild,
    BSTR *pszHelp)
{
    *pszHelp = NULL;
    if (varChild.vt != VT_I4)
    {
        return E_INVALIDARG;
    }
    if (varChild.lVal == CHILDID_SELF)
    {
        *pszHelp = SysAllocString(L"Contact list.");
    }
    else
    {
        int index = (int)varChild.lVal - 1;
        CustomListControlItem* pItem = m_pControl->GetItemAt(index);
        if (pItem == NULL)
        {
            return E_INVALIDARG;
        }
        if (pItem->GetStatus() == online)
        {
            *pszHelp = SysAllocString(L"Online contact.");
        }
        else
        {
            *pszHelp = SysAllocString(L"Offline contact.");
        }
    }
    return S_OK;
};

```

## See also

[Help Property](https://learn.microsoft.com/windows/desktop/WinAuto/help-property)

[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)

[IAccessible::get_accDescription](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_accdescription)

[IAccessible::get_accHelpTopic](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_acchelptopic)

[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)