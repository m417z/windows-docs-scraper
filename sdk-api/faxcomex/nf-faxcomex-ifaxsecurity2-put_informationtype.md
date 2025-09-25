# IFaxSecurity2::put_InformationType

## Description

Retrieves the security information type.

This property is read/write.

## Parameters

## Remarks

The information type is a bitwise combination that indicates what security information will be retrieved from the server when requesting a security descriptor using the [Descriptor](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity2-descriptor) property, or when refreshing the [FaxSecurity2](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity2) object using the [IFaxSecurity2::Refresh](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity2-refresh-vb) method. The information type property also determines what information is sent to the fax server when you save changes to the **FaxSecurity2** object using the [IFaxSecurity2::Save](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity2-save-vb) method.

The bits are specified in the [SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) structure, defined in Winnt.h. Each item of security information is designated by a bit flag. The following values specify the bits applicable to the fax service:

| Value | Meaning |
| --- | --- |
| DACL_SECURITY_INFORMATION | Indicates that the discretionary access control list (ACL) of the object is being referenced. |
| GROUP_SECURITY_INFORMATION | Indicates that the primary group identifier of the object is being referenced. |
| OWNER_SECURITY_INFORMATION | Indicates that the owner identifier of the object is being referenced. |
| SACL_SECURITY_INFORMATION | Indicates that the system ACL of the object is being referenced. |

Set the **IFaxSecurity2::InformationType** property before you get the [Descriptor](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity2-descriptor) property, to ensure that you receive the desired information, and that you request only the information for which you have the appropriate access rights. Also, the **IFaxSecurity2::InformationType** property will affect what information is sent to the fax server when you call the [IFaxSecurity2::Save](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity2-save-vb) method. If you do not set the **IFaxSecurity2::InformationType** property, it defaults to the flags DACL_SECURITY_INFORMATION, GROUP_SECURITY_INFORMATION, and OWNER_SECURITY_INFORMATION.

## See also

[FaxSecurity2](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsecurity2)

[IFaxSecurity2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxsecurity2)