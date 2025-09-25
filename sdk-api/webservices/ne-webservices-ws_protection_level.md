# WS_PROTECTION_LEVEL enumeration

## Description

Defines the required integrity and confidentiality levels for sent and
received messages. With transport and mixed-mode security bindings,
this setting applies to each message as a whole. With message
security, the protection level is specified at the granularity of a
message header or body. The default value defined applies only to
transport and mixed-mode security.

## Constants

### `WS_PROTECTION_LEVEL_NONE:1`

No signing or encryption.

### `WS_PROTECTION_LEVEL_SIGN:2`

Only signing.

### `WS_PROTECTION_LEVEL_SIGN_AND_ENCRYPT:3`

Signing and encryption.