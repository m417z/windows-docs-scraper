# ber_peek_tag function

## Description

The **ber_peek_tag** function returns the tag of the next element to be parsed in the supplied [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure.

## Parameters

### `pBerElement` [in]

Pointer to the source [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure.

### `pLen` [out]

Returns the length of the next element to be parsed.

## Return value

Returns the tag of the next element to be read in the [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure. LBER_DEFAULT is returned if there is no further data to be read.

## Remarks

The decoding position within the *pBerElement* parameter is unchanged by this call; that is, the fact that **ber_peek_tag** has been called does not affect future use of the [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure.

## See also

[ber_first_element](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_first_element)

[ber_next_element](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_next_element)

[ber_skip_tag](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_skip_tag)