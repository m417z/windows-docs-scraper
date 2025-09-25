# IX509AttributeClientId::get_UserSamName

## Description

The **UserSamName** property retrieves the [Security Accounts Manager](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SAM) name of the user.

This property is read-only.

## Parameters

## Remarks

Call the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeclientid-initializeencode) method or the [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeclientid-initializedecode) method to initialize the **UserSamName** value. You can call the following properties to retrieve the raw data:

* [ClientId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeclientid-get_clientid)
* [MachineDnsName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeclientid-get_machinednsname)
* [ProcessName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeclientid-get_processname)

## See also

[IX509AttributeClientId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributeclientid)