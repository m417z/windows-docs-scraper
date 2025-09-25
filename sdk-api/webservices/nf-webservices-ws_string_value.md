# WS_STRING_VALUE macro

## Description

Initializes a [WS_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_string) structure given a constant string.

## Parameters

### `S`

The initializer string.

## Remarks

The initializer string is assumed to be zero terminated.

#### Examples

The following is an example of how to use the macro.

`WS_STRING myString = WS_STRING_VALUE(L"MyString");`