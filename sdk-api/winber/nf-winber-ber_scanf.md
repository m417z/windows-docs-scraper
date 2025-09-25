# ber_scanf function

## Description

The **ber_scanf** function decodes a BER element in a similar manner as [sscanf_s](https://learn.microsoft.com/cpp/c-runtime-library/reference/sscanf-s-sscanf-s-l-swscanf-s-swscanf-s-l). One important difference is that some state status data is kept with the **BerElement** argument so that multiple calls can be made to **ber_scanf** to sequentially read from the BER element. The **BerElement** argument should be a pointer to a **BerElement** returned by [ber_init](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_init).

## Parameters

### `pBerElement` [in, out]

Pointer to the decoded [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure.

### `fmt` [in]

Encoding format string. For more information, see Remarks section.

### `...`

Pointers to variables used to hold the values decoded as specified by the *fmt* argument.

## Return value

On error, the function returns LBER_ERROR.

## Remarks

The function interprets the bytes according to the format string *fmt*, and stores the results in its additional arguments. The format string contains conversion specifications used to direct the interpretation of the BER element. The format string can contain characters listed in the following table.

| Character | Description |
| --- | --- |
| **a** | **Octet string**. A **char**** argument must be supplied. Memory is allocated, filled with the contents of the octet string, zero-terminated, and the pointer to the string is stored in the argument. The returned value should be freed using [ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree). The tag of the element must indicate the primitive form (constructed strings are not supported), but is otherwise ignored and discarded during the decoding. This format cannot be used with octet strings which could contain null bytes. |
| **O** | **Octet string**. A **berval**** argument must be supplied, which upon return points to an allocated **berval** that contains the octet string and its length. [ber_bvfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_bvfree) should be called to free the allocated memory. The tag of the element must indicate the primitive form (constructed strings are not supported), but is otherwise ignored during the decoding. |
| **b** | **Boolean**. A pointer to a **ber_int_t** must be supplied. The **ber_int_t** value stored will be 0 for FALSE or nonzero for TRUE. The tag of the element must indicate the primitive form, but is otherwise ignored during the decoding. |
| **e** | **Enumerated**. A pointer to a **ber_int_t** must be supplied. The tag of the element must indicate the primitive form but is otherwise ignored during the decoding. **ber_scanf** will return an error if the value of the enumerated value cannot be stored in a **ber_int_t**. |
| **i** | **Integer**. A pointer to a **ber_int_t** must be supplied. The tag of the element must indicate the primitive form, but is otherwise ignored during decoding. **ber_scanf** will return an error if the integer cannot be stored in a **ber_int_t**. |
| **B** | **Bitstring**. A **char**** argument must be supplied which will point to the allocated bits, followed by a **ber_len_t** * argument, which will point to the length (in bits) of the bitstring returned. [ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree) should be called to free the bitstring. The tag of the element must indicate the primitive form (constructed bitstrings are not supported), but is otherwise ignored during the decoding. |
| **n** | **Null**. No argument is required. The element is verified to have a zero-length value and is skipped. The tag is ignored. |
| **t** | **Tag**. A pointer to a **ber_tag_t** must be supplied. The **ber_tag_t** value stored will be the tag of the next element in the *pBerElement*, represented so it can be written using the **t** format of [ber_printf](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_printf). The decoding position within the *pBerElement* argument is unchanged by this. |
| **v** | **Several octet strings**. A **char***** argument must be supplied, which upon return points to an allocated null-terminated array of char *'s that contain the octet strings. **NULL** is stored if the sequence is empty. [ldap_memfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/nf-winldap-ldap_memfree) should be called to free each element of the array and the array itself. The tag of the sequence and of the octet strings are ignored. |
| **V** | **Several octet strings** (which could contain null bytes). A **berval***** must be supplied, which upon return points to an allocated NULL-terminated array of **berval***'s containing the octet strings and their lengths. **NULL** is stored if the sequence is empty. [ber_bvecfree](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_bvecfree) can be called to free the allocated memory. The tag of the sequence and of the octet strings are ignored. |
| **x** | **Skip element**. The next element is skipped. No argument is required. |
| **{** | **Begin sequence**. No argument is required. The initial sequence tag and length are skipped. |
| **}** | **End sequence**. No argument is required. |
| **[** | **Begin set**. No argument is required. The initial set tag and length are skipped. |
| **]** | **End set**. No argument is required. |

## See also

[BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ber_printf](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_printf)

[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval)