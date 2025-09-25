# BCryptFinishHash function

## Description

The **BCryptFinishHash** function retrieves the hash or [Message Authentication Code](https://learn.microsoft.com/windows/win32/SecGloss/m-gly) (MAC) value for the data accumulated from prior calls to [BCryptHashData](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcrypthashdata).

## Parameters

### `hHash` [in, out]

The handle of the hash or MAC object to use to perform the operation. This handle is obtained by calling the [BCryptCreateHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptcreatehash) or [BCryptDuplicateHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptduplicatehash) functions. After this function has been called, the *hHash* handle cannot be reused, unless it was created with the **BCRYPT_HASH_REUSABLE_FLAG** flag.

### `pbOutput` [out]

A pointer to a buffer that receives the hash or MAC value. The *cbOutput* parameter contains the size of this buffer.

### `cbOutput` [in]

The size, in bytes, of the *pbOutput* buffer. This size must exactly match the size of the hash or MAC value if it has a fixed size.

The size can be obtained by calling the [BCryptGetProperty](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptgetproperty) function to get the **BCRYPT_HASH_LENGTH** property. This will provide the size of the hash or MAC value for the specified algorithm. Extendable-output functions (XOFs), such as SHAKE256 may support a variable output size, but a default size which maintains full security of the XOF can be queried using **BCRYPT_HASH_LENGTH**.

### `dwFlags` [in]

A set of flags that modify the behavior of this function.

This can be zero or a combination of one or more of the following values:

| Value | Meaning |
|-------|---------|
| **BCRYPT_HASH_DONT_RESET_FLAG** | This flag only applies to Extendable-output functions (XOFs), such as SHAKE, CSHAKE, and KMAC. XOFs support variable output size, and this flag allows that variable output to be extracted incrementally. When this flag is specified, the *hHash* handle is not reset by this call to *BCryptFinishHash*, meaning further *BCryptFinishHash* calls can be made to extract additional output. A final call to *BCryptFinishHash* without specifying this flag will reset the state of XOF operation, the same as a call to *BCryptFinishHash* for a non-XOF algorithm.**Windows 11, version 24H2:** Support for XOFs begins. |

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following:

| Return code | Description |
|-------------|-------------|
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_HANDLE** | The hash handle in the *hHash* parameter is not valid. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. This includes the case where *cbOutput* is not the same size as the fixed size output of the hash or MAC. |

## Remarks

When using a supported algorithm provider, **BCryptFinishHash** can be called either from user mode or kernel mode. Kernel mode callers can execute either at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/win32/SecGloss/i-gly) or **DISPATCH_LEVEL** IRQL. If the current IRQL level is **DISPATCH_LEVEL**, the handle provided in the *hHash* parameter must be derived from an algorithm handle returned by a provider that was opened by using the **BCRYPT_PROV_DISPATCH** flag, and any pointers passed to the **BCryptFinishHash** function must refer to nonpaged (or locked) memory.

To call this function in kernel mode, use `Cng.lib`, which is part of the Driver Development Kit (DDK). **Windows Server 2008 and Windows Vista:** To call this function in kernel mode, use `Ksecdd.lib`.

## See also

[BCryptCreateHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptcreatehash)

[BCryptDuplicateHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptduplicatehash)

[BCryptHashData](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcrypthashdata)

[BCryptDestroyHash](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptdestroyhash)