# AlgorithmFlags enumeration

## Description

The **AlgorithmFlags** enumeration type contains flags that can be used to refine the search for a [cryptographic algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). The only flag currently defined enables retrieval of key wrapping algorithms. This enumeration is used by the [InitializeFromAlgorithmName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-initializefromalgorithmname) method on the [IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid) interface.

## Constants

### `AlgorithmFlagsNone:0`

No flags are specified.

### `AlgorithmFlagsWrap:0x1`

The algorithm is used for key wrapping. For more information, see [InitializeFromAlgorithmName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-iobjectid-initializefromalgorithmname).

## See also

[CertEnroll Enumerations](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-enumerations)

[CertEnroll Interfaces](https://learn.microsoft.com/windows/desktop/SecCertEnroll/certenroll-interfaces)

[ICspAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithm)

[IObjectId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-iobjectid)