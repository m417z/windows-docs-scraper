# IAccessible::get_accDescription

## Description

The **IAccessible::get_accDescription** method retrieves a string that describes the visual appearance of the specified object. Not all objects have a description.

**Note** The Description property is often used incorrectly and is not supported by Microsoft UI Automation. Microsoft Active Accessibility server developers should not use this property. If more information is needed for accessibility and automation scenarios, use the
properties supported by UI Automation elements and control patterns.

## Parameters

### `varChild` [in]

Type: **VARIANT**

Specifies whether the retrieved description belongs to the object or one of the object's child elements. This parameter is either CHILDID_SELF (to obtain information about the object) or a child ID (to obtain information about the object's child element). For more information about initializing the [VARIANT structure](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure), see [How Child IDs Are Used in Parameters](https://learn.microsoft.com/windows/desktop/WinAuto/how-child-ids-are-used-in-parameters).

### `pszDescription` [out, retval]

Type: **BSTR***

 Address of a **BSTR** that receives a localized string that describes the specified object, or **NULL** if this object has no description.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

If not successful, returns one of the values in the table that follows, or another standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values). Servers return these values, but clients must always check output parameters to ensure that they contain valid values. For more information, see [Checking IAccessible Return Values](https://learn.microsoft.com/windows/desktop/WinAuto/checking-iaccessible-return-values).

| Return code | Description |
| --- | --- |
| **S_FALSE** | The specified object does not have a description. |
| **E_INVALIDARG** | An argument is not valid. |
| **DISP_E_MEMBERNOTFOUND** | The specified object does not support this property. |

## Remarks

An Microsoft Active Accessibility server can add support for UI Automation by using Direct Annotation, using the [IAccessibleEx](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iaccessibleex) interface, or by implementing Microsoft Active Accessibility and UI Automation side-by-side with both implementations handling the [WM_GETOBJECT](https://learn.microsoft.com/windows/win32/winauto/wm-getobject) message.

This property provides a textual equivalent of the object for the user. The description should be similar to the text supplied with the ALT attribute in HTML, which is the text that is displayed to describe images for people using text-only browsers. However, some controls use this property to store extra information about the control that is not related to a textual equivalent. For more information about this property, see [Description Property](https://learn.microsoft.com/windows/desktop/WinAuto/description-property).

**Note to server developers:** Localize the string returned from this property.

### Server Example

The following example code shows one possible implementation of this method for a custom list box that maintains its own child elements. The example demonstrates the syntax, but remember that a real text-only list box would probably not need to support this property. For simplicity, the strings in the example are not localized.

```cpp

HRESULT STDMETHODCALLTYPE AccServer::get_accDescription(
    VARIANT varChild,
    BSTR *pszDescription)
{
    if (varChild.vt != VT_I4)
    {
        *pszDescription = NULL;
        return E_INVALIDARG;
    }
    if (varChild.lVal == CHILDID_SELF)
    {
        *pszDescription = SysAllocString(L"List of contacts.");

    }
    else
    {
        *pszDescription = SysAllocString(L"A contact.");

    }
    return S_OK;
};

```

### Client Example

The following example function retrieves the description of the specified accessible object, or a child element, and displays it on the console.

```cpp

HRESULT PrintDescription(IAccessible* pAcc, long child)
{
    VARIANT varObject;
    varObject.vt = VT_I4;
    varObject.lVal = child;
    BSTR bstrDesc;
    HRESULT hr = pAcc->get_accDescription(varObject, &bstrDesc);
    if (hr == S_OK)
    {
        printf("Description: %S\n", bstrDesc);
        SysFreeString(bstrDesc);
    }
    return hr;
}

```

## See also

**Conceptual**

[Description Property](https://learn.microsoft.com/windows/desktop/WinAuto/description-property)

[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)

[IAccessible::get_accHelp](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_acchelp)

[IAccessible::get_accName](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_accname)

[IAccessible::get_accValue](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-iaccessible-get_accvalue)

**Reference**

[Using Direct Annotation](https://learn.microsoft.com/windows/desktop/WinAuto/using-direct-annotation)