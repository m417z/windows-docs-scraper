# SslComputeEapKeyBlock function

The **SslComputeEapKeyBlock** function computes the key block used by the Extensible Authentication Protocol (EAP).

## Parameters

*hSslProvider* \[in\]

The handle of the [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) protocol provider instance.

*hMasterKey* \[in\]

The handle of the [*master key*](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) object.

*pbRandoms* \[in\]

A pointer to a buffer that contains a concatenation of the client\_random and server\_random values of the SSL session.

*cbRandoms* \[in\]

The length, in bytes, of the *pbRandoms* buffer.

*pbOutput* \[out, optional\]

The address of a buffer that receives the key BLOB. The *cbOutput* parameter contains the size of this buffer. If this parameter is **NULL**, this function will place the required size, in bytes, in the **DWORD** pointed to by the *pcbResult* parameter.

*cbOutput* \[in\]

The length, in bytes, of the *pbOutput* buffer.

*pcbResult* \[out\]

A pointer to a **DWORD** value that specifies the length, in bytes, of the hash written to the *pbOutput* buffer.

*dwFlags* \[in\]

Set to **NCRYPT\_SSL\_SERVER\_FLAG** to indicate that this is a server call.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

| Return code/value | Description |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------|
| **NTE\_INVALID\_HANDLE**

0x80090026L | One of the supplied handles is not valid.\ | ## Requirements | Requirement | Value | |-------------------------------------|------------------------------------------------------------------------------------------| | Minimum supported client\ | Windows Vista \[desktop apps only\]\ | | Minimum supported server\ | Windows Server 2008 \[desktop apps only\]\ | | Header\ | Sslprovider.h | | DLL\ | Ncrypt.dll |