# IX509AttributeCspProvider::get_Signature

## Description

The **Signature** property retrieves the [digital signature](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) on the provider. The signature is contained in a byte array represented by a Unicode-encoded string.

This property is read-only.

## Parameters

## Remarks

Call the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributecspprovider-initializeencode) method or the [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributecspprovider-initializedecode) method to initialize the **Signature** property. You can call the following properties to retrieve the raw data:

* [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributecspprovider-get_keyspec)
* [ProviderName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributecspprovider-get_providername)

## See also

[IX509AttributeCspProvider](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributecspprovider)