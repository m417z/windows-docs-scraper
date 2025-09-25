# IX509PrivateKey::get_ProviderType

## Description

The **ProviderType** property specifies or retrieves the type of cryptographic provider associated with the [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). This property is web enabled for both input and output.

This property is read/write.

## Parameters

## Remarks

You can use this property to force the use of the default provider for a given provider type. For example, to use the **PROV_RSA_SCHANNEL** provider, set this property to the **XCN_PROV_RSA_SCHANNEL**[X509ProviderType](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509providertype) enumeration value and do not specify a value for the [ProviderName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_providername) property.

Setting this property automatically sets the following properties to be consistent with the specified **ProviderType** value:

* [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyspec)
* [LegacyCsp](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_legacycsp)

These properties are set in the following manner:

* If the **ProviderType** is set to **XCN_PROV_NONE**:
  + The [LegacyCsp](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_legacycsp) property is set to **VARIANT_FALSE**.
  + The [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyspec) property is set to **XCN_AT_NONE**.
* If the **ProviderType** is not set to **XCN_PROV_NONE**:
  + The [LegacyCsp](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_legacycsp) property is set to **VARIANT_TRUE**.
  + The [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyspec) property is set to **XCN_AT_SIGNATURE** if the current value is **XCN_AT_NONE**.

Because a previously specified [ProviderName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_providername) is not affected by setting the **ProviderType** property, setting a **ProviderType** that is inconsistent with the **ProviderName** property will result in undefined behavior, likely a failure when creating or opening a private key. We recommend that you set the **ProviderType** property only when attempting to force the use of the default provider for the specified type as discussed above.

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)