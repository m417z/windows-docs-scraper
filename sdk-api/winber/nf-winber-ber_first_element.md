# ber_first_element function

## Description

The **ber_first_element** function is used to begin the traversal of a SET, SET OF, SEQUENCE or SEQUENCE OF data value stored in the supplied [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure. It returns the tag and length of the first element.

## Parameters

### `pBerElement` [in]

Pointer to the source [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure.

### `pLen` [out]

Returns the length of the next element to be parsed.

### `ppOpaque` [out]

Returns a pointer to a cookie that is passed to subsequent calls of the
[ber_next_element](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_next_element) function.

## Return value

Returns the tag of the next element to be read in the [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure. LBER_DEFAULT is returned if there is no further data to be read.

## Remarks

The *pLen* and *ppOpaque* values returned by the function are internal parsing state values, and should not be used by applications other than as arguments to [ber_next_element](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_next_element).

## See also

[ber_next_element](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_next_element)

[ber_peek_tag](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_peek_tag)

[ber_skip_tag](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_skip_tag)