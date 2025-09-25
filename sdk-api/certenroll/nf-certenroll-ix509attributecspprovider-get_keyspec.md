# IX509AttributeCspProvider::get_KeySpec

## Description

The **KeySpec** property retrieves a value that identifies whether the key pair stored by the provider or key container is used for encryption or for signing content.

This property is read-only.

## Parameters

## Remarks

Call the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributecspprovider-initializeencode) method or the [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributecspprovider-initializedecode) method to initialize the **KeySpec** property. You can also call the following properties to retrieve raw data:

* [ProviderName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributecspprovider-get_providername)
* [Signature](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributecspprovider-get_signature)

## See also

[IX509AttributeCspProvider](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributecspprovider)