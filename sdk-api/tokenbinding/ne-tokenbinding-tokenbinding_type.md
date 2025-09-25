# TOKENBINDING_TYPE enumeration

## Description

Specifies the possible types for a token binding.

## Constants

### `TOKENBINDING_TYPE_PROVIDED:0`

This type of Token Binding is used to protect tokens issued by the Identity Provider for the client to present with subsequent requests back to this Identity Provider.

### `TOKENBINDING_TYPE_REFERRED:1`

This type of Token Binding is used to protect tokens issued by the Identity Provider for the client to present to a Relying Party.

## Remarks

More information about the use of these Token Binding types can be found in the **Token Binding over HTTP Internet** draft.

## See also

[TokenBindingGenerateBinding](https://learn.microsoft.com/windows/desktop/api/tokenbinding/nf-tokenbinding-tokenbindinggeneratebinding)