# IX509AttributeClientId::InitializeEncode

## Description

The **InitializeEncode** method initializes the attribute from information about the user, client computer, and application that submitted the [certificate request](https://learn.microsoft.com/windows/win32/SecGloss/c-gly).

## Parameters

### `ClientId` [in]

A [RequestClientInfoClientId](https://learn.microsoft.com/windows/win32/api/certenroll/ne-certenroll-requestclientinfoclientid) enumeration value that identifies the type of application that created the request. Examples include auto-enrollment services, command-line request tools, and custom request applications.

### `strMachineDnsName` [in, optional]

A **BSTR** variable that contains the Domain Name System (DNS) name of the computer on which the request was created, for example `ComputerName.contoso.com`. If you do not supply a name, the method calls the [GetComputerNameEx](https://learn.microsoft.com/windows/win32/api/sysinfoapi/nf-sysinfoapi-getcomputernameexa) function. If a name cannot be found, the method fails.

### `strUserSamName` [in, optional]

A **BSTR** variable that contains the [Security Accounts Manager](https://learn.microsoft.com/windows/win32/SecGloss/s-gly) (SAM) name for the user in the form *DomainName\UserName*. If you do not supply a name, the method calls the [GetUserNameEx](https://learn.microsoft.com/windows/win32/api/secext/nf-secext-getusernameexa) function. If a name cannot be found, the method fails.

### `strProcessName` [in, optional]

A **BSTR** variable that contains the name of the application that created the certificate request. If you do not supply a name, the method calls the [GetCommandLine](https://learn.microsoft.com/windows/desktop/api/processenv/nf-processenv-getcommandlinea) function and parses the command line. If a name cannot be found, the method fails.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/win32/SecCrypto/common-hresult-values).

## Remarks

The [object identifier](https://learn.microsoft.com/windows/win32/SecGloss/o-gly) (OID) for this attribute is **XCN_OID_REQUEST_CLIENT_INFO** (1.3.6.1.4.1.311.21.20). For more information, see [CERTENROLL_OBJECTID](https://learn.microsoft.com/windows/win32/api/certenroll/ne-certenroll-certenroll_objectid). The attribute is created as an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/win32/SecGloss/a-gly) (ASN.1) structure that is encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/win32/SecGloss/d-gly) (DER).

You must call either **InitializeEncode** or [InitializeDecode](https://learn.microsoft.com/windows/win32/api/certenroll/nf-certenroll-ix509attributeclientid-initializedecode) before you can use an [IX509AttributeClientId](https://learn.microsoft.com/windows/win32/api/certenroll/nn-certenroll-ix509attributeclientid) object. The two methods complement each other. The **InitializeEncode** method enables you to construct an encoded ASN.1 structure from raw data, and the **InitializeDecode** method enables you to initialize raw data from an encoded ASN.1 structure. You can call the following properties to retrieve the raw data:

- [ClientId](https://learn.microsoft.com/windows/win32/api/certenroll/nf-certenroll-ix509attributeclientid-get_clientid)
- [MachineDnsName](https://learn.microsoft.com/windows/win32/api/certenroll/nf-certenroll-ix509attributeclientid-get_machinednsname)
- [ProcessName](https://learn.microsoft.com/windows/win32/api/certenroll/nf-certenroll-ix509attributeclientid-get_processname)
- [UserSamName](https://learn.microsoft.com/windows/win32/api/certenroll/nf-certenroll-ix509attributeclientid-get_usersamname)

## See also

[IX509AttributeClientId](https://learn.microsoft.com/windows/win32/api/certenroll/nn-certenroll-ix509attributeclientid)

[InitializeDecode](https://learn.microsoft.com/windows/win32/api/certenroll/nf-certenroll-ix509attributeclientid-initializedecode)