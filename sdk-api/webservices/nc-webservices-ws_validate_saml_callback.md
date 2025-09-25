# WS_VALIDATE_SAML_CALLBACK callback function

## Description

Validates a SAML assertion. If a
received SAML assertion passes the signature verification checks that
ensure the SAML was issued by a trusted issuer, then this callback is
invoked to enable the application to do additional validation on the
XML form of the SAML assertion. This callback is expected to return
S_OK if the SAML assertion was successfully validated, S_FALSE when
the assertion could not be validated and an error value if an
unexpected error occurred. Returning any result other than S_OK from
this callback will result in the associated receive message failing
with a security error.

As with all security callbacks, the application should expect to
receive this callback any time between listener open and close, but it
will never be invoked when a listener is not open.

## Parameters

### `samlValidatorCallbackState` [in, optional]

The state to be passed back when invoking this callback.

### `samlAssertion` [in]

The received SAML assertion that has undergone a successful signature check.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This callback function does not return a value.