# IFaxServer::put_RetryDelay

## Description

Sets or retrieves the **RetryDelay** property for a [FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver-client) object. The **RetryDelay** property is a value that represents the time interval, in minutes, the fax server waits before attempting to retransmit an outbound fax job.

This property is read/write.

## Parameters

## Remarks

A transmission might not be sent on the first attempt for various reasons. For example, the sending device may receive a busy signal.

## See also

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver-client)

[IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxserver)