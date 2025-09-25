# IADsUser::ChangePassword

## Description

The **IADsUser::ChangePassword** method changes the user password from the specified old value to a new value.

## Parameters

### `bstrOldPassword` [in]

A **BSTR** that contains the current password.

### `bstrNewPassword` [out]

A **BSTR** that contains the new password.

## Return value

This method supports the standard return values, including S_OK. For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

**IADsUser::ChangePassword** functions similarly to [IADsUser::SetPassword](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsuser-setpassword) in that it will use one of three methods to try to change the password. Initially, the LDAP provider will attempt an LDAP change password operation, if a secure SSL connection to the server is established. If this attempt fails, the LDAP provider will next try to use Kerberos (see **IADsUser::SetPassword** for some problems that may result on Windows with cross-forest authentication), and if this also fails, it will finally call the Active Directory specific network management API, [NetUserChangePassword](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netuserchangepassword).

In Active Directory, the caller must have the [Change Password](https://learn.microsoft.com/windows/desktop/ADSchema/r-user-change-password) extended control access right to change the password with this method.

#### Examples

The following code example shows how to change a user password.

```vb
Dim usr As IADsUser
Dim szOldPass As String
Dim szNewPass As String

On Error GoTo Cleanup

Set usr = GetObject("WinNT://Fabrikam/JeffSmith,user")
' Add code to securely retrieve the old and new password.

usr.ChangePassword szOldPass, szNewPass

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set usr = Nothing
```

The following code example shows how to change a user password.

```cpp
HRESULT ChangePassword(
    IADsUser *pUser,
    LPWSTR oldPasswd,
    LPWSTR newPasswd)
{
    HRESULT hr=S_OK;
    if(!pUser) { return E_FAIL;}
    hr = pUser->ChangePassword(oldPasswd, newPasswd);
    printf("User password has been changed");
    return hr;
}

```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsUser](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsuser)

[IADsUser
Property Methods](https://learn.microsoft.com/windows/desktop/ADSI/iadsuser-property-methods)