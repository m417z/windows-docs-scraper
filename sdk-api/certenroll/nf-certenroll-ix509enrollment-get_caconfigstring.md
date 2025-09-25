# IX509Enrollment::get_CAConfigString

## Description

The **CAConfigString** property retrieves the configuration string that identifies the certification authority (CA) to which the certificate request was submitted.

This property is read-only.

## Parameters

## Remarks

The configuration string contains the Domain Name System (DNS) name and the common name (CN) of the certification authority. The format of the string is "*CAComputerDNSName*\*CACommonName*".

## See also

[IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment)