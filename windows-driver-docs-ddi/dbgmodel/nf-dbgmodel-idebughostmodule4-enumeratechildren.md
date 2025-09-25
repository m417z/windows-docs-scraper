## Description

The EnumerateChildren method returns an enumerator which will enumerate all children of a given symbol. For a C++ type, for example, the base classes, fields, member functions, and the like are all considered children of the type symbol.

## Parameters

### `kind`

Indicates what kinds of child symbols the caller wishes to enumerate. If the flat value Symbol is passed, all kinds of child symbols will be enumerated.

### `name`

If specified, only child symbols with a name as given in this argument will be enumerated.

### `ppEnum`

An enumerator which enumerates child symbols of the specified kind and name will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IDebugHostType> spType; /* get the type of an object */

// Enumerate every field of this type.  Note that this *WILL NOT* enumerate
// fields of base classes!
ComPtr<IDebugHostSymbolEnumerator> spEnum;
if (SUCCEEDED(spType->EnumerateChildren(SymbolField, nullptr, &spEnum)))
{
    ComPtr<IDebugHostSymbol> spFieldSymbol;
    HRESULT hr = S_OK;
    while (SUCCEEDED(hr))
    {
        hr = spEnum->GetNext(&spFieldSymbol);
        if (SUCCEEDED(hr))
        {
            ComPtr<IDebugHostField> spField;
            if (SUCCEEDED(spFieldSymbol.As(&spField))) /* should always succeed */
            {
                // spField is each field of the type in turn
            }
        }
    }

    // hr == E_BOUNDS : we hit the end of the enumerator
    // hr == E_ABORT  : user requested interruption, propagate upwards immediately
}
```

## See also

[IDebugHostModule4 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmodule4)