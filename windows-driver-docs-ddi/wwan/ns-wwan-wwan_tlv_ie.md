## Description

**WWAN_TLV_IE** is a variable-sized data structure for exchanging a wide range of information between a WWAN host and a device.

## Members

### `Type`

A two-octet IE type value identifying the information element that follows.

### `Reserved`

Unused and reserved byte. Must set to zero.

### `PaddingLength`

Length of the Padding field in octets. Must be 0, 1, 2, or 3.

### `DataLength`

The length of the *Data* field in octets.

## Remarks

The padding is to ensure that the entire size of the structure is a multiple of the size of a DWORD.

## See also