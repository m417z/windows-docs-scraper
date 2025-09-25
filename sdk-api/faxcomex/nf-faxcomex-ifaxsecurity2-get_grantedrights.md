# IFaxSecurity2::get_GrantedRights

## Description

Retrieves a combination of the fax server access rights granted to the user referencing this property. For example, some users have permission to submit fax jobs with high priority while others have permission to submit jobs with normal or low priority only.

This property is read-only.

## Parameters

## Remarks

The **IFaxSecurity2::GrantedRights** property reflects rights granted by the fax server, while the [Descriptor](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity2-descriptor) property represents the security descriptor, which contains the rights explicitly granted to a user by the fax administrator.

To read this property, a user must have the [far2QUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum_2) access right.

## See also

[FaxSecurity2](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity2)

[IFaxSecurity2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxsecurity2)