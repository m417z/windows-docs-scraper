# ber_next_element function

## Description

The **ber_next_element** function is used along with
[ber_first_element](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_first_element) to traverse a SET, SET OF, SEQUENCE or SEQUENCE OF data value stored in the supplied [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure. It returns the tag and length of the next element in the constructed type.

## Parameters

### `pBerElement` [in]

Pointer to the source [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure.

### `pLen` [in, out]

Returns the length of the next element to be parsed.

### `opaque` [in, out]

An opaque cookie used internally that was returned by the initial call to the
[ber_first_element](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_first_element) function.

## Return value

Returns the tag of the next element to be read in the [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure. LBER_DEFAULT is returned if there is no further data to be read.

## Remarks

The *pLen* and *opaque* pointer values returned by the function are internal parsing state values, and should not be used by applications other than as arguments to subsequent calls of this function.

## See also

[ber_first_element](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_first_element)

[ber_peek_tag](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_peek_tag)

[ber_skip_tag](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_skip_tag)