# EVENT_EXTENDED_ITEM_RELATED_ACTIVITYID structure (evntcons.h)

## Description

Defines the parent event of this event.

## Members

### `RelatedActivityId`

A GUID that uniquely identifies the parent activity to which this activity is related. The identifier is specified in the *RelatedActivityId* parameter passed to the [EventWriteTransfer](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventwritetransfer) function.

## See also

[EVENT_HEADER_EXTENDED_DATA_ITEM](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header_extended_data_item)

[EventWriteTransfer](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventwritetransfer)