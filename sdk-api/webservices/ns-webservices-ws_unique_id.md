# WS_UNIQUE_ID structure

## Description

Represents a unique ID URI.

## Members

### `uri`

A string representation of the URI. If length is zero,
then the unique ID is a guid, and the value is stored
in the guid field. Otherwise, the URI is a string
and the string value is stored in the uri field.

### `guid`

If the uri.length field is 0, then this field contains
the GUID representation of the unique ID. Otherwise
the value of the field is not defined.

## Remarks

This structure represents a URI that is used as a unique ID.
It has native support for GUID-based URI's, but can also
accommodate other unique-id URI's as a string.