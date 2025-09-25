# IADsProperty::Qualifiers

## Description

The **IADsProperty::Qualifiers** method is an optional method that returns a collection of ADSI objects that describe additional qualifiers of this property.

## Parameters

### `ppQualifiers` [out]

Indirect pointer to the [IADsCollection](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscollection) interface on the ADSI collection object that represents additional limits for this property.

## Return value

This method supports the standard return values **E_FAIL** and **E_UNEXPECTED**, as well as the following:

## Remarks

The qualifier objects are provider-specific. When supported, this method can be used to obtain extended schema data.

This method is not currently supported by any of the providers supplied by Microsoft.

## See also

[IADsClass::Qualifiers](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsclass-qualifiers)

[IADsCollection](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscollection)

[IADsProperty](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsproperty)