# IRawElementProviderSimple::GetPropertyValue

## Description

Retrieves the value of a property supported by the Microsoft UI Automation provider.

## Parameters

### `propertyId` [in]

Type: **PROPERTYID**

The property identifier. For a list of property IDs, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids).

### `pRetVal` [out, retval]

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)***

Receives the property value, or **VT_EMPTY** if the property is not supported by this
provider. This parameter is passed uninitialized. See Remarks.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) error code.

If the provider does not support the *propertyId* property, the provider should set *pRetVal->vt* to **VT_EMPTY** and return **S_OK**.

## Remarks

If a provider is explicitly hiding the property value (that is, the provider does not supply the property, and the request is not to be passed through to other providers), it should return a pointer obtained by using the [UiaGetReservedNotSupportedValue](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiagetreservednotsupportedvalue) function. For example:

```
pRetVal->vt = VT_UNKNOWN;
UiaGetReservedNotSupportedValue(&pRetVal->punkVal);
```

UI Automation properties of the **double** type support Not a Number (NaN) values. When returning a NaN value, the provider should return a quiet (non-signaling) NaN to avoid raising an exception if floating-point exceptions are turned on. The following example shows how to create a quiet NaN:

```
ULONGLONG ulNaN = 0xFFFFFFFFFFFFFFFF;
    *pRetVal = *reinterpret_cast<double*>(&ulNaN);
```

Alternatively, you can use the following function from the standard C++ libraries:

```
numeric_limits<double>::quiet_NaN( )
```

#### Examples

The following example returns various property values. The **UiaIds** structure contains
property identifiers; to see how it is initialized, see [UiaLookupId](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uialookupid).

```cpp

HRESULT STDMETHODCALLTYPE Provider::GetPropertyValue(PROPERTYID propertyId,
        VARIANT* pRetVal)
{
    if (propertyId == UiaIds.ControlTypeProperty)
    {
        pRetVal->vt = VT_I4;
        pRetVal->lVal = UiaIds.ButtonControlType;
    }

    // The Name property normally comes from the Caption property of the
    // control window, if it has one. The Name is overridden here for the
    // sake of illustration.
    else if (propertyId == UiaIds.NameProperty)
    {
        pRetVal->vt = VT_BSTR;
        pRetVal->bstrVal = SysAllocString(L"ColorButton");
    }
    else
    {
        pRetVal->vt = VT_EMPTY;
        // UI Automation will attempt to get the property from the host
        //window provider.
    }
    return S_OK;
}

```

## See also

[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)