# TOKENBINDING_IDENTIFIER structure

## Description

Contains the information for representing a token binding identifier that results from a token binding message exchange.

## Members

### `keyType`

#### - bindingType

The type of the token binding.

#### - hashAlgorithm

The hash algorithm for the token binding. The value of this member is always **TOKENBINDING_HASH_ALGORITHM_SHA256**.

#### - signatureAlgorithm

The signature algorithm for the token binding. The following values are possible for this member.

#### TOKENBINDING_SIGNATURE_ALGORITHM_RSA (1)

#### TOKENBINDING_SIGNATURE_ALGORITHM_ECDSAP256 (3)

## See also

[TOKENBINDING_RESULT_DATA](https://learn.microsoft.com/windows/desktop/api/tokenbinding/ns-tokenbinding-tokenbinding_result_data)