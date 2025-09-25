# RtlGenRandom function

## Description

[The **RtlGenRandom** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [CryptGenRandom](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptgenrandom) function.]

The **RtlGenRandom** function generates a pseudo-random number.

**Note** This function has no associated import library. This function is available as a resource named **SystemFunction036** in Advapi32.dll. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Advapi32.dll.

## Parameters

### `RandomBuffer` [out]

A pointer to a buffer that receives the random number as binary data. The size of this buffer is specified by the *RandomBufferLength* parameter.

### `RandomBufferLength` [in]

The length, in bytes, of the *RandomBuffer* buffer.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**.

## Remarks

When you have finished using the random number, free the *RandomBuffer* buffer by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function.