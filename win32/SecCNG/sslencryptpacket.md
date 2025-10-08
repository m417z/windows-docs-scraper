# SslEncryptPacket function

The **SslEncryptPacket** function encrypts a single [*Secure Sockets Layer protocol*](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL) packet.

## Parameters

*hSslProvider* \[in\]

The handle of the SSL protocol provider instance.

*hKey* \[in, out\]

The handle to the key that is used to encrypt the packet.

*pbInput* \[in\]

A pointer to the buffer that contains the packet to be encrypted.

*cbInput* \[in\]

The length, in bytes, of the *pbInput* buffer.

*pbOutput* \[out\]

A pointer to a buffer to receive the encrypted packet.

*cbOutput* \[in\]

The length, bytes, of the *pbOutput* buffer.

*pcbResult* \[out\]

The number of bytes written to the *pbOutput* buffer.

*SequenceNumber* \[in\]

The sequence number that corresponds to this packet.

*dwContentType* \[in\]

The content type that corresponds to this packet, which specifies the higher level protocol used to process the enclosed packet.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------|
| **CT\_CHANGE\_CIPHER\_SPEC**<br>20 | Indicates a change in the ciphering strategy.<br> |
| **CT\_ALERT**<br>21 | Indicates that the enclosed packet contains an alert.<br> |
| **CT\_HANDSHAKE**<br>22 | Indicates that the enclosed packet is part of the handshake protocol.<br> |
| **CT\_APPLICATIONDATA**<br>23 | Indicates that the packet contains application data.<br> |

*dwFlags* \[in\]

This parameter is reserved for future use.

## Return value

If the function succeeds, it returns zero.

If the function fails, it returns a nonzero error value.

Possible return codes include, but are not limited to, the following.

| Return code/value | Description |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------|
| **NTE\_INVALID\_HANDLE**<br>0x80090026L | One of the provided handles is not valid.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Sslprovider.h |
| DLL<br> | Ncrypt.dll |

