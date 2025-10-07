# SystemPrng function

\[**SystemPrng** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [**BCryptGenRandom**](https://learn.microsoft.com/windows/desktop/api/Bcrypt/nf-bcrypt-bcryptgenrandom).\]

The **SystemPrng** function retrieves a specified number of random bytes from the system random number generator.

> [!NOTE]
> This function has no associated header file or import library. To call this function, you must create a user-defined header file.

## Parameters

*pbRandomData* \[out\]

A pointer to a buffer that receives the retrieved bytes.

*cbRandomData* \[in\]

The number of bytes to retrieve.

## Return value

Always returns **TRUE**.

## Requirements

| Requirement | Value |
|--------|--------|
| Minimum supported client | Windows Vista with SP1 \[desktop apps only\] |
| Minimum supported server | Windows Server 2008 \[desktop apps only\] |
| DLL | `Ksecdd.sys` on Windows Server 2008 and Windows Vista with SP1<br>`Cng.sys` on Windows 7 and Windows Server 2008 R2 |