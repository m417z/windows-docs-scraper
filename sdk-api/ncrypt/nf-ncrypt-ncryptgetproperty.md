# NCryptGetProperty function

## Description

The **NCryptGetProperty** function retrieves the value of a named property for a key storage object.

## Parameters

### `hObject` [in]

The handle of the object to get the property for. This can be a provider handle (**NCRYPT_PROV_HANDLE**) or a key handle (**NCRYPT_KEY_HANDLE**).

### `pszProperty` [in]

A pointer to a null-terminated Unicode string that contains the name of the property to retrieve. This can be one of the predefined [Key Storage Property Identifiers](https://learn.microsoft.com/windows/win32/SecCNG/key-storage-property-identifiers) or a custom property identifier.

### `pbOutput` [out]

The address of a buffer that receives the property value. The _cbOutput_ parameter contains the size of this buffer.

 To calculate the size required for the buffer, set this parameter to **NULL**. The size, in bytes, required is returned in the location pointed to by the _pcbResult_ parameter.

### `cbOutput` [in]

The size, in bytes, of the _pbOutput_ buffer.

### `pcbResult` [out]

A pointer to a **DWORD** variable that receives the number of bytes that were copied to the _pbOutput_ buffer.

If the _pbOutput_ parameter is **NULL**, the size, in bytes, required for the buffer is placed in the location pointed to by this parameter.

### `dwFlags` [in]

Flags that modify function behavior. This can be zero or the following value.

| Value | Meaning |
| --- | --- |
| **NCRYPT_PERSIST_ONLY_FLAG** | Ignore any built in values for this property and only retrieve the user-persisted properties of the key. The maximum size of the data for any persisted property is **NCRYPT_MAX_PROPERTY_DATA** bytes. |
| **NCRYPT_SILENT_FLAG** | Requests that the key storage provider (KSP) not display any user interface. If the provider must display the UI to operate, the call fails and the KSP should set the **NTE_SILENT_CONTEXT** error code as the last error. |

For the **NCRYPT_SECURITY_DESCR_PROPERTY** property, this parameter must also contain one of the following values, which identifies the part of the security descriptor to retrieve.

| Value | Meaning |
| --- | --- |
| **OWNER_SECURITY_INFORMATION** | Retrieve the security identifier (SID) of the object's owner. Use the [GetSecurityDescriptorOwner](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorowner) function to obtain the owner SID from the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-security_descriptor) structure. |
| **GROUP_SECURITY_INFORMATION** | Retrieve the SID of the object's primary group. Use the [GetSecurityDescriptorGroup](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorgroup) function to obtain the group SID from the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-security_descriptor) structure. |
| **DACL_SECURITY_INFORMATION** | Retrieve the discretionary access control list (DACL). Use the [GetSecurityDescriptorSacl](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptorsacl) function to obtain the DACL from the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-security_descriptor) structure. |
| **SACL_SECURITY_INFORMATION** | Retrieve the system access control list (SACL). Use the [GetSecurityDescriptorDacl](https://learn.microsoft.com/windows/win32/api/securitybaseapi/nf-securitybaseapi-getsecuritydescriptordacl) function to obtain the SACL from the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-security_descriptor) structure. |

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
|-------|--------|
| `ERROR_SUCCESS` | The function was successful. |
| `NTE_BAD_FLAGS` | The `dwFlags` parameter contains a value that is not valid. |
| `NTE_INVALID_HANDLE` | The `hObject` parameter is not valid. |
| `NTE_INVALID_PARAMETER` | One or more parameters are not valid. |
| `NTE_NO_MEMORY` | A memory allocation failure occurred. |
| `NTE_NOT_SUPPORTED` | The specified property is not supported for the object. |

## Remarks

A service must not call this function from its [StartService](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea) function. If a service calls this function from its `StartService` function, a deadlock can occur, and the service may stop responding.