# USER_MODALS_INFO_2 structure

## Description

The
**USER_MODALS_INFO_2** structure contains the Security Account Manager (SAM) domain name and identifier.

## Members

### `usrmod2_domain_name`

Specifies the name of the Security Account Manager (SAM) domain. For a domain controller, this is the name of the domain that the controller is a member of. For workstations, this is the name of the computer.

### `usrmod2_domain_id`

Pointer to a
[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structure that contains the security identifier (SID) of the domain named by the **usrmod2_domain_name** member.

## See also

[NetUserModalsGet](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusermodalsget)

[NetUserModalsSet](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusermodalsset)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[User Modal Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-modal-functions)