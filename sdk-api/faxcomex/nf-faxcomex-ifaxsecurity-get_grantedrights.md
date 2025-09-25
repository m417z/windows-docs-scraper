# IFaxSecurity::get_GrantedRights

## Description

The **IFaxSecurity::get_GrantedRights** property is a combination of the fax server access rights granted to the user referencing this property. For example, some users have permission to submit fax jobs with high priority while others have permission to submit jobs with normal or low priority only.

This property is read-only.

## Parameters

## Remarks

The **IFaxSecurity::get_GrantedRights** property reflects rights granted by the fax server, while the [IFaxSecurity::Descriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nf-faxcomex-ifaxsecurity-get_descriptor) property represents the security descriptor, which contains the rights explicitly granted to a user by the fax administrator.

To read this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxSecurity](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity)

[IFaxSecurity](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxsecurity)