# ICspStatuses::get_ItemByOrdinal

## Description

The **ItemByOrdinal** property retrieves an [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) object from the collection by ordinal number.

This property is read-only.

## Parameters

## Remarks

The ordinal order of the [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) objects in the collection can vary each time the collection is enumerated for a variety of reasons including, but not limited to, the following:

* Certificate request template settings
* Property values for the cryptographic provider
* Private key property values

For example, assume that the version 2 template chosen to create a certificate request specifies that the certificate can only be used for signing (the **pKIDefaultKeySpec** template attribute is XCN_AT_SIGNATURE) and that the default provider is the Microsoft Enhanced RSA and AES Cryptographic Provider. Notice that the template restricts the certificate to signing even though the provider supports both encryption and signing algorithms. That is, the [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_keyspec) property on the provider is a bitwise combination of the XCN_AT_KEYEXCHANGE and XCN_AT_SIGNATURE constants, but the **pKIDefaultKeySpec** template attribute supports only XCN_AT_SIGNATURE.

The [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) objects in the collection will be ordered in the following manner:

* Of the [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) objects enumerated for this provider, those associated with signature algorithms (XCN_AT_SIGNATURE) are ordered first (lower ordinal value) and their [Display](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_display) and [Selected](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_selected) properties are enabled.

  **Note** If the **pKIDefaultKeySpec** template attribute had been XCN_AT_KEYEXCHANGE, the encryption algorithms would be ordered first.
* Of the [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) objects enumerated for this provider, those associated with encryption algorithms (XCN_AT_KEYEXCHANGE) are ordered later (higher ordinal values) and their [Display](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_display) and [Selected](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_selected) properties are not enabled.
* For all other installed CryptoAPI providers that support asymmetric signing algorithms (XCN_AT_SIGNATURE) but which are not associated with the specified provider, the [Display](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_display) property is enabled and the [Selected](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_selected) property is not enabled.
* For all other installed CryptoAPI providers that support asymmetric encryption algorithms (XCN_AT_KEYEXCHANGE), the [Display](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_display) and [Selected](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_selected) properties are not enabled.
* For all installed Cryptography API: Next Generation (CNG) providers, the [Display](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_display) and [Selected](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509enrollmentstatus-get_selected) properties are not enabled.

For another example, assume that a version 3 template specifies one specific CNG provider and algorithm. That provider/algorithm pair ([ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) object) is ordered first, enabled for display and selected. All other algorithms supported by that provider are ordered later, not enabled for display, and not selected. All other providers that support the specified algorithm will be ordered later still, enabled for display, but not selected. All remaining provider/algorithm pairs will not be enabled for display and not selected.

**Note** CNG providers do not support the [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_keyspec) intended use concept. They return XCN_AT_NONE for this property value.

## See also

[ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus)

[ICspStatuses](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatuses)