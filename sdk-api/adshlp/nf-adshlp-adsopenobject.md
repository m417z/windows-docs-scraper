# ADsOpenObject function

## Description

The **ADsOpenObject** function binds to an ADSI object using explicit user name and password credentials.**ADsOpenObject** is a wrapper function for [IADsOpenDSObject](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsopendsobject) and is equivalent to the [IADsOpenDSObject::OpenDsObject](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsopendsobject-opendsobject) method.

## Parameters

### `lpszPathName` [in]

Type: **LPCWSTR**

The null-terminated Unicode string that specifies the ADsPath of the ADSI object. For more information and code examples of binding strings for this parameter, see [LDAP ADsPath](https://learn.microsoft.com/windows/desktop/ADSI/ldap-adspath) and [WinNT ADsPath](https://learn.microsoft.com/windows/desktop/ADSI/winnt-adspath).

### `lpszUserName` [in]

Type: **LPCWSTR**

The null-terminated Unicode string that specifies the user name to supply to the directory service to use for credentials. This string should always be in the format "\<domain\\>\<user name>" to avoid ambiguity. For example, if DomainA and DomainB have a trust relationship and both domains have a user with the name "user1", it is not possible to predict which domain **ADsOpenObject** will use to validate "user1".

### `lpszPassword` [in]

Type: **LPCWSTR**

The null-terminated Unicode string that specifies the password to supply to the directory service to use for credentials.

### `dwReserved` [in]

Type: **DWORD**

Provider-specific authentication flags used to define the binding options. For more information, see [ADS_AUTHENTICATION_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_authentication_enum).

### `riid` [in]

Type: **REFIID**

Interface identifier for the requested interface on this object.

### `ppObject` [out]

Type: **VOID****

Pointer to a pointer to the requested interface.

## Return value

Type: **HRESULT**

This method supports the standard **HRESULT** return values, including the following.

For more information, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

This function should not be used just to validate user credentials.

A C/C++ client calls the **ADsOpenObject** helper function to bind to an ADSI object, using the user name and password supplied as credentials for the appropriate directory service. If *lpszUsername* and *lpszPassword* are **NULL** and **ADS_SECURE_AUTHENTICATION** is set, ADSI binds to the object using the security context of the calling thread, which is either the security context of the user account under which the application is running or of the client user account that the calling thread impersonates.

The credentials passed to the **ADsOpenObject** function are used only with the particular object bound to and do not affect the security context of the calling thread. This means that, in the example below, the call to **ADsOpenObject** will use different credentials than the call to [ADsGetObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsgetobject).

```cpp
HRESULT hr;
IADs *padsRoot1;
IADs *padsRoot2;

hr = ADsOpenObject(L"LDAP://rootDSE",
    pwszUsername,
    pwszPassword,
    ADS_SECURE_AUTHENTICATION,
    IID_IADs,
    (LPVOID*)&padsRoot1);

hr = ADsGetObject(L"LDAP://rootDSE",
    IID_IADs,
    (LPVOID*)&padsRoot2);

```

To work with the WinNT: provider, you can pass in *lpszUsername* as one of the following strings:

* The name of a user account, that is, "jeffsmith".
* The Windows style user name, that is, "Fabrikam\jeffsmith".

With the LDAP provider for Active Directory, you may pass in *lpszUsername* as one of the following strings:

* The name of a user account, such as "jeffsmith". To use a user name by itself, you must set only the **ADS_SECURE_AUTHENTICATION** flag in the *dwReserved* parameter.
* The user path from a previous version of Windows, such as "Fabrikam\jeffsmith".
* Distinguished Name, such as "CN=Jeff Smith,OU=Sales,DC=Fabrikam,DC=Com". To use a DN, the *dwReserved* parameter must be zero or it must include the **ADS_USE_SSL** flag.
* User Principal Name (UPN), such as "jeffsmith@Fabrikam.com". To use a UPN, assign the appropriate UPN value for the **userPrincipalName** attribute of the target user object.

If Kerberos authentication is required for the successful completion of a specific directory request using the LDAP provider, the *lpszPathName* binding string must use either a serverless ADsPath, such as "LDAP://CN=Jeff Smith,CN=admin,DC=Fabrikam,DC=com", or it must use an ADsPath with a fully qualified DNS server name, such as "LDAP://central3.corp.Fabrikam.com/CN=Jeff Smith,CN=admin,DC=Fabrikam,DC=com". Binding to the server using a flat NETBIOS name or a short DNS name, for example, using the short name "central3" instead of "central3.corp.Fabrikam.com", may or may not yield Kerberos authentication.

The following code example shows how to bind to a directory service object with the requested user credentials.

```cpp
IADs *pObject;
LPWSTR szUsername = NULL;
LPWSTR szPassword = NULL
HRESULT hr;

// Insert code to securely retrieve the user name and password.

hr = ADsOpenObject(L"LDAP://CN=Jeff,DC=Fabrikam,DC=com",
                   "jeffsmith",
                   "etercespot",
                   ADS_SECURE_AUTHENTICATION,
                   IID_IADs,
                   (void**) &pObject);
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADSI Functions](https://learn.microsoft.com/windows/desktop/ADSI/adsi-functions)

[ADsOpenObject and IADsOpenDSObject::OpenDsObject](https://learn.microsoft.com/windows/desktop/ADSI/binding-with-adsopenobject-and-iadsopendsobject-opendsobject)

[Binding](https://learn.microsoft.com/windows/desktop/wsw/binding)

[IADsOpenDSObject](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsopendsobject)

[IADsOpenDSObject::OpenDsObject](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsopendsobject-opendsobject)