# ber_printf function

## Description

The **ber_printf** function is used to encode a BER element and is similar to sprintf_s. One important difference is that state data is stored in the **BerElement** argument so that multiple calls can be made to **ber_printf** to append to the end of the BER element. The **BerElement** argument passed to this function must be a pointer to a **BerElement** returned by
[ber_alloc_t](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_alloc_t).

## Parameters

### `pBerElement` [in, out]

A pointer to the encoded [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement) structure.

### `fmt` [in]

An encoding format string. For more information, see Remarks.

### `...`

The values to be encoded as specified by the *fmt* argument.

## Return value

If the function succeeds, a non-negative number is returned. If the function fails, -1 is returned.

## Remarks

The format string can contain format characters listed in the following table.

| Character | Description |
| --- | --- |
| **t** | **Tag**. The next argument is a **ber_tag_t** that specifies the tag to override the next element written to the [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement). This works across calls. |
| **b** | **Boolean**. The next argument is an **ber_int_t**, that contains either 0 for **FALSE** or 1 for **TRUE**. A Boolean element is output. If this format character is not preceded by the **t** format modifier, the tag 0x01U is used for the element. |
| **e** | **Enumerated**. The next argument is a **ber_int_t**, that contains the enumerated value. An enumerated element is output. If this format character is not preceded by the **t** format modifier, the tag 0x0AU is used for the element. |
| **i** | **Integer**. The next argument is a **ber_int_t**, that contains the integer value. An integer element is output. If this format character is not preceded by the **t** format modifier, the tag 0x02U is used for the element. |
| **n** | **Null**. No argument is required. An ASN.1 NULL element is output. If this format character is not preceded by the **t** format modifier, the tag 0x05U is used for the element. |
| **o** | **Octet string**. The next two arguments are a **char***, followed by a **ber_len_t** with the length of the string. The string may contain **NULL** bytes and do not have to be zero-terminated. An octet string element is output and no character format conversions on the string data is performed. Passing a **NULL** pointer followed by a length of 0 is acceptable if a **NULL** octet string element is required. If this format character is not preceded by the **t** format modifier, the tag 0x04U is used for the element. |
| **s** | **Octet string**. The next argument is a **char*** pointing to a zero-terminated ANSI character string. The ANSI string characters are converted to UTF-8 format and an octet string element is output, which does not include the trailing '\0' (null) byte. Passing a **NULL** pointer is acceptable if a **NULL** octet string element is required. If this format character is not preceded by the **t** format modifier, the tag 0x04U is used for the element. |
| **v** | **Several octet strings**. The next argument is a **char****, an array of **char*** pointers to zero-terminated ANSI strings. The last element in the array must be a **NULL** pointer. The octet strings do not include the trailing '\0' (null) byte. Be aware that a construct like **{****v****}** is used to get an actual SEQUENCE OF octet strings. The **t** format modifier cannot be used with this format character. |
| **V** | **Several octet strings**. A NULL-terminated array of [berval*](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval) is supplied. Be aware that a construct like **{****v****}** is used to get an actual SEQUENCE OF octet strings. The **t** format modifier cannot be used with this format character. |
| **X** | **Bitstring**. The next two arguments are a **char*** pointer to the start of the bitstring, followed by a **ber_len_t** that contains the number of bits in the bitstring. A bitstring element is output. If this format character is not preceded by the **t** format modifier, the tag 0x03U is used for the element. |
| **{** | **Begin sequence**. No argument is required. If this format character is not preceded by the **t** format modifier, the tag 0x30U is used. |
| **}** | **End sequence**. No argument is required. The **t** format modifier cannot be used with this format character. |
| **[** | **Begin set**. No argument is required. If this format character is not preceded by the **t** format modifier, the tag 0x31U is used. |
| **]** | **End set**. No argument is required. The **t** format modifier cannot be used with this format character. |

Each left brace (**{**) character must be paired with a right brace (**}**) character later in the format string, or in the format string of a subsequent call to **ber_printf** for that specific [BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement). The same applies to the left bracket ([) character and right bracket (]) characters.

## See also

[BerElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/winldap/ns-winldap-berelement)

[Functions](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/functions)

[ber_scanf](https://learn.microsoft.com/previous-versions/windows/desktop/api/winber/nf-winber-ber_scanf)

[berval](https://learn.microsoft.com/windows/win32/api/winldap/ns-winldap-ldap_berval)