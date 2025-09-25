# WS_USERNAME_MESSAGE_SECURITY_BINDING_TEMPLATE structure

## Description

The security binding template for specifying the use of an application
supplied username / password pair as a direct (i.e., one-shot)
security token. This security binding may be used only with message
security. It provides client authentication, but not traffic signing
or encryption. So, it is used in conjunction with another transport
security or message security binding that provides message protection.

See also [WS_USERNAME_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_username_message_security_binding)

## Members

### `securityBindingProperties`

Application provided security binding properties that cannot be represented in policy.

### `clientCredential`

The username credential to be used with this security binding. This
needs to be specified when this security binding is used on the
client.

### `passwordValidator`

The validator to be used to check received username/password pairs.
This needs to be specified when this security binding is used on the
service.

### `passwordValidatorCallbackState`

The optional state to be passed in as an argument when the username validator is invoked.