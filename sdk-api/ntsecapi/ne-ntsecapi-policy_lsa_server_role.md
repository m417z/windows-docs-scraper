# POLICY_LSA_SERVER_ROLE enumeration

## Description

The **POLICY_LSA_SERVER_ROLE** enumeration type defines values that indicate the role of an LSA server. The
[LsaQueryInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaqueryinformationpolicy) and
[LsaSetInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasetinformationpolicy) functions use this enumeration type when their *InformationClass* parameters are set to **PolicyLsaServerRoleInformation**.

## Constants

### `PolicyServerRoleBackup:2`

Indicates a backup LSA server.

### `PolicyServerRolePrimary`

Indicates a primary LSA server, a workstation, or a standalone computer.

## See also

[LsaQueryInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaqueryinformationpolicy)

[LsaSetInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasetinformationpolicy)

[POLICY_LSA_SERVER_ROLE_INFO](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-policy_lsa_server_role_info)