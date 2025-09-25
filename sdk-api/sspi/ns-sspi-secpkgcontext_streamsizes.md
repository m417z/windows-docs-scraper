# SecPkgContext_StreamSizes structure

## Description

The **SecPkgContext_StreamSizes** structure indicates the sizes of the various parts of a stream for use with the message support functions. The
[QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa) function uses this structure.

## Members

### `cbHeader`

Specifies the size, in bytes, of the header portion. If zero, no header is used.

### `cbTrailer`

Specifies the maximum size, in bytes, of the trailer portion. If zero, no trailer is used.

### `cbMaximumMessage`

Specifies the size, in bytes, of the largest message that can be encapsulated.

### `cBuffers`

Specifies the number of buffers to pass.

### `cbBlockSize`

Specifies the preferred integral size of the messages. For example, eight indicates that messages should be of size zero mod eight for optimal performance. Messages other than this block size can be padded.

## Remarks

Applications calling [EncryptMessage (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-encryptmessage) should check the values of the **cbHeader**, **cbTrailer**, and **cbMaximumMessage** members to determine the size of the encrypted packet.

## See also

[QueryContextAttributes (General)](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-querycontextattributesa)