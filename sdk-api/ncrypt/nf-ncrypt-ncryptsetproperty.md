# NCryptSetProperty function

## Description

The **NCryptSetProperty** function sets the value for a named property for a CNG key storage object.

## Parameters

### `hObject` [in]

The handle of the key storage object to set the property for.

### `pszProperty` [in]

A pointer to a null-terminated Unicode string that contains the name of the property to set. This can be one of the predefined [Key Storage Property Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/key-storage-property-identifiers) or a custom property identifier.

### `pbInput` [in]

The address of a buffer that contains the new property value. The *cbInput* parameter contains the size of this buffer.

### `cbInput` [in]

The size, in bytes, of the *pbInput* buffer.

### `dwFlags` [in]

Flags that modify function behavior. This can be zero or a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **NCRYPT_PERSIST_FLAG** | The property should be stored in key storage along with the key material. This flag can only be used when the *hObject* parameter is the handle of a persisted key. The maximum size of the data for any persisted property is **NCRYPT_MAX_PROPERTY_DATA** bytes. |
| **NCRYPT_PERSIST_ONLY_FLAG** | Do not overwrite any built-in values for this property and only set the user-persisted properties of the key. The maximum size of the data for any persisted property is **NCRYPT_MAX_PROPERTY_DATA** bytes. This flag cannot be used with the **NCRYPT_SECURITY_DESCR_PROPERTY** property. |
| **NCRYPT_SILENT_FLAG** | Requests that the key storage provider (KSP) not display any user interface. If the provider must display the UI to operate, the call fails and the KSP should set the **NTE_SILENT_CONTEXT** error code as the last error. |

For the **NCRYPT_SECURITY_DESCR_PROPERTY** property, this parameter must also contain one of the following values, which identifies the part of the security descriptor to set.

| Value | Meaning |
| --- | --- |
| **OWNER_SECURITY_INFORMATION** | Set the [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) of the object's owner. Use the [SetSecurityDescriptorOwner](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorowner) function to set the owner SID in the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure. |
| **GROUP_SECURITY_INFORMATION** | Set the SID of the object's primary group. Use the [SetSecurityDescriptorGroup](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorgroup) function to set the group SID in the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure. |
| **DACL_SECURITY_INFORMATION** | Set the [discretionary access control list](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DACL). Use the [SetSecurityDescriptorDacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptordacl) function to set the DACL in the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure. |
| **SACL_SECURITY_INFORMATION** | Set the [system access control list](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SACL). Use the [SetSecurityDescriptorSacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorsacl) function to set the SACL in the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure. |
| **LABEL_SECURITY_INFORMATION** | Set the mandatory label access control entry in the SACL of the object. Use the [SetSecurityDescriptorSacl](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-setsecuritydescriptorsacl) function to set the SACL in the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure. For more information about the mandatory label access control entry, see [Windows Integrity Mechanism Design](https://learn.microsoft.com/previous-versions/dotnet/articles/bb625963(v=msdn.10)). |

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter contains a value that is not valid. |
| **NTE_INVALID_HANDLE** | The *hObject* parameter is not valid. |
| **NTE_INVALID_PARAMETER** | One or more parameters are not valid. |
| **NTE_NO_MEMORY** | A memory allocation failure occurred. |
| **NTE_NOT_SUPPORTED** | The specified property is not supported for the object. |

## Remarks

A service must not call this function from its [StartService Function](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea). If a service calls this function from its StartService function, a deadlock can occur, and the service may stop responding.