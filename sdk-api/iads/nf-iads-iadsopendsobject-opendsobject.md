# IADsOpenDSObject::OpenDSObject

## Description

The **IADsOpenDSObject::OpenDSObject** method binds to an ADSI object, using the given credentials, and retrieves an [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) pointer to the specified object.

**Important** It is not recommended that you use this method with the WinNT Provider. For more information, please see KB article 218497, [User authentication issues with the Active Directory Service Interfaces WinNT provider](https://learn.microsoft.com/troubleshoot/windows-client/admin-development/adsi-winnt-provider-user-authentication-issues).

## Parameters

### `lpszDNName` [in]

The null-terminated Unicode string that specifies the ADsPath of the ADSI object. For more information and examples of binding strings for this parameter, see [LDAP ADsPath](https://learn.microsoft.com/windows/desktop/ADSI/ldap-adspath). When using the LDAP provider with an ADsPath that includes a specific server name, the *lnReserved* parameter should include the **ADS_SERVER_BIND** flag.

### `lpszUserName` [in]

The null-terminated Unicode string that specifies the user name to be used for securing permission from the namespace server. For more information, see the following Remarks section.

### `lpszPassword` [in]

The null-terminated Unicode string that specifies the password to be used to obtain permission from the namespace server.

### `lnReserved` [in]

Authentication flags used to define the binding options. For more information, see [ADS_AUTHENTICATION_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_authentication_enum).

### `ppOleDsObj` [out]

Pointer to a pointer to an [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface on the requested object.

## Return value

This method supports the standard return values, including **S_OK** when the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface has been successfully retrieved using these credentials.

For more information, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

This method should not be used just to validate user credentials.

When *lnReserved* is set, the behavior of **OpenDSObject** depends on the provider it connects to. High security namespaces may ignore these flags and always require authentication.

The **IADsOpenDSObject::OpenDSObject** method maintains the authenticated and encrypted user credentials in the cache. Cached credentials may be used in subsequent operations for binding to any other directory objects. The ADSI client applications should not cache the credentials supplied by the user. Instead, they should rely on ADSI infrastructure to perform caching. To use the cached credentials, *lpszPassword* and *lpszUserName* must remain unchanged in any subsequent calls of **OpenDSObject**. The following code example shows this operation.

```vb
Dim dso As IADsOpenDSObject
Dim obj1, obj2 As IADs
Dim szUsername As String
Dim szPassword As String

Set dso = GetObject("LDAP:")

' Insert code securely.

' Supply full credentials to initiate a server connection.
Set obj1 = dso.OpenDSObject( _
    "LDAP://server1/CN=Dept1,DC=Fabrikam,DC=com", _
    szUsername, _
    szPassword, _
    ADS_SECURE_AUTHENTICATION + ADS_SERVER_BIND)

' Perform an operation with the bound object, obj1
MsgBox obj1.Class

' Bind to another object with the cached user credential.
Set obj2 = dso.OpenDSObject( _
    "LDAP://server1/CN=Dept2,DC=Fabrikam,DC=com", _
    szUsername, _
    szPassword, _
    ADS_SECURE_AUTHENTICATION + ADS_SERVER_BIND)

MsgBox obj2.Class

```

The credentials passed to the **IADsOpenDSObject::OpenDSObject** function are used only with the particular object bound to and do not affect the security context of the calling thread. This means that, in the following code example, the call to **IADsOpenDSObject::OpenDSObject** will use different credentials than the call to **GetObject**.

```vb
Dim dso As IADsOpenDSObject
Dim obj1, obj2 As IADs
Dim szUsername As String
Dim szPassword As String

Set dso = GetObject("LDAP:")

' Insert code securely.

' Bind using full credentials.
Set obj1 = dso.OpenDSObject( _
    "LDAP://server1/CN=Dept1,DC=Fabrikam,DC=com", _
    szUsername, _
    szPassword, _
    ADS_SECURE_AUTHENTICATION + ADS_SERVER_BIND)

' Bind to another object with the default credentials.
Set obj2 = GetObject("LDAP://server1/CN=Dept2,DC=Fabrikam,DC=com")
```

With a serverless binding, the server name, "server1", is not stated explicitly. The default server is used instead. Only the LDAP provider supports the serverless binding. To use this feature, the client computer must be on an Active Directory domain. To attempt a serverless binding from a computer, you must bind as a domain user.

For credential caching to work properly, it is important to keep an object reference outstanding to maintain the cache handle. In the example given above, an attempt to open "obj2" after releasing "obj1" will result in an authentication failure.

The [IADsOpenDSObject](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsopendsobject) method uses the default credentials when *lpszUserName* and *lpszPassword* are set to **NULL**.

If Kerberos authentication is required for the successful completion of a specific directory request using the LDAP provider, the *lpszDNName* binding string must use either a serverless ADsPath, such as "LDAP://CN=Jeff Smith,CN=admin,DC=Fabrikam,DC=com", or it must use an ADsPath with a fully qualified DNS server name, such as "LDAP://central3.corp.Fabrikam.com/CN=Jeff Smith,CN=admin,DC=Fabrikam,DC=com". Binding to the server using a flat NETBIOS name or a short DNS name, for example, using the short name "central3" instead of "central3.corp.Fabrikam.com", may or may not yield Kerberos authentication.

The [ADsOpenObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsopenobject) helper function offers the same features as the **IADsOpenDSObject::OpenDSObject** method.

With the LDAP provider for Active Directory, you may pass in *lpszUserName* as one of the following strings:

* The name of a user account, such as "jeffsmith". To use a user name by itself, you must set only the **ADS_SECURE_AUTHENTICATION** flag in the *lnReserved* parameter.
* The user path from a previous version of Windows, such as "Fabrikam\jeffsmith".
* Distinguished Name, such as "CN=Jeff Smith,OU=Sales,DC=Fabrikam,DC=Com". To use a DN, the *lnReserved* parameter must be zero or it must include the **ADS_USE_SSL** flag
* User Principal Name (UPN), such as "jeffsmith@Fabrikam.com". To use a UPN, you must assign the appropriate UPN value for the *userPrincipalName* attribute of the target user object.

#### Examples

The following code example shows how to use [IADsOpenDSObject](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsopendsobject) to open the "Administrator" user object on "Fabrikam" with Secure Authentication through the LDAP provider.

```vb
Dim dso As IADsOpenDSObject
Dim domain As IADsDomain
Dim szUsername As String
Dim szPassword As String

On Error GoTo Cleanup

' Insert code to securely retrieve the user name and password.

Set dso = GetObject("LDAP:")
Set domain = dso.OpenDSObject("LDAP://Fabrikam", szUsername, _
                              szPassword, _
                              ADS_SECURE_AUTHENTICATION)

Cleanup:
    If (Err.Number <> 0 ) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set dso = Nothing
    Set domain = Nothing
```

The following code example uses [IADsOpenDSObject](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsopendsobject) to open an Active Directory object through the LDAP provider.

```cpp
IADsOpenDSObject *pDSO = NULL;
HRESULT hr = S_OK;

hr = ADsGetObject(L"LDAP:", IID_IADsOpenDSObject, (void**) &pDSO);
if (SUCCEEDED(hr))
{
    IDispatch *pDisp;
    hr = pDSO->OpenDSObject(CComBSTR("LDAP://DC=Fabrikam, DC=com"),
                       CComBSTR("jeffsmith@Fabrikam.com"),
                       CComBSTR("passwordhere"),
                       ADS_SECURE_AUTHENTICATION,
                       &pDisp);
    pDSO->Release();
    if (SUCCEEDED(hr))
    {
        IADs *pADs;
        hr = pDisp->QueryInterface(IID_IADs, (void**) &pADs);
        pDisp->Release();
        if (SUCCEEDED(hr))
        {
        // Perform an object manipulation here.
            pADs->Release();
        }
    }
}
```

## See also

[ADSI Error
Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADS_AUTHENTICATION_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_authentication_enum)

[ADsOpenObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsopenobject)

[Binding](https://learn.microsoft.com/windows/desktop/wsw/binding)

[GetObject](https://learn.microsoft.com/windows/desktop/ADSI/binding-with-getobject-and-adsgetobject)

[IADsOpenDSObject](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsopendsobject)

[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)

[LDAP ADsPath](https://learn.microsoft.com/windows/desktop/ADSI/ldap-adspath)

[WNetAddConnetion2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection2a)