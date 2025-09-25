# ADsGetObject function

## Description

The **ADsGetObject** function binds to an object given its path and a specified interface identifier.

## Parameters

### `lpszPathName` [in]

Type: **LPCWSTR**

The null-terminated Unicode string that specifies the path used to bind to the object in the underlying directory service. For more information and code examples for binding strings for this parameter, see [LDAP ADsPath](https://learn.microsoft.com/windows/desktop/ADSI/ldap-adspath) and [WinNT ADsPath](https://learn.microsoft.com/windows/desktop/ADSI/winnt-adspath).

### `riid` [in]

Type: **REFIID**

Interface identifier for a specified interface on this object.

### `ppObject` [out]

Type: **VOID****

Pointer to a pointer to the requested Interface.

## Return value

Type: **HRESULT**

This method supports the standard **HRESULT** return values, as well as the following.

For more information about other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

A C/C++ client calls the **ADsGetObject** helper function to bind to an ADSI object. It is equivalent to a Visual Basic client calling the [GetObject](https://learn.microsoft.com/windows/desktop/ADSI/binding-with-getobject-and-adsgetobject) function. They both take an ADsPath as input and returns a pointer to the requested interface. By default the binding uses ADS_SECURE_AUTHENTICATION option with the security context of the calling thread. However, if the authentication fails, the secure bind is downgraded to an anonymous bind, for example, a simple bind without user credentials. To securely bind to an ADSI object, use the [ADsOpenObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsopenobject) function instead of the **ADsGetObject** function.

For a code example that shows how to use [ADsOpenObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsopenobject), see [Binding With GetObject and ADsGetObject](https://learn.microsoft.com/windows/desktop/ADSI/binding-with-getobject-and-adsgetobject).

It is possible to bind to an ADSI object with a user credential different from that of the currently logged-on user. To perform this operation, use the [ADsOpenObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsopenobject) function.

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADSI Functions](https://learn.microsoft.com/windows/desktop/ADSI/adsi-functions)

[ADsOpenObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsopenobject)

[Binding With GetObject and ADsGetObject](https://learn.microsoft.com/windows/desktop/ADSI/binding-with-getobject-and-adsgetobject)