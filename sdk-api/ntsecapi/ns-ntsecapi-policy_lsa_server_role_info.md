# POLICY_LSA_SERVER_ROLE_INFO structure

## Description

The **POLICY_LSA_SERVER_ROLE_INFO** structure is used to set and query the role of an LSA server. The [LsaQueryInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaqueryinformationpolicy) and [LsaSetInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasetinformationpolicy) functions use this structure when their *InformationClass* parameters are set to **PolicyLsaServerRoleInformation**.

## Members

### `LsaServerRole`

Specifies one of the values from the
[POLICY_LSA_SERVER_ROLE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-policy_lsa_server_role) enumeration type to indicate a primary or backup LSA server.

## See also

[LsaQueryInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaqueryinformationpolicy)

[LsaSetInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasetinformationpolicy)

[POLICY_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-policy_information_class)

[POLICY_LSA_SERVER_ROLE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-policy_lsa_server_role)