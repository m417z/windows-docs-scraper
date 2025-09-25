# WS_STRING structure

## Description

An array of Unicode characters and a length.

## Members

### `length`

The number of characters in the string.

### `chars`

The array of characters that make up the string.

## Remarks

The string is not required to be zero terminated. If it is
zero terminated, then the terminating character is not included
in the length.

The macro [WS_STRING_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-ws_string_value) can be used to initialize
this structure if the string is a constant string.