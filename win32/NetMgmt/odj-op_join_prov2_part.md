# OP_JOINPROV2_PART structure

Contains additional information used for configuring a client joined to a domain.

## Members

### dwFlags

Must be set to either zero or one of the following values:

|Value|Meaning|
| --- | --- |
|OP_JP2_FLAG_PERSISTENTSITE (0x00000001)|The site specified in lpSiteName MUST be considered the permanent site for the client.|

### lpNetbiosName

Contains the Netbios name of the machine account in Unicode format.

### lpSiteName

Contains the name of the Active Directory site that the client should use.

### lpPrimaryDNSDomain

Contains the primary DNS domain name that the client should use.

### dwReserved

Reserved for future use and must be set to 0.

### lpReserved

Reserved for future use and must be set to NULL.

## See also

[**Offline Domain Join IDL Definitions**](https://learn.microsoft.com/windows/win32/netmgmt/odj-idl)