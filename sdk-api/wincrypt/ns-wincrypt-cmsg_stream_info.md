# CMSG_STREAM_INFO structure

## Description

The **CMSG_STREAM_INFO** structure is used to enable stream processing of data rather than single block processing. Stream processing is most often used when processing large messages. Stream-processed messages can originate from any serialized source such as a file on a hard disk, a server, or a CD ROM.

This structure is passed to
the [CryptMsgOpenToEncode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentoencode) and
[CryptMsgOpenToDecode](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgopentodecode) functions.

## Members

### `cbContent`

Specifies the size, in bytes, of the content. Normal [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoding is used unless **CMSG_INDEFINITE_LENGTH**(0xFFFFFFFF) is passed, indicating that the application is not specifying the content length. This forces the use of indefinite-length [Basic Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) (BER) encoding.

### `pfnStreamOutput`

The address of a callback function used to read from and write data to a disk when processing large messages.

The callback function must have the following signature and parameters:

```cpp
#include <windows.h>
#include <Wincrypt.h>

BOOL WINAPI CmsgStreamOutputCallback(
  IN const void *pvArg,  //in
  IN BYTE *pbData,       //in
  IN DWORD cbData,       //in
  IN BOOL fFinal         //in
);

```

| Value | Meaning |
| --- | --- |
| **pvArg** | The arguments specified by CMSG_STREAM_INFO. |
| **pbData** | A pointer to a block of processed data that is available to the application. |
| **cbData** | The size, in bytes, of the block of processed data at pbData. |
| **fFinal** | Specifies that the last block of data is being processed and that this is the last time the callback will be executed. |

### `pvArg`

A pointer to the argument to pass to the callback function. Typically, this is used for state data that includes the handle to a more deeply nested message (when decoding) or a less deeply nested message (when encoding).

## Remarks

Messages can be so large that processing them all at once by storing the whole message in memory can be difficult, if not impossible. It is possible to process large messages without encountering memory limitations by streaming the data that is to be processed into manageable sized blocks. The
[low-level message functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions) can be used with streaming to encode or decode a message. Any level of nesting of messages is supported when streaming to encode and streaming to decode.

The input message to be processed as a stream feeds into
[CryptMsgUpdate](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgupdate) one block at a time, with the application determining the size of the block. As the streamed message is processed for encoding or decoding, the resulting output data is passed back to the application through an application-specified callback function that is specified by the **pfnStreamOutput** member.

No assumptions can be made about the block size of the output data because the size can vary for several reasons, such as the jitter in output block size caused by the block size for the encryption algorithm when processing an enveloped message, or when blocks that contain the message header and the SignerInfo as defined by PKCS # 7 are processed.

The size of the output block is passed to the callback function in its *cbData* parameter. The use of output data is determined in the calling application. Typically, output from stream processing will not be persisted in memory as a whole due to memory limitations; rather, it will be serialized to a disk or server file.