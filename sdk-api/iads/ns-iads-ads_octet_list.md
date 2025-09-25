# ADS_OCTET_LIST structure

## Description

The **ADS_OCTET_LIST** structure is an ADSI representation of an ordered sequence of single-byte strings.

## Members

### `Next`

Pointer to the next **ADS_OCTET_LIST** entry in the list.

### `Length`

Contains the length, in bytes, of the list.

### `Data`

Pointer to an array of BYTEs that contains the list. The **Length** member of this structure contains the number of BYTEs in this array.

## Remarks

For more information, see Novell NetWare Directory Services Schema Specification, version 1.1.

## See also

[ADSI Structures](https://learn.microsoft.com/windows/desktop/ADSI/adsi-structures)