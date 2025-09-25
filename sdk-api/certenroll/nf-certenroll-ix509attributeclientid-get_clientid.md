# IX509AttributeClientId::get_ClientId

## Description

The **ClientId** property retrieves the type of client application that generated the request.

This property is read-only.

## Parameters

## Remarks

Call the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeclientid-initializeencode) method or the [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeclientid-initializedecode) method to initialize the **ClientId** value. You can call the following properties to retrieve the raw data:

* [MachineDnsName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeclientid-get_machinednsname)
* [ProcessName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeclientid-get_processname)
* [UserSamName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeclientid-get_usersamname)

## See also

[IX509AttributeClientId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributeclientid)