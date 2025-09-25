# TOKENBINDING_KEY_TYPES structure

## Description

Contains all of the combinations of types of token binding keys that a client device or server supports.

## Members

### `keyCount`

The number of elements in the array that the **key** member contains.

### `keyType`

#### - key

An array of all of the combinations of types of token binding keys that a client device or server supports. These keys map one-to-one to Application Layer Protocol Negotiation (ALPN) protocol identifiers. You must maintain the table of these mappings.

## See also

[TokenBindingGetKeyTypesClient](https://learn.microsoft.com/windows/desktop/api/tokenbinding/nf-tokenbinding-tokenbindinggetkeytypesclient)

[TokenBindingGetKeyTypesServer](https://learn.microsoft.com/windows/desktop/api/tokenbinding/nf-tokenbinding-tokenbindinggetkeytypesserver)