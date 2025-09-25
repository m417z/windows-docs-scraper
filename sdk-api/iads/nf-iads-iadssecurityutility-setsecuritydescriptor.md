# IADsSecurityUtility::SetSecurityDescriptor

## Description

The **SetSecurityDescriptor** method sets the security descriptor for the specified file, file share, or registry key.

## Parameters

### `varPath` [in]

A **VARIANT** string that contains the path of the object to set the security descriptor for. Possible values are listed in the following list.

#### File

A valid file path syntax. For example: "c:\specs\public\adxml.doc" or "\\adsi\public\dsclient.exe".

#### File share

A valid file path syntax for a file share. For example: "\\adsi\public".

#### Registry key

A valid registry syntax. For example, "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\ADs".

### `lPathFormat` [in]

Contains one of the [ADS_PATHTYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_pathtype_enum) values which specifies the format of the *varPath* parameter.

### `varData` [in]

A **VARIANT** that contains the new security descriptor. The format of the security descriptor is specified by the *lDataFormat* parameter.

### `lDataFormat` [in]

Contains one of the [ADS_SD_FORMAT_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_sd_format_enum) values which specifies the format of the security descriptor contained in the *VarData* parameter. The following list identifies the possible values for this parameter and the format of the *VarData* parameter.

## Return value

Returns **S_OK** if successful or a COM or Win32 error code otherwise. Possible error codes are listed in the following list.

## Remarks

Access control entries must appear in the following order in a security descriptor's access control list:

* Access-denied ACEs that apply to the object itself
* Access-denied ACEs that apply to a child of the object, such as a property set or property
* Access-allowed ACEs that apply to the object itself
* Access-allowed ACEs that apply to a child of the object, such as a property set or property
* All inherited ACEs

#### Examples

The following code example shows how to set a security descriptor for a file.

```vb
Dim dacl as IADsAccessControlList
Dim sd as IADsSecurityDescriptor
Dim newAce as New AccessControlEntry
Dim sdUtil as New ADsSecurityUtility

Set sd = sdUtil.GetSecurityDescriptor("c:\specs\adsixml.doc", ADS_PATH_FILE, ADS_SD_FORMAT_IID )
Set dacl = sd.DiscretionaryAcl

' Add a new ACE for Jeff Smith.
newAce.Trustee = "Fabrikam\jeffsmith"
newAce.AccessMask = ADS_RIGHT_GENERIC_READ Or ADS_RIGHT_GENERIC_EXECUTE

newAce.AceType = ADS_ACETYPE_ACCESS_ALLOWED

dacl.AddAce newAce
sd.DiscretionaryAcl = dacl
sdUtil.SetSecurityDescriptor "c:\specs\adsixml.doc", ADS_PATH_FILE, sd, ADS_SD_FORMAT_IID

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set dacl = Nothing
    Set sd = Nothing
    Set newAce = Nothing
    Set sdUtil = Nothing

```

## See also

[ADS_PATHTYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_pathtype_enum)

[ADS_SD_FORMAT_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_sd_format_enum)

[ConvertSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadssecurityutility-convertsecuritydescriptor)

[IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor)

[IADsSecurityUtility](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecurityutility)