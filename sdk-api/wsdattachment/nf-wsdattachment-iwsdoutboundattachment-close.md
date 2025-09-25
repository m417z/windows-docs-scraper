# IWSDOutboundAttachment::Close

## Description

Closes the current attachment MIME data stream.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. All data in the attachment stream was successfully transferred. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_OPERATION)** | [Close](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nf-wsdattachment-iwsdoutboundattachment-close) was called before [Write](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nf-wsdattachment-iwsdoutboundattachment-write) was called. You must call **Write** before closing the attachment stream. |
| **STG_S_BLOCK** | Internal buffers were not available. The data in the attachment stream was not successfully transferred. |

## Remarks

**Close** is used to indicate that the application has no more data to transmit in the current attachment stream. The return value can indicate an error in a previous Write operation or an issue closing the connection.

**Close** may block while waiting for a previous [Write](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nf-wsdattachment-iwsdoutboundattachment-write) operation to complete.
**Close** may block for up to 30 seconds (per HTTP transmission timeouts) while waiting for a previous **Write** operation to complete.

 The **Close** method may return successfully after a failed **Close** attempt that returned **STG_S_BLOCK**. A subsequent success indicates that the internal buffers were freed for use after the initial failed attempt. When **STG_S_BLOCK** is received by an application, the application can either call **Close** again or terminate the data transfer using the [Abort](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nf-wsdattachment-iwsdoutboundattachment-abort) method.

## See also

[IWSDInboundAttachment](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nn-wsdattachment-iwsdinboundattachment)

[IWSDOutboundAttachment](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nn-wsdattachment-iwsdoutboundattachment)

[IWSDOutboundAttachment::Abort](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nf-wsdattachment-iwsdoutboundattachment-abort)

[IWSDOutboundAttachment::Write](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nf-wsdattachment-iwsdoutboundattachment-write)