# FAX_ACCOUNT_EVENTS_TYPE_ENUM enumeration

## Description

Specifies the types of event notifications, on a particular account, that the server sends to listening clients.

## Constants

### `faetNONE:0`

No notifications are sent.

### `faetIN_QUEUE:0x1`

Notifications of changes to the state of any fax in the incoming queue are sent.

### `faetOUT_QUEUE:0x2`

Notifications of changes to the state of any fax in the outgoing queue are sent.

### `faetIN_ARCHIVE:0x4`

A notification is sent whenever a message is removed from the incoming fax archive.

### `faetOUT_ARCHIVE:0x8`

A notification is sent whenever a message is removed from the outgoing fax archive.

### `faetFXSSVC_ENDED:0x10`

A notification is sent whenever the fax service stops executing.

## Remarks

The following table lists the [IFaxAccountNotify](https://learn.microsoft.com/windows/win32/api/faxcomex/nn-faxcomex-_ifaxaccountnotify) methods called by each member of the enumeration:

| Member | Methods Called |
| --- | --- |
| faetNONE | none |
| faetIN_QUEUE | OnIncomingJobAddedOnIncomingJobRemovedOnIncomingJobChanged |
| faetOUT_QUEUE | OnOutgoingJobAddedOnOutgoingJobRemovedOnOutgoingJobChanged |
| faetIN_ARCHIVE | OnIncomingMessageAddedOnIncomingMessageRemoved |
| faetOUT_ARCHIVE | OnOutgoingMessageAddedOnOutgoingMessageRemoved |
| faetFXSSVC_ENDED | OnServerShutDown |