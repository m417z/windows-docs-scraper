# SslGenerateSessionKeys function

The **SslGenerateSessionKeys** function generates a set of [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) session keys.

## Parameters

*hSslProvider* \[in\]

The handle to the SSL protocol provider instance.

*hMasterKey* \[in\]

The handle to the [*master key*](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) object.

*phReadKey* \[out\]

A pointer to the returned read key handle.

*phWriteKey* \[out\]

A pointer to the returned write key handle.

*pParameterList* \[in\]

A pointer to an array of **NCryptBuffer** buffers that contain information used as part of the key exchange operation. The precise set of buffers is dependent on the protocol and cipher suite that is used. At the minimum, the list will contain buffers that contain the client and server supplied random values.

*dwFlags* \[in\]

This parameter is reserved for future use.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------|
| **NTE\_NO\_MEMORY**<br>0x8009000EL | Not enough memory is available to allocate necessary buffers.<br> |
| **NTE\_INVALID\_HANDLE**<br>0x80090026L | One of the provided handles is not valid.<br> |
| **NTE\_INVALID\_PARAMETER**<br>0x80090027L | The *phReadKey* or *phWriteKey* parameter is null.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Sslprovider.h |
| DLL<br> | Ncrypt.dll |

