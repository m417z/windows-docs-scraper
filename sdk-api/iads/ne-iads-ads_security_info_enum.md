# ADS_SECURITY_INFO_ENUM enumeration

## Description

The **ADS_SECURITY_INFO_ENUM** enumeration specifies the available options for examining security data of an object.

## Constants

### `ADS_SECURITY_INFO_OWNER:0x1`

Reads or sets the owner data.

### `ADS_SECURITY_INFO_GROUP:0x2`

Reads or sets the group data.

### `ADS_SECURITY_INFO_DACL:0x4`

Reads or sets the discretionary access-control list data.

### `ADS_SECURITY_INFO_SACL:0x8`

Reads or sets the system access-control list data.

## Remarks

The options defined in this enumeration are bit-masks. More than one option can be set using appropriate bitwise operations.

To read the security data for an object, use the [IADsObjectOptions](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsobjectoptions) interface, supplying the security data options listed in this enumeration.

The following list lists common flag combinations and their use.

| Flag combination | Description |
| --- | --- |
| **ADS_SECURITY_INFO_OWNER**, **ADS_SECURITY_INFO_GROUP**, and **ADS_SECURITY_INFO_DACL** | Enable users to read the security data of the owner, group, or DACL of an object. This is the default setting when an object is created. |
| **ADS_SECURITY_INFO_OWNER**, **ADS_SECURITY_INFO_GROUP**, **ADS_SECURITY_INFO_DACL**, and **ADS_SECURITY_INFO_SACL** | Enable users to read the SACL. The **ADS_SECURITY_INFO_SACL** flag cannot be used by itself. |

Presently, such options are available for Active Directory only.

Because Visual Basic Scripting Edition (VBScript) cannot read data from a type library, an application must use the appropriate numeric constants, instead of the symbolic constants, to set the appropriate flags. To use the symbolic constants as a good programming practice, write explicit declarations of such constants, as done here.

#### Examples

The following code example displays the number of access control entries in a SACL.

```vb
Const ADS_SECURITY_INFO_OWNER = &H1
Const ADS_SECURITY_INFO_GROUP = &H2
Const ADS_SECURITY_INFO_DACL = &H4
Const ADS_SECURITY_INFO_SACL = &H8

Const ADS_OPTION_SECURITY_MASK = 3

Dim x As IADs
Dim dso As IADsOpenDSObject
Dim adsPath As String
Dim sd As IADsSecurityDescriptor
Dim sacl As IADsAccessControlList
Dim objOps As IADsObjectOptions
Dim opt As Variant
Dim canReadSacl As Variant

Set dso = GetObject("LDAP:")
adsPath = "LDAP://ArcSrv1/dc=Sales,dc=Fabrikam,dc=com"
Set x = dso.OpenDSObject(adsPath, vbNullString, vbNullString, 1)
Set objOps = x

canReadSacl = ADS_SECURITY_INFO_OWNER _
                Or ADS_SECURITY_INFO_GROUP _
                Or ADS_SECURITY_INFO_DACL _
                Or ADS_SECURITY_INFO_SACL

opt = objOps.GetOption(ADS_OPTION_SECURITY_MASK)
If opt <> canReadSacl Then
    objOps.SetOption ADS_OPTION_SECURITY_MASK, canReadSacl
End If
Set sd = x.Get("ntSecurityDescriptor")
Set sacl = sd.SystemAcl
Debug.Print "sacl(aceCount)= " & sacl.AceCount
```

The following code example displays the number of access-control entries in a system ACL. For brevity, error checking is omitted.

```cpp
void TestObjectOptions()
{
    long lCanReadSACL = ADS_SECURITY_INFO_OWNER |
        ADS_SECURITY_INFO_GROUP |
        ADS_SECURITY_INFO_DACL |
        ADS_SECURITY_INFO_SACL;

    HRESULT hr = S_OK;
    CComPtr<IADs> spObj;
    hr = ADsOpenObject(L"LDAP://arcSrv1/dc=Sales,dc=Fabrikam,dc=com",
        NULL,
        NULL,
        ADS_SECURE_AUTHENTICATION,
        IID_IADs,
        (void**)&spObj);
    if(S_OK != hr)
    {
        return;
    }

    CComPtr<IADsObjectOptions> spObjOps;
    hr = spObj->QueryInterface(IID_IADsObjectOptions, (void**)&spObjOps);
    if(S_OK != hr)
    {
        return;
    }

    CComVariant svar;
    hr = spObjOps->GetOption(ADS_OPTION_SECURITY_MASK, &svar);
    if(S_OK != hr)
    {
        return;
    }

    if(V_I4(&svar) != lCanReadSACL)
    {
        svar = lCanReadSACL;
        hr = spObjOps->SetOption(ADS_OPTION_SECURITY_MASK, svar);
    }

    hr = spObj->Get(CComBSTR("ntSecurityDescriptor"), &svar);
    if(S_OK != hr)
    {
        return;
    }

    CComPtr<IADsSecurityDescriptor> spSd;
    hr = V_DISPATCH(&svar)->QueryInterface(IID_IADsSecurityDescriptor,
                                            (void**)&spSd);
    if(S_OK != hr)
    {
        return;
    }

    CComPtr<IDispatch> spDisp;
    hr = spSd->get_SystemAcl(&spDisp);
    if(S_OK != hr)
    {
        return;
    }

    CComPtr<IADsAccessControlList> spSacl;
    hr = spDisp->QueryInterface(IID_IADsAccessControlList,
                                (void**)&spSacl);
    if(S_OK != hr)
    {
        return;
    }

    LONG lOptions;
    hr = spSacl->get_AceCount(&lOptions);
    if(S_OK != hr)
    {
        return;
    }

    _tprintf(TEXT("Number of ACE's in the SACL is %d\n"), lOptions);
}
```

## See also

[ADSI Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[IADsObjectOptions](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsobjectoptions)

[IADsObjectOptions::GetOption](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsobjectoptions-getoption)

[IADsObjectOptions::SetOption](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsobjectoptions-setoption)