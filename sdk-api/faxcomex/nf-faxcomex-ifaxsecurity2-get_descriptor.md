# IFaxSecurity2::get_Descriptor

## Description

Represents the security descriptor for a [IFaxServer2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver2) object.

This property is read/write.

## Parameters

## Remarks

The **IFaxSecurity2::Descriptor** property represents the security descriptor, which contains the rights explicitly granted to a user by the fax administrator. The [IFaxSecurity2::GrantedRights](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity2-grantedrights-vb) property reflects the user rights that the fax server grants based on the descriptor. Specifically, if a user has the access right [far2SUBMIT_HIGH](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum_2), the user can send high-priority, normal-priority and low-priority faxes. If a user has the access right [far2SUBMIT_NORMAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum_2), the user can send normal-priority and low-priority faxes.

To read and write this property, the user must have the [far2MANAGE_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum_2) access right. Users with the [far2QUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum_2) access right can read this property.

## See also

[FaxSecurity2.Descriptor](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity2-descriptor)

[IFaxSecurity2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxsecurity2)