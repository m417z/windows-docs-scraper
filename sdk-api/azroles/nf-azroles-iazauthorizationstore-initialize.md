# IAzAuthorizationStore::Initialize

## Description

The **Initialize** method initializes the authorization manager.

## Parameters

### `lFlags` [in]

Flags that control the behavior of the initialization. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 (0x0) | The authorization store is opened for use by the **Update** method and the [AccessCheck](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazclientcontext-accesscheck) method. |
| **AZ_AZSTORE_FLAG_AUDIT_IS_CRITICAL**<br><br>8 (0x8) | The calling application is required to have SE_AUDIT_PRIVILEGE; if the application does not have the audit privilege, the **Initialize** method fails. |
| **AZ_AZSTORE_FLAG_BATCH_UPDATE**<br><br>4 (0x4) | The provider is notified that many objects will be modified or created. The provider then optimizes submission of the changes for better performance. Use this flag only when multiple child objects of an [AzAuthorizationStore](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazauthorizationstore) object are updated simultaneously, such as during an install or a controlled batch update. |
| **AZ_AZSTORE_FLAG_CREATE**<br><br>1 (0x1) | The system attempts to create the policy store specified by the *bstrPolicyURL* parameter. |
| **AZ_AZSTORE_FLAG_MANAGE_STORE_ONLY**<br><br>2 (0x2) | An existing store is opened for management purposes. Run-time routines cannot be performed. |

If the AZ_AZSTORE_FLAG_CREATE flag is specified:

* The system will attempt to create the underlying policy store specified by the *bstrPolicyURL* parameter.
* If the specified policy store exists, the **Initialize** method will fail with ERROR_ALREADY_EXISTS.
* You must call the [Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-submit) method to persist any changes made by this method.
* The [UpdateCache](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-updatecache) method will fail until the [Submit](https://learn.microsoft.com/windows/desktop/api/azroles/nf-azroles-iazauthorizationstore-submit) method is called. The underlying policy store is actually created when **Submit** is called.

If the AZ_AZSTORE_FLAG_CREATE flag is not specified, the system expects the underlying policy store to exist. If the store does not exist, the **Initialize** method will fail with ERROR_FILE_NOT_FOUND.

### `bstrPolicyURL` [in]

Location of the persistent copy of the authorization policy database.

This string must contain both the policy URL prefix and the provider-specific policy location. Authorization Manager uses the provider prefix to load the appropriate provider. The store is loaded from the provider-specific policy location. No spaces are allowed in the policy URL prefix.

The policy URL prefix for an Active Directory store is **msldap:**. The general format for the URL is as follows:

**msldap://***ServerName***:***Port***//***DistinguishedNameForTheStore*

The server name and the port are optional. If a server name is not provided, the default domain controller is used. If a port is not specified, the default LDAP port (LDAP_PORT, 389) is used. The distinguished name (DN) for the store begins with the relative distinguished name (RDN) of the [AzAuthorizationStore](https://learn.microsoft.com/windows/desktop/api/azroles/nn-azroles-iazauthorizationstore) object. For example, if the RDN of the **AzAuthorizationStore** object is MyStore and MyStore is in an organizational unit (OU) named AzMan, a possible URL for the Active Directory store is as follows:

msldap://*MyServer*/CN=MyStore,OU=AzMan,DC=*MyDomain*,DC=Fabrikam,DC=Com

The policy URL prefix for an XML store is **msxml:**. The general format for an XML store URL is the same as for a file URL, as shown in the following examples:

* msxml://c:/abc/test.xml
* msxml://\\server\share\abc.xml
* msxml://d|/dir1/dir2/abc.xml
* msxml://c:/Documents%20and%20Settings/test%2exml

Note that in the fourth example, the URL uses encoding for the space (%20) and the period (%2e) characters. Also, the traditional relative path notation is not supported in URLs. If you specify msxml://abc.xml, the URL points to the file at the root of your drive.

**Note** If an XML or SQL store is used over a network, the traffic is not automatically encrypted. IPsec can be used to encrypt the authorization information in transit. For an SQL store, it is also possible to set up the open database connectivity (ODBC) connection to use encryption. For information about how to set up the ODBC connection, see [How to enable encryption after SQL Server has been installed (Network Utility)](https://msdn.microsoft.com/library/aa198230.aspx).

### `varReserved` [in, optional]

Reserved for future use. This parameter can be one of the following values:

* varReserved.vt == VT_ERROR and varReserved.scode == DISP_E_PARAMNOTFOUND
* varReserved.vt == VT_EMPTY
* varReserved.vt == VT_NULL
* varReserved.vt == VT_I4 and varReserved.lVal == 0
* varReserved.vt == VT_I2 and varReserved.iVal == 0

## Return value

 If the method succeeds, the method returns S_OK.

If the *bstrPolicyURL* parameter is not valid, the method returns HRESULT_FROM_WIN32(ERROR_INVALID_NAME).

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Active Directory supports Application Partitions, which are also known as Non-Domain Naming Contexts. These partitions are used as a location for programs to store application data. An Authorization Manager policy store cannot be created or kept in the Application Partition; instead, use the Program Data container as the container for Active Directory Authorization Manager policy stores.