# ICspStatus::get_CspInformation

## Description

The **CspInformation** property retrieves an [ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation) object that contains general information about the provider. This property is web enabled.

This property is read-only.

## Parameters

## Remarks

The [ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation) object includes the following information about a CSP:

* A collection of supported algorithms and their intended uses.
* Whether the CSP is implemented in hardware or software.
* Whether the CSP is a smart card provider or a legacy provider.
* The version number and name.
* Whether the CSP is installed on the client computer.

## See also

[ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus)

[ICspStatuses](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatuses)