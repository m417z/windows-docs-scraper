# RSOP_TARGET structure

## Description

The
**RSOP_TARGET** structure contains computer and user information required by the
[GenerateGroupPolicy](https://learn.microsoft.com/windows/desktop/api/userenv/nc-userenv-pfngenerategrouppolicy) function.

## Members

### `pwszAccountName`

Pointer to the account name of the computer or the user.

### `pwszNewSOM`

Pointer to the new domain or organizational unit that is the location for the account identified by the **pwszAccountName** member. This member can be **NULL**.

### `psaSecurityGroups`

Pointer to a **SAFEARRAY** that contains a proposed list of new security groups. This member can be **NULL**. For more information about security groups, see
[Filtering the Scope of a GPO](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/filtering-the-scope-of-a-gpo) and
[How Security Groups are Used in Access Control](https://learn.microsoft.com/windows/desktop/AD/how-security-groups-are-used-in-access-control).

### `pRsopToken`

Pointer to an **RSOPTOKEN** to use with the
[RSoPAccessCheckByType](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-rsopaccesscheckbytype) and the
[RSoPFileAccessCheck](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-rsopfileaccesscheck) functions.

### `pGPOList`

Pointer to a
[GROUP_POLICY_OBJECT](https://learn.microsoft.com/windows/desktop/api/userenv/ns-userenv-group_policy_objecta) structure containing a linked list of GPOs.

### `pWbemServices`

Specifies the WMI services pointer to the namespace to which the planning mode policy data should be written.

## See also

[GROUP_POLICY_OBJECT](https://learn.microsoft.com/windows/desktop/api/userenv/ns-userenv-group_policy_objecta)

[GenerateGroupPolicy](https://learn.microsoft.com/windows/desktop/api/userenv/nc-userenv-pfngenerategrouppolicy)

[Group Policy Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[Group Policy Structures](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-structures)

[RSoPAccessCheckByType](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-rsopaccesscheckbytype)

[RSoPFileAccessCheck](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-rsopfileaccesscheck)