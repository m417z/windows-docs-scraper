# IModelObject::EnumerateRawValues

## Description

The EnumerateRawValues method enumerates all native children (e.g.: fields, base classes, etc...) of the given object.

## Parameters

### `kind`

Indicates the kind of native symbol to fetch (e.g.: a base class or a data member)

### `searchFlags`

An optional set of flags specifying the behavior of the search for the native construct.

### `enumerator`

An enumerator which will enumerate every native child of the kind specified by the kind argument as an [IRawEnumerator](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-irawenumerator) interface.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spMessage; /* get a tagMSG */

ComPtr<IRawEnumerator> spEnum;
if (SUCCEEDED(spMessage->EnumerateRawValues(SymbolField, RawSearchNone, &spEnum)))
{
    HRESULT hr = S_OK;
    while (SUCCEEDED(hr))
    {
        BSTR fieldName;
        SymbolKind symKind;
        ComPtr<IModelObject> spFieldValue;
        hr = spEnum->GetNext(&fieldName, &symbolKind, &spFieldValue);
        if (SUCCEEDED(hr))
        {
            // fieldName contains the name of the field, symKind contains the kind of
            // symbol matched (SymbolField in this case), spFieldValue contains the value
            // For tagMSG (with symbols), the enumerator should produce field names and
            // values for 'hwnd', 'message', 'wParam', 'lParam', 'time', and 'pt'
            SysFreeString(fieldName);
        }
    }

    // hr == E_BOUNDS : We hit the end of the enumerator
    // hr == E_ABORT  : There was a user request for an interrupt / propagate that upward immediately
}
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)