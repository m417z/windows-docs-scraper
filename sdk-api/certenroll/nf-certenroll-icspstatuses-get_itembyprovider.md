# ICspStatuses::get_ItemByProvider

## Description

The **ItemByProvider** property retrieves an [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) object that has the same name as the provider specified on input but identifies an algorithm that supports a different intended key use.

This property is read-only.

## Parameters

## Remarks

The **ItemByProvider** property retrieves the [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) object that matches the name of the input provider but is associated with a different [X509KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509keyspec) enumeration value. For example, if the input provider has a [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_keyspec) value of XCN_AT_KEYEXCHANGE, the **ItemByProvider** property attempts to find an **ICspStatus** object for the same provider but with a **KeySpec** value of XCN_AT_SIGNATURE.

Because the [KeySpec](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_keyspec) property is only associated with legacy providers, if you specify a Cryptography API: Next Generation (CNG) providers, the **ItemByProvider** property returns the same [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) object as that entered.

To use this property to iterate through the collection, perform the following steps:

* Retrieve an [ICspStatuses](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatuses) collection by calling the [GetCspStatuses](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-getcspstatuses) method or the [CspStatuses](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509certificaterequestpkcs10-get_cspstatuses) property on the [IX509CertificateRequestPkcs10](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509certificaterequestpkcs10) interface.
* Call the [ItemByIndex](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspstatuses-get_itembyindex) property to iterate through the collection.
* For each [ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus) element retrieved that contains the provider you are interested in, call **ItemByProvider**.

## See also

[ICspStatuses](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatuses)