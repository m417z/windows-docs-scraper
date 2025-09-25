# BCRYPT_ALGORITHM_IDENTIFIER structure

## Description

The **BCRYPT_ALGORITHM_IDENTIFIER** structure is used with the [BCryptEnumAlgorithms](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptenumalgorithms) function to contain a [cryptographic algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) identifier.

## Members

### `pszName`

A pointer to a null-terminated Unicode string that contains the string identifier of the algorithm. The [CNG Algorithm Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-algorithm-identifiers) topic contains the predefined algorithm identifiers.

### `dwClass`

Specifies the class of the algorithm. This can be one of the [CNG Interface Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-interface-identifiers).

### `dwFlags`

A set of flags that specify other information about the algorithm. There are currently no flags defined for this member.

## See also

[BCryptEnumAlgorithms](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptenumalgorithms)