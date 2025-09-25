# EVENT_FILTER_LEVEL_KW structure

## Description

The **EVENT_FILTER_LEVEL_KW** structure defines event IDs used in an
[EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor)
structure for a stack walk level-keyword filter.

This filter is only applied to events that are otherwise enabled on the logging
session, via a level/keyword in the enable call.

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

**true** to filter the events matching the provided names in; **false** to
filter them out.

If set to **true**, the filtered events will have stacks collected.