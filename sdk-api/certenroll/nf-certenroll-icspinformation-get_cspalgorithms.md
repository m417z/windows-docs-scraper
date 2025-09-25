# ICspInformation::get_CspAlgorithms

## Description

The **CspAlgorithms** property retrieves a collection of [ICspAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithm) interfaces that contain information about the algorithms supported by the provider. This property is web enabled.

This property is read-only.

## Parameters

## Remarks

An [ICspAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithm) object contains information about the cryptographic algorithms supported by the provider. This includes the algorithm [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID), the permitted key lengths and incremental lengths, the algorithm name and abbreviated name, and a Boolean value that specifies whether the algorithm OID object is valid.

## See also

[ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation)