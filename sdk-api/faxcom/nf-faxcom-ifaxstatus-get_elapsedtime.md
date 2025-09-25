# IFaxStatus::get_ElapsedTime

## Description

Retrieves the **ElapsedTime** property for the [FaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxstatus) object of a parent [FaxPort](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxport) object. The **ElapsedTime** property is a number that represents the elapsed time for an active fax job.

This property is read-only.

## Parameters

## Remarks

The value of this property is provided in **DATE** format, but represents elapsed time, not the date and time. The value of this property is undefined if there is no job being executed on the device.

You can use the **ElapsedTime** property of a [FaxStatus](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxstatus) object in conjunction with the [StartTime](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxstatus-get-starttime-vb) property of the object to inform users about the transmission length of a fax job.