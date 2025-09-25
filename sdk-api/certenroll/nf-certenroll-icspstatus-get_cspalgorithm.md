# ICspStatus::get_CspAlgorithm

## Description

The **CspAlgorithm** property retrieves an [ICspAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithm) object that contains information about an algorithm supported by the provider. This property is web enabled.

This property is read-only.

## Parameters

## Remarks

The [ICspAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithm) object includes the following information about an algorithm:

* The default, minimum, maximum, and incremental lengths of the key.
* The abbreviated and long name of the algorithm.
* The cryptographic operations that can be performed by the algorithm.

## See also

[ICspStatus](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatus)

[ICspStatuses](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspstatuses)