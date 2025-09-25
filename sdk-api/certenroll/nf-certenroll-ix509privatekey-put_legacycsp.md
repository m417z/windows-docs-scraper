# IX509PrivateKey::put_LegacyCsp

## Description

The **LegacyCsp** property specifies or retrieves a Boolean value that indicates whether the provider is a CryptoAPI (legacy) [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). This property is web enabled for both input and output.

This property is read/write.

## Parameters

## Remarks

Setting this property automatically sets the following properties to be consistent with the specified **LegacyCsp** value:

* [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyspec)
* [ProviderType](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_providertype)

These properties are set in the following manner:

* If the **LegacyCsp** property is set to **VARIANT_FALSE**:
  + The [ProviderType](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_providertype) is set to **XCN_PROV_NONE**.
  + The [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyspec) property is set to **XCN_AT_NONE**.
* If the **LegacyCsp** property is set to **VARIANT_TRUE**:
  + The [ProviderType](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_providertype) is set to **XCN_PROV_RSA_FULL** if the current value is **XCN_PROV_NONE**.
  + The [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_keyspec) property is set to **XCN_AT_SIGNATURE** if the current property is **XCN_AT_NONE**.

Because a previously specified [ProviderName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_providername) is not affected by setting the **LegacyCsp** property, setting a **LegacyCsp** that is inconsistent with the **ProviderName** property will result in undefined behavior, likely a failure when creating or opening a private key.

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)