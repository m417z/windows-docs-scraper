# ICspAlgorithm::get_Valid

## Description

The **Valid** property retrieves a Boolean value that specifies whether the algorithm object is valid.

This property is read-only.

## Parameters

## Remarks

If a template refers to an algorithm that is not supported by the specified cryptographic provider, the enrollment process creates a placeholder [ICspAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithm) object, sets the **Valid** property to false, and sets the [Name](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspalgorithm-get_name) property. No other property values are defined.

You must call the [InitializeFromName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-initializefromname) method or the [InitializeFromType](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icspinformation-initializefromtype) method on the [ICspInformation](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspinformation) interface before calling this property.

[Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) is defined by the X.680 through X.683 standards. The Certificate Enrollment API verifies an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) by [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoding it and then decoding the result to make certain that the OID remains unchanged and by checking that the following are true:

* The first number in the OID is either 0, 1, or 2.
* All other characters are either digits (0 to 9) or periods (.).
* No periods start or end the OID.
* No consecutive characters are both periods.
* The OID must contain at least one period.
* If the first number is 0 or 1, the second number must be between 0 and 39 inclusive.
* If the first number is 2, the second number can be any value.

## See also

[ICspAlgorithm](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icspalgorithm)