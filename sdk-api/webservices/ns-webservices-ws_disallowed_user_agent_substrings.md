# WS_DISALLOWED_USER_AGENT_SUBSTRINGS structure

## Description

Specifies the list of blocked UserAgent sub-string's. This is
used with the [WS_LISTENER_PROPERTY_DISALLOWED_USER_AGENT](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_listener_property_id)
listener property.

## Members

### `subStringCount`

The number of items in 'prefixes'.

### `subStrings`

An array of WS_STRING*. Each WS_STRING* would be searched as a sub-string in the UserAgent HTTP header value.