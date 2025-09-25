# WdfFileObjectGetInitiatorProcessId function

## Description

[Applies to KMDF and UMDF]

The **WdfFileObjectGetInitiatorProcessId** function retrieves the initiator process ID that is associated with a specified framework file object.

## Parameters

### `FileObject` [in]

A handle to a framework file object.

## Return value

Returns the initiator process identifier associated with the file, if any exists. Otherwise, the function returns zero.

## Remarks

Starting in Windows 8, a system component may issue a create on behalf of an application. The driver can call **WdfFileObjectGetInitiatorProcessId** to determine which process the create operation is ultimately intended for.

**WdfFileObjectGetInitiatorProcessId** returns zero if no initiator process is associated with the create operation.

## See also

[IWDFDevice3::GetInitiatorProcessId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdffile3-getinitiatorprocessid)

[WdfRequestGetRequestorProcessId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetrequestorprocessid)