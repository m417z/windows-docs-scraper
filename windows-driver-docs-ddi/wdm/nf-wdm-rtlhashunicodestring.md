# RtlHashUnicodeString function

## Description

The **RtlHashUnicodeString** routine creates a hash value from a given Unicode string and hash algorithm.

## Parameters

### `String` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the Unicode string to be converted to a hash value.

### `CaseInSensitive` [in]

Specifies whether to treat the Unicode string as case sensitive when computing the hash value. If *CaseInSensitive* is **TRUE**, a lowercase and uppercase string hash to the same value.

### `HashAlgorithm` [in]

The hash algorithm to use. If *HashAlgorithm* is HASH_STRING_ALGORITHM_X65599, **RtlHashUnicodeString** uses the x65599 hashing algorithm. If *HashAlgorithm* is HASH_STRING_ALGORITHM_DEFAULT, **RtlHashUnicodeString** uses the default algorithm. Currently, the default algorithm is the x65599 hashing algorithm.

### `HashValue` [out]

A pointer to a ULONG variable that receives the hash value.

## Return value

**RtlHashUnicodeString** returns STATUS_SUCCESS on success, or the appropriate NTSTATUS value on failure. The routine returns a STATUS_INVALID_PARAMETER value if the Unicode string is **NULL**, *HashValue* is **NULL**, or the caller specifies an undefined value for *HashAlgorithm*.

## See also

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)