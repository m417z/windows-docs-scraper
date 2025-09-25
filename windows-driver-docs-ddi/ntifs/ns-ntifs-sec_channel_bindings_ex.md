## Description

The **SEC_CHANNEL_BINDINGS_EX** structure is used to provide channel binding information for a security context.

## Members

### `magicNumber`

Contains SEC_CHANNEL_BINDINGS_VERSION_2. This member ensures that the structure is correctly identified as an extended version, preventing misinterpretation as a standard channel bindings buffer.

### `flags`

Specifies additional options for channel bindings. The following flag is defined.

| Flag | Description |
|------|-------------|
| SEC_CHANNEL_BINDINGS_VALID_FLAGS | Indicates that auditing is required for operations involving these channel bindings. |

### `cbHeaderLength`

Length in bytes of the header portion of the structure.

### `cbStructureLength`

Total length in bytes of the entire structure, including the header and all channel binding data.

### `dwInitiatorAddrType`

Address type of the initiator, indicating the format of the initiator's address.

### `cbInitiatorLength`

Length in bytes of the initiator's address data.

### `dwInitiatorOffset`

Offset in bytes from the start of structure to the initiator's address data.

### `dwAcceptorAddrType`

Address type of the acceptor, indicating the format of the acceptor's address.

### `cbAcceptorLength`

Length in bytes of the acceptor's address data.

### `dwAcceptorOffset`

Offset in bytes from the start of the structure to the acceptor's address data.

### `cbApplicationDataLength`

Length in bytes of the application-specific data.

### `dwApplicationDataOffset`

Offset in bytes from the start of the structure to the application-specific data.