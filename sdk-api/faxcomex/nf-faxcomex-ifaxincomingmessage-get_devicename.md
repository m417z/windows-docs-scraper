# IFaxIncomingMessage::get_DeviceName

## Description

The **DeviceName** property is a null-terminated string that contains the name of the device on which the inbound fax message was received.

This property is read-only.

## Parameters

## Remarks

This method returns the name of the fax device rather than the device ID. This is useful because an administrator may remove the device ID after completion of the fax job and before the client's query of the archive of inbound fax messages.

## See also

[FaxIncomingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage)

[IFaxIncomingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingmessage)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-the-incoming-archive)