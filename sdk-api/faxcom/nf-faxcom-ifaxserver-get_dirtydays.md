# IFaxServer::get_DirtyDays

## Description

Sets or retrieves the **DirtyDays** property for a [FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver-client) object. The **DirtyDays** property is the number of days the fax server retains an unsent job in the fax job queue.

This property is read/write.

## Parameters

## Remarks

To minimize the amount of space unsent jobs use, the fax server removes unsent jobs after the number of days specified by the **DirtyDays** property have elapsed.

A transmission might not be sent for various reasons. Examples are if an invalid fax number is specified, or when the sending device receives a busy signal multiple times.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver-client)

[IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxserver)