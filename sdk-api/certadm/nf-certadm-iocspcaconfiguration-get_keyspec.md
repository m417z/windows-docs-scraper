# IOCSPCAConfiguration::get_KeySpec

## Description

The **KeySpec** property gets a value that indicates whether the key bound to the configuration is used for encryption or for signing content. The default implementations of [IOCSPAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspadmin) and [IOCSPCAConfigurationCollection](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfigurationcollection) methods set this value.

 Possible values are determined by the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) in use.

This property is read-only.

## Parameters

## Remarks

For the Microsoft Base Cryptographic Provider, the **KeySpec** property has the value **AT_KEYEXCHANGE** for [exchange keys](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) and the value **AT_SIGNATURE** for signature keys. The default value is **AT_SIGNATURE**.

For information about the other Microsoft CSPs, see
[Cryptographic Service Providers](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptographic-service-providers) in the CryptoAPI 2.0 documentation.

For information about a non-Microsoft CSP, see the documentation provided with that CSP.

## See also

[IOCSPCAConfiguration](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfiguration)