# WS_CHANNEL_PROPERTIES structure

## Description

Specifies a set of [WS_CHANNEL_PROPERTY](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_channel_property) structures.

## Members

### `properties`

An array of properties. The number of elements in the array is specified
using the propertyCount parameter. This field may be **NULL** if the propertyCount
is 0.

### `propertyCount`

The number of elements in the properties array.