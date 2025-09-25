# ICspInformation::get_IsHardwareDevice

## Description

The **IsHardwareDevice** property retrieves a Boolean value that determines whether the provider is implemented in a hardware device.

This property is read-only.

## Parameters

## Remarks

This property only specifies whether a provider is implemented in hardware. Because a provider can be implemented in both hardware and software, you cannot assume that a value of true for this property indicates that there is no software component. You must also examine the [IsSoftwareDevice](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_issoftwaredevice) property. The following providers return true for the **IsHardwareDevice** property:

* Microsoft Smart Card Key Storage Provider
* Microsoft Base Smart Card Crypto Provider

Both of these providers also return true for the [IsSoftwareDevice](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_issoftwaredevice) property. The Certificate Enrollment service assumes that a provider is a smart card provider if both the **IsHardwareDevice** and **IsSoftwareDevice** properties are set, or if the [IsRemovable](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_isremovable) property is set.

## See also

[ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation)