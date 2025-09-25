# IFaxSecurity::put_Descriptor

## Description

The **Descriptor** property represents the security descriptor for a [IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver) object.

This property is read/write.

## Parameters

## Remarks

The **IFaxSecurity::Descriptor** property represents the security descriptor, which contains the rights explicitly granted to a user by the fax administrator. The [IFaxSecurity::get_GrantedRights](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity-grantedrights-vb) property reflects the user rights that the fax server grants based on the descriptor. Specifically, if a user has the access right [farSUBMIT_HIGH](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum), the user can send high-priority, normal-priority and low-priority faxes. If a user has the access right [farSUBMIT_NORMAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum), the user can send normal-priority and low-priority faxes.

To read this property, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxSecurity.Descriptor](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity-descriptor)

[IFaxSecurity](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxsecurity)