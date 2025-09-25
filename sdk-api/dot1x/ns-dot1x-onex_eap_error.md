# ONEX_EAP_ERROR structure

## Description

The **ONEX_EAP_ERROR** structure contains 802.1X EAP error when an error occurs with 802.1X authentication.

## Members

### `dwWinError`

The error value defined in the *Winerror.h* header file. This member also sometimes contains the reason the EAP method failed. The existing values for this member for the reason the EAP method failed are defined in the *Eaphosterror.h* header file.

Some possible values are listed below.

| Value | Meaning |
| --- | --- |
| **ERROR_PATH_NOT_FOUND**<br><br>3L | The system cannot find the path specified. |
| **ERROR_INVALID_DATA**<br><br>13L | The data is not valid. |
| **ERROR_INVALID_PARAMETER**<br><br>87L | A parameter is incorrect. |
| **ERROR_BAD_ARGUMENTS**<br><br>160L | One or more arguments are not correct. |
| **ERROR_CANTOPEN**<br><br>1011L | The configuration registry key could not be opened. |
| **ERROR_DATATYPE_MISMATCH**<br><br>1629L | The data supplied is of the wrong type. |
| **EAP_I_USER_ACCOUNT_OTHER_ERROR**<br><br>0x40420110 | The EAPHost received EAP failure after the identity exchange. There is likely a problem with the authenticating user's account. |
| **E_UNEXPECTED**<br><br>0x8000FFFFL | A catastrophic failure occurred. |
| **EAP_E_CERT_STORE_INACCESSIBLE**<br><br>0x80420010 | The certificate store can't be accessed on either the authenticator or the peer. |
| **EAP_E_EAPHOST_METHOD_NOT_INSTALLED**<br><br>0x80420011 | The requested EAP method is not installed. |
| **EAP_E_EAPHOST_EAPQEC_INACCESSIBLE**<br><br>0x80420013 | The EAPHost is not able to communicate with the EAP quarantine enforcement client (QEC) on a client with Network Access Protection (NAP) enabled. |
| **EAP_E_EAPHOST_IDENTITY_UNKNOWN**<br><br>0x80420014 | The EAPHost returns this error if the authenticator fails the authentication after the peer sent its identity. |
| **EAP_E_AUTHENTICATION_FAILED**<br><br>0x80420015 | The EAPHost returns this error on authentication failure. |
| **EAP_I_EAPHOST_EAP_NEGOTIATION_FAILED**<br><br>0x80420016 | The EAPHost returns this error when the client and the server aren't configured with compatible EAP types. |
| **EAP_E_EAPHOST_METHOD_INVALID_PACKET**<br><br>0x80420017 | The EAPMethod received an EAP packet that cannot be processed. |
| **EAP_E_EAPHOST_REMOTE_INVALID_PACKET**<br><br>0x80420018 | The EAPHost received a packet that cannot be processed. |
| **EAP_E_EAPHOST_XML_MALFORMED**<br><br>0x80420019 | The EAPHost configuration schema validation failed. |
| **EAP_E_METHOD_CONFIG_DOES_NOT_SUPPORT_SSO**<br><br>0x8042001A | The EAP method does not support single signon for the provided configuration. |
| **EAP_E_EAPHOST_METHOD_OPERATION_NOT_SUPPORTED**<br><br>0x80420020 | The EAPHost returns this error when a configured EAP method does not support a requested operation (procedure call). |
| **EAP_E_USER_CERT_NOT_FOUND**<br><br>0x80420100 | The EAPHost could not find the user certificate for authentication. |
| **EAP_E_USER_CERT_INVALID**<br><br>0x80420101 | The user certificate being used for authentication does not have a proper extended key usage (EKU) set. |
| **EAP_E_USER_CERT_EXPIRED**<br><br>0x80420102 | The EAPhost found a user certificate which has expired. |
| **EAP_E_USER_CERT_REVOKED**<br><br>0x80420103 | The user certificate being used for authentication has been revoked. |
| **EAP_E_USER_CERT_OTHER_ERROR**<br><br>0x80420104 | An unknown error occurred with the user certificate being used for authentication. |
| **EAP_E_USER_CERT_REJECTED**<br><br>0x80420105 | The authenticator rejected the user certificate being used for authentication. |
| **EAP_E_USER_CREDENTIALS_REJECTED**<br><br>0x80420111 | The authenticator rejected the user credentials for authentication. |
| **EAP_E_USER_NAME_PASSWORD_REJECTED**<br><br>0x80420112 | The authenticator rejected the user credentials for authentication. |
| **EAP_E_NO_SMART_CARD_READER**<br><br>0x80420113 | No smart card reader was present. |
| **EAP_E_SERVER_CERT_INVALID**<br><br>0x80420201 | The server certificate being user for authentication does not have a proper EKU set . |
| **EAP_E_SERVER_CERT_EXPIRED**<br><br>0x80420202 | The EAPhost found a server certificate which has expired. |
| **EAP_E_SERVER_CERT_REVOKED**<br><br>0x80420203 | The server certificate being used for authentication has been revoked. |
| **EAP_E_SERVER_CERT_OTHER_ERROR**<br><br>0x80420204 | An unknown error occurred with the server certificate being used for authentication. |
| **EAP_E_USER_ROOT_CERT_NOT_FOUND**<br><br>0x80420300 | The EAPHost could not find a certificate in trusted root certificate store for user certificate validation. |
| **EAP_E_USER_ROOT_CERT_INVALID**<br><br>0x80420301 | The authentication failed because the root certificate used for this network is not valid. |
| **EAP_E_USER_ROOT_CERT_EXPIRED**<br><br>0x80420302 | The trusted root certificate needed for user certificate validation has expired. |
| **EAP_E_SERVER_ROOT_CERT_NOT_FOUND**<br><br>0x80420400 | The EAPHost could not find a root certificate in the trusted root certificate store for server certificate validation. |

### `type`

The EAP method type that raised the error during 802.1X authentication. The [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure is defined in the *Eaptypes.h* header file.

### `dwReasonCode`

The reason the EAP method failed. Some of the values for this member are defined in the *Eaphosterror.h* header file and some are defined in the *Winerror.h* header file, although other values are possible.

Possible values are listed below.

| Value | Meaning |
| --- | --- |
| **ERROR_BAD_ARGUMENTS** | One or more arguments are not correct. |
| **ERROR_INVALID_DATA** | The data is not valid. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. |
| **EAP_I_USER_ACCOUNT_OTHER_ERROR** | The EAPHost received EAP failure after the identity exchange. There is likely a problem with the authenticating user's account. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

### `rootCauseGuid`

A unique ID that identifies cause of error in EAPHost. An EAP method can define a new GUID and associate the GUID with a specific root cause. The existing values for this member are defined in the *Eaphosterror.h* header file.

| Value | Meaning |
| --- | --- |
| **GUID_EapHost_Default**<br><br>{0x00000000, 0x0000, 0x0000, 0, 0, 0, 0, 0, 0, 0, 0} | The default error cause.<br><br>This is not a fixed GUID when it reaches supplicant, but the first portion will be filled by a generic Win32/RAS error. This helps create a unique GUID for every unique error. |
| **GUID_EapHost_Cause_MethodDLLNotFound**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 1}} | EAPHost cannot locate the DLL for the EAP method. |
| **GUID_EapHost_Cause_CertStoreInaccessible**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 4}} | Both the authenticator and the peer are unable to access the certificate store. |
| **GUID_EapHost_Cause_Server_CertExpired**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 5}} | EAPHost found an expired server certificate. |
| **GUID_EapHost_Cause_Server_CertInvalid**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 6}} | The server certificate being user for authentication does not have a proper extended key usage (EKU) set. |
| **GUID_EapHost_Cause_Server_CertNotFound**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 7}} | EAPHost could not find the server certificate for authentication. |
| **GUID_EapHost_Cause_Server_CertRevoked**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 8}} | The server certificate being used for authentication has been revoked. |
| **GUID_EapHost_Cause_User_CertExpired**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 9}} | EAPHost found an expired user certificate. |
| **GUID_EapHost_Cause_User_CertInvalid**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0xA}} | The user certificate being user for authentication does not have proper extended key usage (EKU) set. |
| **GUID_EapHost_Cause_User_CertNotFound**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0xB}} | EAPHost could not find a user certificate for authentication. |
| **GUID_EapHost_Cause_User_CertOtherError**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0xC}} | An unknown error occurred with the user certification being used for authentication. |
| **GUID_EapHost_Cause_User_CertRejected**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0xD}} | The authenticator rejected the user certification. |
| **GUID_EapHost_Cause_User_CertRevoked**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0xE}} | The user certificate being used for authentication has been revoked. |
| **GUID_EapHost_Cause_User_Root_CertExpired**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0xF}} | The trusted root certificate needed for user certificate validation has expired. |
| **GUID_EapHost_Cause_User_Root_CertInvalid**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x10}} | The authentication failed because the root certificate used for this network is not valid. |
| **GUID_EapHost_Cause_User_Root_CertNotFound**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x11}} | EAPHost could not find a certificate in a trusted root certificate store for user certification validation. |
| **GUID_EapHost_Cause_Server_Root_CertNameRequired**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x12}} | The authentication failed because the certificate on the server computer does not have a server name specified. |
| **GUID_EapHost_Cause_EapNegotiationFailed**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x1C}} | The authentication failed because Windows does not have the authentication method required for this network. |
| **GUID_EapHost_Cause_XmlMalformed**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x1D}} | The EAPHost configuration schema validation failed. |
| **GUID_EapHost_Cause_MethodDoesNotSupportOperation**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x1E}} | EAPHost returns this error when a configured EAP method does not support a requested operation (procedure call). |
| **GUID_EapHost_Cause_No_SmartCardReader_Found**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x2B}} | A valid smart card needs to be present for authentication to be proceed.<br><br>This GUID is supported on Windows Server 2008 R2 with the Wireless LAN Service installed and on Windows 7 . |
| **GUID_EapHost_Cause_Generic_AuthFailure**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 1, 4}} | EAPHost returns this error on a generic, unspecified authentication failure. |
| **GUID_EapHost_Cause_Server_CertOtherError**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 1, 8}} | An unknown error occurred with the server certificate. |
| **GUID_EapHost_Cause_User_Account_OtherProblem**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 1, 0xE}} | An EAP failure was received after an identity exchange, indicating the likelihood of a problem with the authenticating user's account. |
| **GUID_EapHost_Cause_Server_Root_CertNotFound**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 1, 0x12}} | EAPHost could not find a root certificate in a trusted root certificate store for the server certification validation. |
| **GUID_EapHost_Cause_IdentityUnknown**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 2, 4}} | EAPHost returns this error if the authenticator fails the authentication after the peer identity was submitted. |
| **GUID_EapHost_Cause_User_CredsRejected**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 2, 0xE}} | The authenticator rejected user credentials for authentication. |
| **GUID_EapHost_Cause_ThirdPartyMethod_Host_Reset**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 2, 0x12}} | The host of the third party method is not responding and was automatically restarted. |
| **GUID_EapHost_Cause_EapQecInaccessible**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 3, 0x12}} | EAPHost was not able to communicate with the EAP quarantine enforcement client (QEC) on a client with Network Access Protection (NAP) enabled. This error may occur when the NAP service is not responding. |
| **GUID_EapHost_Cause_Method_Config_Does_Not_Support_Sso**<br><br>{0xda18bd32, 0x004f, 0x41fa, {0xae, 0x08, 0x0b, 0xc8, 0x5e, 0x58, 0x45, 0xac}} | The EAP method does not support single signon for the provided configuration data.<br><br>This GUID is supported on Windows Server 2008 R2 with the Wireless LAN Service installed and on Windows 7. |

