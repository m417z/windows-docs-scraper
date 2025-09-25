# IWSDInboundAttachment::Read

## Description

Retrieves attachment data from a message sent by a remote host.

## Parameters

### `pBuffer` [out]

Pointer to a buffer receiving the data read from the attachment stream. The application program is responsible for allocating and freeing this data buffer.

### `dwBytesToRead` [in]

Size of the *pBuffer* input buffer, in bytes.

### `pdwNumberOfBytesRead` [out]

Pointer to a **DWORD** containing the number of bytes of data read from the attachment stream into the *pBuffer* input buffer.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **S_FALSE** | The end of the attachment stream has been reached. |
| **E_INVALIDARG** | *pBuffer* is **NULL**. |
| **E_POINTER** | *pdwNumberofBytesRead* is **NULL**. |

## Remarks

The **Read** method allows an application to receive arbitrary data from a remote host in a MIME-encapsulated message attachment. WSDAPI will provide an object implementing this interface when an attachment stream is received as part of a message. The call to **Read** opens the inbound attachment stream and transfers the attachment data to the application's buffer. If **Read** returns S_OK or S_FALSE, *pdwNumberofBytesRead* is set to the number of bytes read, which may be less than the size of the buffer. The **Read** call may block on network traffic.

## See also

[IWSDInboundAttachment](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nn-wsdattachment-iwsdinboundattachment)