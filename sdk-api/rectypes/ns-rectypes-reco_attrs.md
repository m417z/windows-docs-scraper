# RECO_ATTRS structure

## Description

Retrieves the attributes of a recognizer or specifies which attributes to use when you search for an installed recognizer.

## Members

### `dwRecoCapabilityFlags`

### `awcVendorName`

Vendor who wrote the recognizer.

### `awcFriendlyName`

A human-readable name for the recognizer.

Specify this name when you search for an installed recognizer.

### `awLanguageId`

List of language and sublanguage combinations that the recognizer supports. The list is **NULL** -terminated.

Specify language identifiers when you search for an installed recognizer if the *awcFriendlyName* member contains an empty string. Use the MAKELANGID macro to create the language identifiers. If the recognizer does not distinguish between writing styles corresponding to different sublanguages, specify SUBLANG_NEUTRAL for the sublanguage identifier.

## Remarks

The *awcFriendlyName* parameter may be empty (that is, having the first element set to the null character) when you use this structure as a return value from the [GetRecoAttributes Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-getrecoattributes). Because this is not an error, the return code for *awcFriendlyName* in **GetRecoAttributes Function** will be S_OK, and the other fields will contain data.

## See also

[GetRecoAttributes Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-getrecoattributes)