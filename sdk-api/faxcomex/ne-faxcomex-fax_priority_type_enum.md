# FAX_PRIORITY_TYPE_ENUM enumeration

## Description

The **FAX_PRIORITY_TYPE_ENUM** enumeration defines the types of priorities for outbound faxes.

## Constants

### `fptLOW:0`

The fax will be sent with a low priority. All faxes that have a normal or a high priority will be sent before a fax that has a low priority.

### `fptNORMAL`

The fax will be sent with a normal priority. All faxes that have a high priority will be sent before a fax that has a normal priority.

### `fptHIGH`

The fax will be sent with a high priority.

## See also

[IFaxDocument::get_Priority](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument-priority-vb)

[IFaxOutgoingJob::get_Priority](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjob-priority-vb)

[IFaxOutgoingMessage::get_Priority](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingmessage-priority-vb)