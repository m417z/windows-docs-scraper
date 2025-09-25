# LDAP_BERVAL structure

## Description

The **berval** structure represents arbitrary binary data that is encoded according to Basic Encoding Rules (BER). Use a **berval** to represent any attribute that cannot be represented by a null-terminated string.

## Members

### `bv_len`

Length, in bytes, of binary data.

### `bv_val`

Pointer to the binary data.

## Remarks

Use a **berval** structure for attributes that contain raw binary data, such as certificates, graphics, or sound files.

## See also

[Data Structures](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/data-structures)