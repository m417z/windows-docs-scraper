# WS_ERROR_PROPERTY_ID enumeration

## Description

A set of property values associated with the error. They are set
and retrieved using [WsGetErrorProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsgeterrorproperty) and
[WsSetErrorProperty](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsseterrorproperty).

## Constants

### `WS_ERROR_PROPERTY_STRING_COUNT:0`

The number of error strings (ULONG) available in the error object. Error strings
might be added using [WsAddErrorString](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsadderrorstring). When [WS_ERROR_PROPERTY_ORIGINAL_ERROR_CODE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_error_property_id) is present in the error object, the corresponding error text will be counted as an
additional string in the returned number of error strings.

 This property is read only.

### `WS_ERROR_PROPERTY_ORIGINAL_ERROR_CODE:1`

If the error returned from the function was mapped to one of the
standard WS_E_* errors, then this property is used to store the original
implementation specific error code.

Note that the original error code is specific to a particular implementation and version of the underlying libraries used by WWSAPI. It should not be
expected to remain constant, as the libraries may change.

The main purpose in exposing this error is for diagnostic purposes, as the application may
take a look at original error code of underlying library that caused this error.

Applications that take specific action based on the implementation
specific error code will likely be broken when the implementation changes.

If the error was not mapped from an implementation specific value
to a standard error, then this property will have the value NOERROR.

The default value is NOERROR.

### `WS_ERROR_PROPERTY_LANGID:2`

This identifies the language of any language sensitive information
in the error object.

This value may not be zero.

This value may only be set when the error object is first created, or
after it has been reset using [WsResetError](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsreseterror).