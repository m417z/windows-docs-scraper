# ICspInformation::get_IsRemovable

## Description

The **IsRemovable** property retrieves a Boolean value that specifies whether the token that contains the key can be removed.

This property is read-only.

## Parameters

## Remarks

Operator cards and smart cards are examples of removable tokens that can contain keys. For example, the following providers return true for this property value:

* Microsoft Smart Card Key Storage Provider
* Microsoft Base Smart Card Crypto Provider

The Certificate Enrollment service assumes that a provider is a smart card provider if both the [IsHardwareDevice](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_ishardwaredevice) and [IsSoftwareDevice](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_issoftwaredevice) properties are set, or if the **IsRemovable** property is set.

## See also

[ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation)