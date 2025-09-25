# EAP_ERROR structure

## Description

The **EAP_ERROR** structure contains information about an error that occurred during an EAPHost operation.

## Members

### `dwWinError`

Error code from winerror.h.

### `type`

An [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that identifies the EAP method that raised the error.

### `dwReasonCode`

The reason code for the error.

### `rootCauseGuid`

A unique ID that identifies cause of error in EAPHost. An EAP method can define a new GUID and associate the GUID with a specific root cause.

| Value | Meaning |
| --- | --- |
| **GUID_EapHost_Default**<br><br>{0x00000000, 0x0000, 0x0000, 0, 0, 0, 0, 0, 0, 0, 0} | The default error cause. |
| **GUID_EapHost_Cause_MethodDLLNotFound**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 1}} | EAPHost cannot locate the DLL for the EAP method. |
| **GUID_EapHost_Cause_EapNegotiationFailed**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x1C}} | The authentication failed because Windows does not have the authentication method required for this network. |
| **GUID_EapHost_Cause_ThirdPartyMethod_Host_Reset**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 2, 0x12}} | The host of the third party method is not responding and was automatically restarted. |
| **GUID_EapHost_Cause_XmlMalformed**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x1D}} | The EAPHost configuration schema validation failed. |
| **GUID_EapHost_Cause_MethodDoesNotSupportOperation**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x1E}} | EAPHost returns this error when a configured EAP method does not support a requested operation (procedure call). |
| **GUID_EapHost_Cause_EapQecInaccessible**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 3, 0x12}} | EAPHost not able to communicate with EAP quarantine enforcement client (QEC) on a Network Access Protection (NAP) enabled client. This error may occur when the NAP service is not responding. |
| **GUID_EapHost_Cause_Generic_AuthFailure**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 1, 4}} | EAPHost returns this error on a generic, unspecified authentication failure. |
| **GUID_EapHost_Cause_IdentityUnknown**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 2, 4}} | EAPHost returns this error if the authenticator fails the authentication after the peer identity was submitted. |
| **GUID_EapHost_Cause_CertStoreInaccessible**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 4}} | Neither the authenticator or peer can access the certificate store. |
| **GUID_EapHost_Cause_User_CertExpired**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 9}} | EAPHost found an expired user certificate. |
| **GUID_EapHost_Cause_User_CertInvalid**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0xA}} | The user certificate being user for authentication does not have proper extended key usage (EKU) set. |
| **GUID_EapHost_Cause_User_CertNotFound**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0xB}} | EAPHost could not find a user certificate for authentication. |
| **GUID_EapHost_Cause_User_CertOtherError**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0xC}} | An unknown error occurred with the user certification being used for authentication. |
| **GUID_EapHost_Cause_User_CertRejected**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0xD}} | The authenticator rejected the user certification. |
| **GUID_EapHost_Cause_User_CertRevoked**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0xE}} | The user certificate being used for authentication has been revoked. |
| **GUID_EapHost_Cause_User_Account_OtherProblem**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 1, 0xE}} | An EAP failure was received after an identity exchange, indicating the likelihood of a problem with the authenticating user's account. |
| **GUID_EapHost_Cause_User_CredsRejected**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 2, 0xE}} | The authenticator rejected user credentials for authentication. |
| **GUID_EapHost_Cause_Server_CertExpired**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 5}} | EAPHost found an expired server certificate. |
| **GUID_EapHost_Cause_Server_CertInvalid**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 6}} | The server certificate being user for authentication does not have a proper extended key usage (EKU) set. |
| **GUID_EapHost_Cause_Server_CertNotFound**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 7}} | EAPHost could not find the server certificate for authentication. |
| **GUID_EapHost_Cause_Server_CertOtherError**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 1, 8}} | An unknown error occurred with the server certificate. |
| **GUID_EapHost_Cause_Server_CertRevoked**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 8}} | The server certificate being used for authentication has been revoked. |
| **GUID_EapHost_Cause_User_Root_CertExpired**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0xF}} | The trusted root certificate needed for user certificate validation has expired. |
| **GUID_EapHost_Cause_User_Root_CertInvalid**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x10}} | The authentication failed because the root certificate used for this network is invalid. |
| **GUID_EapHost_Cause_User_Root_CertNotFound**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x11}} | EAPHost could not find a certificate in a trusted root certificate store for user certification validation. |
| **GUID_EapHost_Cause_Server_Root_CertNotFound**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 1, 0x12}} | EAPHost could not find a root certificate in a trusted root certificate store for the server certification validation. |
| **GUID_EapHost_Cause_Server_Root_CertNameRequired**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x12}} | The authentication failed because the certificate on the server computer does not have a server name specified. |

### `repairGuid`

A unique ID that maps to a localizable string that identifies the repair action that can be taken to fix the reported error.

| Value | Meaning |
| --- | --- |
| **GUID_EapHost_Repair_ContactSysadmin**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 2}} | The user should contact the network administrator. |
| **GUID_EapHost_Repair_Retry_Authentication**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 1, 0x1B}} | The user should try to connect to the network again. |
| **GUID_EapHost_Repair_User_AuthFailure**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x19}} | The user should enter valid credentials for network authentication. |
| **GUID_EapHost_Repair_User_GetNewCert**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x1A}} | The user should obtain an updated certificate from the network administrator. |
| **GUID_EapHost_Repair_User_SelectValidCert**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x1B}} | The user should use a different and valid user certificate for authentication with the network. |
| **GUID_EapHost_Repair_Server_ClientSelectServerCert**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x19}} | The user should use a different and valid server certificate for authentication with the network. |

### `helpLinkGuid`

A unique ID that maps to a localizable string that specifies an URL for a page that contains additional information about an error or repair message. An EAP method can potentially define a new GUID and associate with one specific help link.

| Value | Meaning |
| --- | --- |
| **GUID_EapHost_Help_EapConfigureTypes** | The URL for the page with more information about configuring EAP types. |
| **GUID_EapHost_Help_FailedAuth** | The URL for the page with more information about authentication failures. |
| **GUID_EapHost_Help_ObtainingCerts**<br><br>{0xf535eea3, 0x1bdd, 0x46ca, {0xa2, 0xfc, 0xa6, 0x65, 0x59, 0x39, 0xb7, 0xe8}} | The URL for the page with more information about getting EAP certificates. |
| **GUID_EapHost_Help_SelectingCerts** | The URL for the page with more information about selecting the appropriate certificate to use for authentication. |
| **GUID_EapHost_Help_SetupEapServer** | The URL for the page with more information about setting up an EAP server. |
| **GUID_EapHost_Help_Troubleshooting**<br><br>{0x33307acf, 0x0698, 0x41ba, {0xb0, 0x14, 0xea, 0x0a, 0x2e, 0xb8, 0xd0, 0xa8}} | The URL for the page with more information about troubleshooting. |

### `pRootCauseString`

A localized and readable string that describes the root cause of the error.

### `pRepairString`

A localized and readable string that describes the possible repair action.

## See also

[Common EAPHost API Structures](https://learn.microsoft.com/windows/win32/eaphost/common-eap-host-api-structures)