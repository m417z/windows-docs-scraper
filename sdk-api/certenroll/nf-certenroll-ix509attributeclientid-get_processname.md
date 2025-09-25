# IX509AttributeClientId::get_ProcessName

## Description

The **ProcessName** property retrieves the name of the application that generated the request.

This property is read-only.

## Parameters

## Remarks

Call the [InitializeEncode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeclientid-initializeencode) method or the [InitializeDecode](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeclientid-initializedecode) method to initialize the **ProcessName** value. You can call the following properties to retrieve the raw data:

* [ClientId](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeclientid-get_clientid)
* [MachineDnsName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeclientid-get_machinednsname)
* [UserSamName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509attributeclientid-get_usersamname)

## See also

[IX509AttributeClientId](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509attributeclientid)

[IX509Enrollment](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollment)