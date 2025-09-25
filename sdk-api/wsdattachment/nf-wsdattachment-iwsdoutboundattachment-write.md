# IWSDOutboundAttachment::Write

## Description

Sends attachment data to the remote host using a MIME container.

## Parameters

### `pBuffer` [in]

Pointer to a buffer containing the output data. The application program is responsible for allocating and freeing this data buffer.

### `dwBytesToWrite` [in]

Number of bytes to send to the remote host from *pBuffer*.

### `pdwNumberOfBytesWritten` [out]

Pointer to a **DWORD** containing the number of bytes of data actually sent to the remote host.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *pdwNumberofBytesWritten* is **NULL**. |
| **E_INVALIDARG** | *pBuffer* is **NULL**. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_OPERATION)** | The outbound attachment interface has not been initialized. Call [WSDCreateOutboundAttachment](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nf-wsdattachment-wsdcreateoutboundattachment) to initialize the interface. |
| **STG_S_BLOCK** | Internal buffers were not available. The data was not accepted and queued for transmission. |

## Remarks

The **Write** method allows an application program to send arbitrary data to a remote host as a MIME-encapsulated message attachment. The first call to **Write** opens the outbound attachment stream and initiates transmission of the HTTP headers, envelope data, and the MIME-encoded application data. Subsequent calls to **Write** will send additional blocks of MIME-encoded application data until the application makes a call to [Close](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nf-wsdattachment-iwsdoutboundattachment-close), which closes the attachment stream and finishes the transmission of the message envelope data and headers.

 The **Write** operation may block under several conditions. On the initial operation, **Write** will block until the HTTP headers and XML content have been transmitted. When sending multiple attachments in a single message, the first call to **Write** on any attachment may block until any prior attachment streams have been completely transmitted.
**Write** may block for up to 30 seconds (per HTTP transmission timeouts) if the remote host does not reply.

If an error occurs in establishing a connection or transmitting headers, **Write** will return the error code immediately. If a data transfer error occurs, the error may be delayed to a future call of **Write** or [Close](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nf-wsdattachment-iwsdoutboundattachment-close).

 The **Write** method may return successfully after a failed **Write** attempt that returned **STG_S_BLOCK**. A subsequent success indicates that the internal buffers were freed for use after the initial failed attempt. When **STG_S_BLOCK** is received by an application, the application can either resend the same data using the **Write** method or terminate the data transfer using the [Abort](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nf-wsdattachment-iwsdoutboundattachment-abort) method.

## See also

[IWSDInboundAttachment](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nn-wsdattachment-iwsdinboundattachment)

[IWSDOutboundAttachment](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nn-wsdattachment-iwsdoutboundattachment)

[IWSDOutboundAttachment::Abort](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nf-wsdattachment-iwsdoutboundattachment-abort)

[IWSDOutboundAttachment::Close](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nf-wsdattachment-iwsdoutboundattachment-close)