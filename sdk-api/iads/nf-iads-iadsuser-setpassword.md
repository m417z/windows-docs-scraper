## Description

The **IADsUser::SetPassword** method sets the user password to a specified value. For the LDAP provider, the user account must have been created and stored in the underlying directory using [IADs::SetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-setinfo) before **IADsUser::SetPassword** is called.

The WinNT provider, however, enables you to set the password on a newly created user object prior to calling [SetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-setinfo). This ensures that you create passwords that comply with the system password policy before you create the user account.

## Parameters

### `NewPassword`

A **BSTR** that contains the new password.

## Return value

This method supports the standard return values, including **S_OK**. For other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

The LDAP provider for Active Directory uses one of three processes to set the password; third-party LDAP directories such as iPlanet do not use this password authentication process. The method may vary according to the network configuration. Attempts to set the password occur in the following order:

* First, the LDAP provider attempts to use LDAP over a 128-bit SSL connection. For LDAP SSL to operate successfully, the LDAP server must have the appropriate server authentication certificate installed and the clients running the ADSI code must trust the authority that issued those certificates. Both the server and the client must support 128-bit encryption.
* Second, if the SSL connection is unsuccessful, the LDAP provider attempts to use Kerberos.
* Third, if Kerberos is unsuccessful, the LDAP provider attempts a [NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo) API call. In previous releases, ADSI called **NetUserSetInfo** in the security context in which the thread was running, and not the security context specified in the call to [IADsOpenDSObject::OpenDSObject](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsopendsobject-opendsobject) or [ADsOpenObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsopenobject). In later releases, this was changed so that the ADSI LDAP provider would impersonate the user specified in the **OpenDSObject** call when it calls NetUserSetInfo.

In Active Directory, the caller must have the [Reset Password](https://learn.microsoft.com/windows/desktop/ADSchema/r-user-force-change-password) extended control access right to set the password with this method.

#### Examples

The following code example shows how to set the user password, if you have the permission to do so.

```vb
Dim usr As IADsUser
Dim szPassword As String
On Error GoTo Cleanup

' Add code to securely get the password.

Set usr = GetObject("LDAP://MyLdapSvr/CN=JeffSmith,DC=Fabrikam")
usr.SetPassword szPassword

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set usr = Nothing
```

The following code example shows how to set the user password, if you have the permission to do so.

```cpp
HRESULT SetPassword(IADsUser *pUser, BSTR password)
{
    HRESULT hr=S_OK;
    if(!pUser) { return E_FAIL;}
    hr = pUser->SetPassword(password);
    if (hr == S_OK) printf("User password has been set");
    pUser->Release();
    return hr;
}

```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADs::SetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-setinfo)

[IADsMembers](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsmembers)

[IADsServiceOperations](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsserviceoperations)

[IADsUser](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsuser)

[IADsUser
Property Methods](https://learn.microsoft.com/windows/desktop/ADSI/iadsuser-property-methods)

[NetUserSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetinfo)