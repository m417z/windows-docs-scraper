# ICspAlgorithm::get_Type

## Description

The **Type** property retrieves the algorithm type. This property is web enabled.

This property is read-only.

## Parameters

## Remarks

The main difference between the **Type** property and the [Operations](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspalgorithm-get_operations) property is that the latter contains a bitfield in which multiple bits can be set. Because many algorithms can be used for multiple purposes, the **Operations** property is often more useful. The **Type** value can correspond to only one of the **Operations** value bits. For example, if the **Operations** property returns XCN_NCRYPT_SIGNATURE_OPERATION | XCN_NCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION, the **Type** property may return XCN_BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE.

## See also

[ICspAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithm)

[Operations](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspalgorithm-get_operations)