### `repairGuid`

A unique ID that maps to a localizable string that identifies the repair action that can be taken to fix the reported error. The existing values for this member are defined in the *Eaphosterror.h* header file.

| Value | Meaning |
| --- | --- |
| **GUID_EapHost_Repair_ContactSysadmin**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 2}} | The user should contact the network administrator. |
| **GUID_EapHost_Repair_Server_ClientSelectServerCert**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x18}} | The user should choose a different and valid certificate for authentication with this network. |
| **GUID_EapHost_Repair_User_AuthFailure**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x19}} | The user should contact your network administrator. Your administrator can verify your user name and password for network authentication. |
| **GUID_EapHost_Repair_User_GetNewCert**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x1A}} | The user should obtain an updated certificate from the network administrator. The certificate required to connect to this network can't be found on your computer. |
| **GUID_EapHost_Repair_User_SelectValidCert**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x1B}} | The user should use a different and valid user certificate for authentication with the network. |
| **GUID_EapHost_Repair_ContactAdmin_AuthFailure**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x1F}} | The user should contact your network administrator. Windows can't verify your identity for connection to this network.<br><br>This GUID is supported on Windows Server 2008 R2 with the Wireless LAN Service installed and on Windows 7. |
| **GUID_EapHost_Repair_ContactAdmin_IdentityUnknown**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x20}} | The user should contact your network administrator. Windows can't verify your identity for connection to this network.<br><br>This GUID is supported on Windows Windows Server 2008 R2 with the Wireless LAN Service installed and on Windows 7. |
| **GUID_EapHost_Repair_ContactAdmin_NegotiationFailed**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x21}} | The user should contact your network administrator. Windows needs to be configured to use the authentication method required for this network.<br><br>This GUID is supported on Windows Server 2008 R2 with the Wireless LAN Service installed and on Windows 7. |
| **GUID_EapHost_Repair_ContactAdmin_MethodNotFound**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x22}} | The user should contact your network administrator. Windows needs to be configured to use the authentication method required for this network.<br><br>This GUID is supported on Windows Windows Server 2008 R2 with the Wireless LAN Service installed and on Windows 7. |
| **GUID_EapHost_Repair_RestartNap**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x23}} | The user should start the Network Access Protection service. The Network Access Protection service is not responding. Start or restart the Network Access Protection service, and then try connecting again.<br><br>This GUID is supported on Windows Server 2008 R2 with the Wireless LAN Service installed and on Windows 7 . |
| **GUID_EapHost_Repair_ContactAdmin_CertStoreInaccessible**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x24}} | The user should contact your network administrator. The certificate store on this computer needs to be repaired.<br><br>This GUID is supported on Windows Windows Server 2008 R2 with the Wireless LAN Service installed and on Windows 7. |
| **GUID_EapHost_Repair_ContactAdmin_InvalidUserAccount**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x25}} | The user should contact your network administrator. A problem with your user account needs to be resolved.<br><br>This GUID is supported on Windows Server 2008 R2 with the Wireless LAN Service installed and on Windows 7. |
| **GUID_EapHost_Repair_ContactAdmin_RootCertInvalid**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x26}} | The user should contact your network administrator. The root certificate used for this network needs to be repaired.<br><br>This GUID is supported on Windows Server 2008 R2 with the Wireless LAN Service installed and on Windows 7. |
| **GUID_EapHost_Repair_ContactAdmin_RootCertNotFound**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x27}} | The user should contact your network administrator. The certificate used by the server for this network needs to be properly installed on your computer.<br><br>This GUID is supported on Windows Server 2008 R2 with the Wireless LAN Service installed and on Windows 7. |
| **GUID_EapHost_Repair_ContactAdmin_RootExpired**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x28}} | The user should contact your network administrator. The root certificate used for this network needs to be renewed.<br><br>This GUID is supported on Windows Server 2008 R2 with the Wireless LAN Service installed and on Windows 7. |
| **GUID_EapHost_Repair_ContactAdmin_CertNameAbsent**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x29}} | The user should contact your network administrator. A problem with the server certificate used for this network needs to be resolved.<br><br>This GUID is supported on Windows Server 2008 R2 with the Wireless LAN Service installed and on Windows 7. |
| **GUID_EapHost_Repair_ContactAdmin_NoSmartCardReader**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x2A}} | The user should connect a smart card reader to your computer, insert a smart card, and attempt to connect again.<br><br>This GUID is supported on Windows Server 2008 R2 with the Wireless LAN Service installed and on Windows 7. |
| **GUID_EapHost_Repair_ContactAdmin_InvalidUserCert**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x2C}} | The user should contact your network administrator. The user certificate on this computer needs to be repaired.<br><br>This GUID is supported on Windows Server 2008 R2 with the Wireless LAN Service installed and on Windows 7. |
| **GUID_EapHost_Repair_Method_Not_Support_Sso**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x2D}} | The user should contact your network administrator. Windows needs to be configured to use the authentication method required for this network.<br><br>This GUID is supported on Windows Server 2008 R2 with the Wireless LAN Service installed and on Windows 7. |
| **GUID_EapHost_Repair_Retry_Authentication**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 1, 0x1B}} | The user should try to connect to the network again. |

