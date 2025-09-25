# CTL_ENTRY structure

## Description

The **CTL_ENTRY** structure is an element of a [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTL).

## Members

### `SubjectIdentifier`

[BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) containing a unique identifier of a subject. It can be a [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) or any unique byte sequence.

### `cAttribute`

Count of elements in the **rgAttribute** member array.

### `rgAttribute`

Array of
[CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute) structures, each holding information about the subject.

## See also

[CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CTL_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_info)