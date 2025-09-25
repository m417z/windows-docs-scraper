# EVENT_FILTER_EVENT_NAME structure

## Description

The **EVENT_FILTER_EVENT_NAME** structure defines event IDs used in an
[EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor)
structure for an event name or stalk walk name filter.

This filter will only be applied to events that are otherwise enabled on the
logging session, via level/keyword in the enable call.

## Members

### `MatchAnyKeyword`

Bitmask of keywords that determine the category of events to filter on.

### `MatchAllKeyword`

This bitmask is optional. This mask further restricts the category of events
that you want to filter on. If the event's keyword meets the **MatchAnyKeyword**
condition, the provider will filter the event only if all of the bits in this
mask exist in the event's keyword. This mask is not used if **MatchAnyKeyword**
is zero.

### `Level`

Defines the severity level of the event to filter on.

### `FilterIn`

**True** to filter the events matching the provided names in; **false** to
filter them out.

When used for the **EVENT_FILTER_TYPE_STACKWALK_NAME**filter type, the filtered
in events will have stacks collected for them.

### `NameCount`

The number of names in the **Names** member.

### `Names`

An **NameCount** long array of null-terminated, UTF-8 event names.

## Remarks