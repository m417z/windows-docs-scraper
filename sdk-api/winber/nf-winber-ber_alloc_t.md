# ber_alloc_t function

## Description

The **ber_alloc_t** function allocates and constructs a new
[BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure.

## Parameters

### `options` [in]

A bitwise OR of the options used to generate the encoding or decoding of the **BerElement**. The **LBER_USE_DER** flag (0x01) should always be specified, which causes the element lengths to be encoded in the minimum number of octets.

Unrecognized option bits are ignored.

## Return value

If the function succeeds, the return value is a pointer to the newly allocated [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure.

If the function fails, it returns a **NULL** pointer.

## Remarks

The **LBER_USE_DER** option does not cause values of sets to be rearranged in tag and byte order or default values to be removed, so these functions are not sufficient for generating DER output as defined in X.509 and X.680. If the caller handles ordering values of sets correctly and removing default values, DER output as defined in X.509 and X.680 can be produced.

The allocated **BerElement** should be freed with [ber_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_free).

## See also

[BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ber_free](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_free)

[ber_printf](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_printf)