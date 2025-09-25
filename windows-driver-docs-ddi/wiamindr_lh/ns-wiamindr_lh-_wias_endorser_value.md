# _WIAS_ENDORSER_VALUE structure

## Description

The WIAS_ENDORSER_VALUE structure stores token/value pairs for endorser strings.

## Members

### `wszTokenName`

Specifies a string value that represents the token name. Endorser token names begin and end with the $ character (for example, L"$MY_TOKEN_NAME$").

### `wszValue`

Specifies the value with which to replace the token.

## Remarks

This structure is used indirectly by the [wiasParseEndorserString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasparseendorserstring) function. One of the parameters of this function is a [WIAS_ENDORSER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wias_endorser_info) structure, which has a WIAS_ENDORSER_VALUE structure as one of its members.

## See also

[WIAS_ENDORSER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wias_endorser_info)

[wiasParseEndorserString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasparseendorserstring)