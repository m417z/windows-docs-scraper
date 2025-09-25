## Description

The **SEC_CHANNEL_BINDINGS_RESULT** structure is used to represent the outcome of channel bindings verification in secure communication protocols.

## Members

### `flags`

Flags related to the channel bindings result. This field is a bitwise OR of the following values:

| Flag | Description |
| ---- | ----------- |
| SEC_CHANNEL_BINDINGS_RESULT_CLIENT_SUPPORT (0x1) | Indicates that the authentication package requires client versions to support channel bindings. |
| SEC_CHANNEL_BINDINGS_RESULT_ABSENT (0x2) | Indicates that the channel bindings are either omitted or consist entirely of zeroes. |
| SEC_CHANNEL_BINDINGS_RESULT_NOTVALID_MISMATCH (0x4) | Indicates that the channel binding hash was incorrect, suggesting a mismatch between expected and actual bindings. |
| SEC_CHANNEL_BINDINGS_RESULT_NOTVALID_MISSING (0x8) | Indicates that missing channel bindings are not allowed for this client, and their absence is considered invalid. |
| SEC_CHANNEL_BINDINGS_RESULT_VALID_MATCHED (0x10) | Indicates that the client and server channel bindings match, confirming the validity of the bindings. |
| SEC_CHANNEL_BINDINGS_RESULT_VALID_PROXY (0x20) | Indicates that the ASC_REQ_PROXY_BINDINGS flag required the client to provide a binding, and this requirement was met. |
| SEC_CHANNEL_BINDINGS_RESULT_VALID_MISSING (0x40) | Indicates that the client is permitted to have missing bindings, as allowed by the ASC_REQ_ALLOW_MISSING_BINDINGS flag. |