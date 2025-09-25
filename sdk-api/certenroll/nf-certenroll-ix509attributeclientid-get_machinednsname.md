# IX509AttributeClientId::get_MachineDnsName

## Description

The **MachineDnsName** property retrieves the Domain Name System (DNS) name of the computer that generated the request.

This property is read-only.

## Parameters

## Remarks

Call the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeclientid-initializeencode) method or the [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeclientid-initializedecode) method to initialize the **MachineDnsName** value. You can call the following properties to retrieve the raw data:

* [ClientId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeclientid-get_clientid)
* [ProcessName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeclientid-get_processname)
* [UserSamName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeclientid-get_usersamname)

## See also

[IX509AttributeClientId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributeclientid)