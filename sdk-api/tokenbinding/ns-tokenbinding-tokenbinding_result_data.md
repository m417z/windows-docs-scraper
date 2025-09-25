# TOKENBINDING_RESULT_DATA structure

## Description

Contains data about the result of generating a token binding or verifying one of the token bindings in a token binding message.

## Members

### `bindingType`

### `identifierSize`

The size of the [TOKENBINDING_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/tokenbinding/ns-tokenbinding-tokenbinding_identifier) structure that the **identifierData** member points to, in bytes.

### `identifierData`

Pointer to the token binding identifier for the token binding that was generated or verified.

### `extensionFormat`

The format to use to interpret the data in the *extensionData* parameter. This value must be **TOKENBINDING_EXTENSION_FORMAT_UNDEFINED**.

### `extensionSize`

The size of the buffer that the **extensionData** member points to, in bytes.

### `extensionData`

A pointer to a buffer that contains extension data. The value of the *extensionFormat* parameter determines how to interpret this data.

## See also

[TOKENBINDING_EXTENSION_FORMAT](https://learn.microsoft.com/windows/desktop/api/tokenbinding/ne-tokenbinding-tokenbinding_extension_format)

[TOKENBINDING_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/tokenbinding/ns-tokenbinding-tokenbinding_identifier)

[TOKENBINDING_RESULT_LIST](https://learn.microsoft.com/windows/desktop/api/tokenbinding/ns-tokenbinding-tokenbinding_result_list)

[TokenBindingGenerateBinding](https://learn.microsoft.com/windows/desktop/api/tokenbinding/nf-tokenbinding-tokenbindinggeneratebinding)

[TokenBindingVerifyMessage](https://learn.microsoft.com/windows/desktop/api/tokenbinding/nf-tokenbinding-tokenbindingverifymessage)