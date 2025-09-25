# WsCreateXmlSecurityToken function

## Description

Creates a security token from its specified XML form.

## Parameters

### `tokenXml` [in]

Pointer to a [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer) structure containing the security token in its XML form. The referenced buffer must have exactly
one top level XML element.

### `tokenKey` [in, optional]

Pointer to a **SECURITY_KEY_HANDLE** structure that may or may not contain a cryptographic proof-of-possession key. If present the key can be used to bind
this security token to a message. If the value of the *tokenKey* parameter is not **NULL**, the token is
assumed to have a proof-of-possession key. If the value is **NULL**, the structure is
assumed to be a "bearer token" as defined below.

* A bearer token also called a basic or keyless token is serialized in a message to demonstrate
  the message's possession of the token, and to indicate the intention to apply the claims from the token to that message.
* A proof-of-possession token also called a PoP or
  cryptographic token has an associated
  cryptographic key which must be used to "sign" a message in order to
  demonstrate possession of the token and to indicate the intention to
  apply the claims from the token to that message. An example is an
  X.509 certificate: the message must be signed with the private key of
  the certificate in order for a receiving principal to accept the
  message as carrying the claims present in the certificate.

### `properties`

An array of [WS_XML_SECURITY_TOKEN_PROPERTY](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_security_token_property) structures containing optional properties for the XML security token.

The value of this parameter may be **NULL**, in which case, the *propertyCount* parameter must be 0 (zero).

### `propertyCount` [in]

The number of properties in the *properties* array.

### `token`

On success, a pointer that receives the address of the [WS_SECURITY_TOKEN](https://learn.microsoft.com/windows/desktop/wsw/ws-security-token) structure representing the created XML security token.
When you no longer need this structure, you must free it by calling [WsFreeSecurityToken](https://learn.microsoft.com/windows/desktop/api/webservices/nf-webservices-wsfreesecuritytoken).

The returned security token may be used with [WS_XML_TOKEN_MESSAGE_SECURITY_BINDING](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_xml_token_message_security_binding) if it is to be

presented to a service.

### `error` [in, optional]

Pointer to a [WS_ERROR](https://learn.microsoft.com/windows/desktop/wsw/ws-error) structure that receives additional error information if the function fails.

## Return value

If the function succeeds, it returns NO_ERROR; otherwise, it returns an HRESULT error code.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are invalid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **Other Errors** | This function may return other errors not listed above. |