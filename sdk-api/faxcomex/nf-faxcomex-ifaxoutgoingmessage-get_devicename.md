# IFaxOutgoingMessage::get_DeviceName

## Description

The **IFaxOutgoingMessage::get_DeviceName** property is a null-terminated string that contains the name of the device on which the fax message was transmitted.

This property is read-only.

## Parameters

## Remarks

This method returns the name of the fax device rather than the device ID. This is useful because an administrator may remove the device ID after completion of the fax job and before the client's query of the archive of fax messages.

## See also

[FaxOutgoingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingmessage)

[IFaxOutgoingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingmessage)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-opening-a-fax-from-the-outgoing-archive)