### `helpLinkGuid`

A unique ID that maps to a localizable string that specifies an URL for a page that contains additional information about an error or repair message. An EAP method can potentially define a new GUID and associate with one specific help link. Some of the existing values for this member are defined in the *Eaphosterror.h* header file.

| Value | Meaning |
| --- | --- |
| **GUID_EapHost_Help_Troubleshooting**<br><br>{0x33307acf, 0x0698, 0x41ba, {0xb0, 0x14, 0xea, 0x0a, 0x2e, 0xb8, 0xd0, 0xa8}} | The URL for the page with more information about troubleshooting. This currently is a generic networking troubleshooting help page, not EAP specific. |
| **GUID_EapHost_Help_EapConfigureTypes**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x03}} | The URL for the page with more information about configuring EAP types. |
| **GUID_EapHost_Help_FailedAuth**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x13}} | The URL for the page with more information about authentication failures.<br><br>This GUID is supported on Windows Vista |
| **GUID_EapHost_Help_SelectingCerts**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x15}} | The URL for the page with more information about selecting the appropriate certificate to use for authentication. |
| **GUID_EapHost_Help_SetupEapServer**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x16}} | The URL for the page with more information about setting up an EAP server.<br><br>This GUID is supported on Windows Vista |
| **GUID_EapHost_Help_Troubleshooting**<br><br>{0x9612fc67, 0x6150, 0x4209, {0xa8, 0x5e, 0xa8, 0xd8, 0, 0, 0, 0x17}} | The URL for the page with more information about troubleshooting.<br><br>This GUID is supported on Windows Vista |
| **GUID_EapHost_Help_ObtainingCerts**<br><br>{0xf535eea3, 0x1bdd, 0x46ca, {0xa2, 0xfc, 0xa6, 0x65, 0x59, 0x39, 0xb7, 0xe8}} | The URL for the page with more information about getting EAP certificates. |

