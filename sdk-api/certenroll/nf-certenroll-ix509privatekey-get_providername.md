# IX509PrivateKey::get_ProviderName

## Description

The **ProviderName** property specifies or retrieves the name of the cryptographic provider. This property is web enabled for both input and output.

This property is read/write.

## Parameters

## Remarks

Setting this property automatically sets the following properties to be consistent with the specified **ProviderName** value:

* [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyspec)
* [LegacyCsp](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_legacycsp)
* [ProviderType](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_providertype)

These properties are set in the following manner:

* The provider configuration data is used, if available, to determine the appropriate [ProviderType](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_providertype) value.
* If the specified provider is a CNG KSP:
  + The [LegacyCsp](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_legacycsp) property is set to **VARIANT_FALSE**.
  + The [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyspec) property is set to **XCN_AT_NONE**.
* If the specified provider is not a CNG KSP:
  + The [LegacyCsp](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_legacycsp) property is set to **VARIANT_TRUE**.
  + The [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyspec) property is set to **XCN_AT_SIGNATURE**.

If you set the **ProviderName** property, we recommend that you do not set the [LegacyCsp](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_legacycsp) or [ProviderType](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_providertype) properties.

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)