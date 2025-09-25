# IX509Extension::get_Critical

## Description

The **Critical** property specifies and retrieves a Boolean value that identifies whether the certificate extension is critical. This property is web enabled on input.

This property is read/write.

## Parameters

## Remarks

A certificate extension consists of an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID), a Boolean value that identifies whether the extension is critical, and a byte array that contains the extension value. The criticality indicates whether an application that uses a certificate can ignore the extension type and value. If an extension is identified as critical but the application does not recognize the extension type, the application should reject the certificate.

## See also

[IX509Extension](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509extension)