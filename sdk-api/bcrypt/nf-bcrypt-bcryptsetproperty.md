# BCryptSetProperty function

## Description

The **BCryptSetProperty** function sets the value of a named property for a CNG object.

## Parameters

### `hObject` [in, out]

A handle that represents the CNG object to set the property value for.

### `pszProperty` [in]

A pointer to a null-terminated Unicode string that contains the name of the property to set. This can be one of the predefined [Cryptography Primitive Property Identifiers](https://learn.microsoft.com/windows/win32/SecCNG/cng-property-identifiers) or a custom property identifier.

### `pbInput` [in]

The address of a buffer that contains the new property value. The *cbInput* parameter contains the size of this buffer.

### `cbInput` [in]

The size, in bytes, of the *pbInput* buffer.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. No flags are defined for this function.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following:

| Return code | Description |
|--|--|
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_HANDLE** | The handle in the *hObject* parameter is not valid. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |
| **STATUS_NOT_SUPPORTED** | The named property specified by the *pszProperty* parameter is not supported or is read-only. |

## Remarks

When using a supported algorithm provider, **BCryptSetProperty** can be called either from user mode or kernel mode. Kernel mode callers can execute either at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/win32/SecGloss/i-gly) or **DISPATCH_LEVEL** IRQL. If the current IRQL level is **DISPATCH_LEVEL**, any pointers passed to **BCryptSetProperty** must refer to nonpaged (or locked) memory. If the object specified in the *hObject* parameter is a handle, it must have been opened by using the **BCRYPT_PROV_DISPATCH** flag.

To call this function in kernel mode, use `Cng.lib`, which is part of the Driver Development Kit (DDK). **Windows Server 2008 and Windows Vista:** To call this function in kernel mode, use `Ksecdd.lib`.

When [generating keys](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptgeneratekeypair) for ML-DSA and ML-KEM, the **BCRYPT_PARAMETER_SET_NAME** property must be set on the key handle, before the key can be [finalized](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptfinalizekeypair).

When setting the value for the property *BCRYPT_CHAINING_MODE*, the *pbInput* parameter is unbounded by *cbInput*. The caller needs to ensure a valid null-terminated Unicode string is provided.

## See also

[Cryptography Primitive Property Identifiers](https://learn.microsoft.com/windows/win32/SecCNG/cng-property-identifiers)