### `fRootCauseString`

Indicates if the **ONEX_EAP_ERROR** structure contains a root cause string in the **RootCauseString** member.

### `fRepairString`

Indicates if the **ONEX_EAP_ERROR** structure contains a repair string in the **RepairString** member.

### `RootCauseString`

A localized and readable string that describes the root cause of the error. This member contains a NULL-terminated Unicode string starting at the **dwOffset** member of the [ONEX_VARIABLE_BLOB](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_variable_blob) if the **fRootCauseString** bitfield member is set.

### `RepairString`

A localized and readable string that describes the possible repair action.
This member contains a NULL-terminated Unicode string starting at the **dwOffset** member of the [ONEX_VARIABLE_BLOB](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_variable_blob) if the **fRepairString** bitfield member is set.

## Remarks

The **ONEX_EAP_ERROR** structure is used by the 802.1X module, a new wireless configuration component supported on Windows Vista and later.

Many members of the **ONEX_EAP_ERROR** structure correspond with similar members in the [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure

The [ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) contains information on a status change to 802.1X authentication. The **ONEX_RESULT_UPDATE_DATA** structure is returned when the **NotificationSource** member of the [WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85)) structure is **WLAN_NOTIFICATION_SOURCE_ONEX** and the **NotificationCode** member of the **WLAN_NOTIFICATION_DATA** structure for received notification is **OneXNotificationTypeResultUpdate**. For this notification, the **pData** member of the **WLAN_NOTIFICATION_DATA** structure points to an **ONEX_RESULT_UPDATE_DATA** structure that contains information on the 802.1X authentication status change.

If the **fEapError** member in the [ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data) structure is set, then the **eapError** member of the **ONEX_RESULT_UPDATE_DATA** structure contains an [ONEX_VARIABLE_BLOB](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_variable_blob) structure with an **ONEX_EAP_ERROR** structure embedded starting at the **dwOffset** member of the **ONEX_VARIABLE_BLOB**.

## See also

[About the ACM Architecture](https://learn.microsoft.com/windows/desktop/NativeWiFi/about-the-acm-architecture)

[Common EAPHost API Structures](https://learn.microsoft.com/windows/win32/eaphost/common-eap-host-api-structures)

[EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error)

[EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type)

[ONEX_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/desktop/api/dot1x/ne-dot1x-onex_notification_type)

[ONEX_RESULT_UPDATE_DATA](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_result_update_data)

[ONEX_VARIABLE_BLOB](https://learn.microsoft.com/windows/desktop/api/dot1x/ns-dot1x-onex_variable_blob)

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification)