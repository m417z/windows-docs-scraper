# ber_skip_tag function

## Description

The **ber_skip_tag** function skips the current tag and returns the tag of the next element in the supplied [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure.

## Parameters

### `pBerElement` [in]

Pointer to the source [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure.

### `pLen` [out]

Returns the length of the skipped element.

## Return value

Returns the tag of the next element in the [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure. LBER_DEFAULT is returned if there is no further data to read.

## Remarks

This function is similar to
[ber_peek_tag](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_peek_tag), except that the state pointer, in the
[BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) argument, is advanced past the first tag and length, and is pointed to the value part of the next element. This routine should only be used with constructed types and situations when a BER encoding is used as the value of an OCTET STRING.

## See also

[ber_first_element](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_first_element)

[ber_next_element](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_next_element)

[ber_peek_tag](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_peek_tag)