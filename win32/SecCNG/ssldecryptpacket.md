# SslDecryptPacket function

the **SslDecryptPacket** function decrypts a single [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) packet.

## Parameters

*hSslProvider* \[in\]

The handle of the SSL protocol provider instance.

*hKey* \[in, out\]

The handle to the key that is used to decrypt the packet.

*pbInput* \[in\]

A pointer to the buffer that contains the packet to be decrypted.

*cbInput* \[in\]

The length, in bytes, of the *pbInput* buffer.

*pbOutput* \[out\]

A pointer to a buffer to contain the decrypted packet.

*cbOutput* \[in\]

The length, bytes, of the *pbOutput* buffer.

*pcbResult* \[out\]

The number of bytes written to the *pbOutput* buffer.

*SequenceNumber* \[in\]

The sequence number that corresponds to this packet.

*dwFlags* \[in\]

This parameter is reserved for future use.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------|
| **NTE\_INVALID\_HANDLE**

0x80090026L | One of the provided handles is not valid.\ | ## Remarks The length of the packet can be zero, such as when a "HelloRequest" message is decrypted. ## Requirements | Requirement | Value | |-------------------------------------|------------------------------------------------------------------------------------------| | Minimum supported client\ | Windows Vista \[desktop apps only\]\ | | Minimum supported server\ | Windows Server 2008 \[desktop apps only\]\ | | Header\ | Sslprovider.h | | DLL\ | Ncrypt.dll |