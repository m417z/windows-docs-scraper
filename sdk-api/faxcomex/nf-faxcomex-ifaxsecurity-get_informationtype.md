# IFaxSecurity::get_InformationType

## Description

The **IFaxSecurity::InformationType** property represents the security information type.

This property is read/write.

## Parameters

## Remarks

The information type is a bitwise combination that indicates what security information will be retrieved from the server when requesting a security descriptor using the [IFaxSecurity::Descriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nf-faxcomex-ifaxsecurity-get_descriptor) property or when refreshing the [IFaxSecurity](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxsecurity) object using the [IFaxSecurity::Refresh](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity-refresh-vb) method. The information type also determines what information is sent to the fax server when you save changes to the **IFaxSecurity** object using the [IFaxSecurity::Save](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity-save-vb) method.

The bits are specified in the [SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) structure, defined in Winnt.h. Each item of security information is designated by a bit flag. The following values specify the bits applicable to the fax service.

| Value | Meaning |
| --- | --- |
| DACL_SECURITY_INFORMATION | Indicates that the discretionary access control list (ACL) of the object is being referenced. |
| GROUP_SECURITY_INFORMATION | Indicates that the primary group identifier of the object is being referenced. |
| OWNER_SECURITY_INFORMATION | Indicates that the owner identifier of the object is being referenced. |
| SACL_SECURITY_INFORMATION | Indicates that the system ACL of the object is being referenced. |

You should set the **IFaxSecurity::InformationType** property before you call the [IFaxSecurity::get_Descriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nf-faxcomex-ifaxsecurity-get_descriptor) method to ensure that you receive the information that you want and to ensure that you request only the information for which you have the appropriate access rights. Also, the **IFaxSecurity::InformationType** property will affect what information is sent to the fax server when you call the [IFaxSecurity::Save](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity-save-vb) method. If you do not set the **IFaxSecurity::InformationType** property, it defaults to the flags DACL_SECURITY_INFORMATION, GROUP_SECURITY_INFORMATION, and OWNER_SECURITY_INFORMATION.