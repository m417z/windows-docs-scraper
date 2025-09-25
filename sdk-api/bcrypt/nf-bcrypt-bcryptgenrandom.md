# BCryptGenRandom function

## Description

The **BCryptGenRandom** function generates a random number.

## Parameters

### `hAlgorithm` [in, out]

The handle of an algorithm provider created by using the [BCryptOpenAlgorithmProvider](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptopenalgorithmprovider) function. The algorithm that was specified when the provider was created must support the random number generator interface.

### `pbBuffer` [in, out]

The address of a buffer that receives the random number. The size of this buffer is specified by the *cbBuffer* parameter.

### `cbBuffer` [in]

The size, in bytes, of the *pbBuffer* buffer.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. This parameter can be zero or the following value.

| Value | Meaning |
| --- | --- |
| **BCRYPT_RNG_USE_ENTROPY_IN_BUFFER**<br><br>0x00000001 | This function will use the number in the *pbBuffer* buffer as additional entropy for the random number. If this flag is not specified, this function will use a random number for the entropy.<br><br>**Windows 8 and later:** This flag is ignored in Windows 8 and later. |
| **BCRYPT_USE_SYSTEM_PREFERRED_RNG**<br><br>0x00000002 | Use the system-preferred random number generator algorithm. The *hAlgorithm* parameter must be **NULL**.<br><br>BCRYPT_USE_SYSTEM_PREFERRED_RNG is only supported at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly). For more information, see Remarks.<br><br>**Windows Vista:** This flag is not supported without SP2. |

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function was successful. |
| **STATUS_INVALID_HANDLE** | The handle in the *hAlgorithm* parameter is not valid. |
| **STATUS_INVALID_PARAMETER** | One or more parameters are not valid. |

## Remarks

The default random number provider implements an algorithm for generating random numbers that complies with the NIST SP800-90 standard, specifically the CTR_DRBG portion of that standard.

**Windows Vista:** Prior to Windows Vista with Service Pack 1 (SP1) the default random number provider implements an algorithm for generating random numbers that complies with the FIPS 186-2 standard.

When using a supported algorithm provider, **BCryptGenRandom** can be called either from user mode or kernel mode. Kernel mode callers can execute either at **PASSIVE_LEVEL** [IRQL](https://learn.microsoft.com/windows/desktop/SecGloss/i-gly) or **DISPATCH_LEVEL** IRQL. If the current IRQL level is **DISPATCH_LEVEL**, the handle provided in the *hAlgorithm* parameter must have been opened by using the **BCRYPT_PROV_DISPATCH** flag, and any pointers passed to the **BCryptGenRandom** function must refer to nonpaged (or locked) memory. **Windows Vista:** The Microsoft provider does not support calling at **DISPATCH_LEVEL**.

To call this function in kernel mode, use Cng.lib, which is part of the Driver Development Kit (DDK). **Windows Server 2008 and Windows Vista:** To call this function in kernel mode, use Ksecdd.lib.