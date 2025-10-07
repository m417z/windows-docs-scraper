# SaferiSearchMatchingHashRules function

Gets the level of a hash identification rule that matches the specified hash.

This function has no associated import library and is not declared in a public header. You must define a function pointer with the signature of this function, and you must use the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Advapi32.dll.

We recommend using the [**SaferIdentifyLevel**](https://learn.microsoft.com/windows/win32/api/winsafer/nf-winsafer-saferidentifylevel) function to evaluate software restriction policies.

## Parameters

*HashAlgorithm* \[in, optional\]

The identifier of the algorithm used to create the hash.

*pHashBytes* \[in\]

A pointer to an array of bytes that contains the hash.

*dwHashSize* \[in\]

The size, in bytes, of the *pHashBytes* array.

*dwOriginalImageSize* \[in, optional\]

The size, in bytes, of the original image from which the hash was computed.

*pdwFoundLevel* \[out\]

A pointer to the level identifier for the matching hash identification rule.

*pdwSaferFlags*

Reserved. Set this value to zero.

## Return value

**TRUE** if the function is successful; otherwise, **FALSE**.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| DLL<br> | Advapi32.dll |

