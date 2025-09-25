# MSV1_0_SUBAUTH_RESPONSE structure

## Description

The **MSV1_0_SUBAUTH_RESPONSE** structure contains the response from a [subauthentication package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

It is used by
[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage).

## Members

### `MessageType`

[MSV1_0_PROTOCOL_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-msv1_0_protocol_message_type) value identifying the type of request being made. This member must be set to **MsV1_0SubAuth**.

### `SubAuthInfoLength`

Indicates the length, in bytes, of the buffer returned by **SubAuthReturnBuffer**.

### `SubAuthReturnBuffer`

Contains the subauthentication package response. The format and content of this buffer is specific to the subauthentication package. For more information, see the documentation for specific subauthentication packages.