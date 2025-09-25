# _WIAS_ENDORSER_INFO structure

## Description

The **WIAS_ENDORSER_INFO** structure holds custom endorser token/value pairs.

## Members

### `ulPageCount`

Specifies the value that will replace the $PAGE_COUNT$ token, provided that the endorser string contains that token.

### `ulNumEndorserValues`

Specifies the number of token/value pairs. This member will be 0 if there are no custom token/value pairs.

### `pEndorserValues`

Points to an array of [WIAS_ENDORSER_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wias_endorser_value) structures, holding custom token/value pairs. If the value of the **ulNumEndorserValues** member is 0, this member should be **NULL**.

## Remarks

Currently, [wiasParseEndorserString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasparseendorserstring) recognizes three endorser tokens: $DATE$, $TIME$, $PAGE_COUNT$, $DAY$, $MONTH$, and $YEAR$. (See *wiamdef.h*.) Any other tokens and their values must be specified in the **pEndorserValues** member of this structure.

## See also

[WIAS_ENDORSER_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/ns-wiamindr_lh-_wias_endorser_value)

[wiasParseEndorserString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wiasparseendorserstring)