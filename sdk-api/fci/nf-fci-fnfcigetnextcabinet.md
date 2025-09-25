## Description

The **FNFCIGETNEXTCABINET** macro provides the declaration for the application-defined callback function to request information for the next cabinet.

## Parameters

### `fn`

Pointer to a [CCAB](https://learn.microsoft.com/windows/desktop/api/fci/ns-fci-ccab) structure to provide the parameters for the creation of a new cabinet.

## Remarks

The [CCAB](https://learn.microsoft.com/windows/desktop/api/fci/ns-fci-ccab) structure referenced by this function is relevant to the most recently completed cabinet. However, with each successful operation the *iCab* field contained within this structure will have incremented by 1. Additionally, the next cabinet will be created using the fields in this structure. The szCab, in particular, should be modified as necessary. In particular, the *szCab* field, which specifies the cabinet name, should be changed for each cabinet.

When creating multiple cabinets, typically the *iCab* field is used to create the name.

#### Examples

```cpp
FNFCIGETNEXTCABINET(fnGetNextCabinet)
{
    HRESULT hr;

    UNREFERENCED_PARAMETER(pv);
    UNREFERENCED_PARAMETER(cbPrevCab);

    hr = StringCchPrintfA(pccab->szCab,
                          ARRAYSIZE(pccab->szCab),
                          "FCISample%02d.cab",
                          pccab->iCab);

    return ( SUCCEEDED(hr) );
}

```

## See also

[FCICreate](https://learn.microsoft.com/windows/desktop/api/fci/nf-fci-fcicreate)