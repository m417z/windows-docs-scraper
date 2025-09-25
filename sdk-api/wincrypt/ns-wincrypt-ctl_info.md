# CTL_INFO structure

## Description

The **CTL_INFO** structure contains the information stored in a [Certificate Trust List](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL).

## Members

### `dwVersion`

The CTL's version number. Currently defined version numbers are shown in the following table.

| Value | Meaning |
| --- | --- |
| **CTL_V1** | Version 1 |

### `SubjectUsage`

[CTL_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage) structure identifying the intended usage of the list as a sequence of object identifiers. This is the same as in the [Enhanced Key Usage](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly) extension.

### `ListIdentifier`

A
[CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that includes a byte string that uniquely identifies the list. This member is used to augment the **SubjectUsage** and further specifies the list when desired.

### `SequenceNumber`

A [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) that contains a monotonically increasing number for each update of the CTL.

### `ThisUpdate`

Indication of the date and time of the [certificate revocation lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRLs) published. If the time is after 1950 and before 2050, it is UTC-time encoded as an 8-byte date/time precise to seconds with a 2-digit year (that is, YYMMDDHHMMSS plus 2 bytes). Otherwise, it is generalized-time encoded as an 8-byte year precise to milliseconds with a 4-byte year.

### `NextUpdate`

Indication of the date and time for the CRL's next available scheduled update. If the time is after 1950 and before 2050, it is UTC-time encoded as an 8-byte date/time precise to seconds with a 2-digit year (that is, YYMMDDHHMMSS plus 2 bytes). Otherwise, it is generalized-time encoded as an 8-byte date time precise to milliseconds with a 4-byte year.

### `SubjectAlgorithm`

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that contains the algorithm type of the **SubjectIdentifier** in [CTL_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_entry) members of the **rgCTLEntry** member array. The structure also includes additional parameters used by the algorithm.

### `cCTLEntry`

Number of elements in the **rgCTLEntry** member array.

### `rgCTLEntry`

Array of
[CTL_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_entry) structures.

### `cExtension`

Number of elements in the **rgExtension** array.

### `rgExtension`

Array of
[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension) structures.

## See also

[CERT_EXTENSION](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_extension)

[CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context)

[CTL_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_entry)

[CTL_USAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_usage)