# ICspInformation::get_Valid

## Description

The **Valid** property retrieves a Boolean value that specifies whether the provider is installed on the client computer.

This property is read-only.

## Parameters

## Remarks

The **Valid** property is typically set by the Certificate Enrollment Control when it processes the list of providers identified in a template-based certificate request. If a provider listed in the template is not installed on the client, the control creates an [ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation) object and sets the value of this property to false. You can use this property value in a user interface to indicate whether a provider is available. If a provider is not installed, only the **Valid** property and the [Name](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-get_name) property provide meaningful information.

## See also

[ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation)