# IAccessible::get_accDefaultAction

## Description

The **IAccessible::get_accDefaultAction** method retrieves a string that indicates the object's default action. Not all objects have a default action.

## Parameters

### `varChild` [in]

Type: **VARIANT**

Specifies whether the retrieved default action is performed by the object or of one of the object's child elements. This parameter is either CHILDID_SELF (to obtain information about the object) or a child ID (to obtain information about the object's child element). For more information about initializing the [VARIANT structure](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure), see [How Child IDs Are Used in Parameters](https://learn.microsoft.com/windows/desktop/WinAuto/how-child-ids-are-used-in-parameters).

### `pszDefaultAction` [out, retval]

Type: **BSTR***

Address of a **BSTR** that receives a localized string that describes the default action for the specified object; if this object has no default action, the value is **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

If not successful, returns one of the values in the table that follows, or another standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values). Servers return these values, but clients must always check output parameters to ensure that they contain valid values. For more information, see [Checking IAccessible Return Values](https://learn.microsoft.com/windows/desktop/WinAuto/checking-iaccessible-return-values).

| Error | Description |
| --- | --- |
| **S_FALSE** | The specified object does not have a default action. |
| **E_INVALIDARG** | An argument is not valid. |
| **DISP_E_MEMBERNOTFOUND** | The specified object does not support this property. |

## Remarks

The retrieved string describes the action that is performed on an object, not what the object does as a result. For example, a toolbar button that prints a document has a default action of "Press" rather than "Prints the current document."

Do not confuse an object's default action with its value. For more information, see [DefaultAction Property](https://learn.microsoft.com/windows/desktop/WinAuto/defaultaction-property).

Only controls that perform actions support this method.

**Note to server developers:** Localize the string returned from this property.

### Server Example

The following example code shows a possible implementation of this method for a custom list box. For simplicity, the strings are not localized.

```cpp

HRESULT STDMETHODCALLTYPE AccServer::get_accDefaultAction(
    VARIANT varChild,
    BSTR *pszDefaultAction)
{
    if (varChild.vt != VT_I4)
    {
        *pszDefaultAction = NULL;
        return E_INVALIDARG;
    }
    if (varChild.lVal == CHILDID_SELF)
    {
        *pszDefaultAction = SysAllocString(L"None.");
    }
    else
    {
        *pszDefaultAction = SysAllocString(L"Double-click");
    }
    return S_OK;
};

```

## See also

[DefaultAction Property](https://learn.microsoft.com/windows/desktop/WinAuto/defaultaction-property)

[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)

[IAccessible::accDoDefaultAction](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-accdodefaultaction)

[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)