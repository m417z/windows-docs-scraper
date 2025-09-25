# DSPROPERTYPAGEINFO structure

## Description

The **DSPROPERTYPAGEINFO** structure is used by an Active Directory property sheet extension to obtain static registration data for the extension. This structure is supplied by the [CFSTR_DSPROPERTYPAGEINFO](https://learn.microsoft.com/windows/desktop/AD/cfstr-dspropertypageinfo) clipboard format.

## Members

### `offsetString`

Contains the offset, in bytes, from the start of the **DSPROPERTYPAGEINFO** structure to a NULL-terminated, Unicode string that contains the optional data stored for the extension.

## Remarks

The **DSPROPETYPAGEINFO** structure contains the optional string that the extension added to the **adminPropertySheet** and/or **shellPropertySheet** attributes when the extension was registered. For more information about how this string is set, see [Registering the Property Page COM Object in a Display Specifier](https://learn.microsoft.com/windows/desktop/AD/registering-the-property-page-com-object-in-a-display-specifier).

## See also

[CFSTR_DSPROPERTYPAGEINFO](https://learn.microsoft.com/windows/desktop/AD/cfstr-dspropertypageinfo)

[Display Structures in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/display-structures-in-active-directory-domain-services)

[Registering the Property Page COM Object in a Display Specifier](https://learn.microsoft.com/windows/desktop/AD/registering-the-property-page-com-object-in-a-display-specifier)