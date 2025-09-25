# MF_ATTRIBUTES_MATCH_TYPE enumeration

## Description

Specifies how to compare the attributes on two objects.

## Constants

### `MF_ATTRIBUTES_MATCH_OUR_ITEMS:0`

Check whether all the attributes in *pThis* exist in *pTheirs* and have the same data, where *pThis* is the object whose [Compare](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-compare) method is being called and *pTheirs* is the object given in the *pTheirs* parameter.

### `MF_ATTRIBUTES_MATCH_THEIR_ITEMS:1`

Check whether all the attributes in *pTheirs* exist in *pThis* and have the same data, where *pThis* is the object whose [Compare](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-compare) method is being called and *pTheirs* is the object given in the *pTheirs* parameter.

### `MF_ATTRIBUTES_MATCH_ALL_ITEMS:2`

Check whether both objects have identical attributes with the same data.

### `MF_ATTRIBUTES_MATCH_INTERSECTION:3`

Check whether the attributes that exist in both objects have the same data.

### `MF_ATTRIBUTES_MATCH_SMALLER:4`

Find the object with the fewest number of attributes, and check if those attributes exist in the other object and have the same data.

## See also

[IMFAttributes::Compare](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfattributes-compare)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)