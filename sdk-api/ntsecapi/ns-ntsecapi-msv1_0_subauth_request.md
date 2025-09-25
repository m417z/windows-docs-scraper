# MSV1_0_SUBAUTH_REQUEST structure

## Description

The **MSV1_0_SUBAUTH_REQUEST** structure contains information to pass to a [subauthentication package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

It is used by
[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage).

## Members

### `MessageType`

[MSV1_0_PROTOCOL_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-msv1_0_protocol_message_type) value identifying the type of request being made. This member should be set to **MsV1_0SubAuth** for local subauthentication and **MsV1_0GenericPassthrough** for subauthentication on the domain controller.

### `SubAuthPackageId`

Contains a [subauthentication package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) identifier. The value of subauthentication package identifiers is established by the creator of the subauthentication package.

### `SubAuthInfoLength`

Indicates the length, in bytes, of the buffer passed to the subauthentication package in **SubAuthSubmitBuffer**.

### `SubAuthSubmitBuffer`

Containing the data to pass to the subauthentication package. The format and content of this data is specific to the subauthentication package. For more information, see the documentation for specific subauthentication packages.