# IWSDOutboundAttachment::Abort

## Description

Aborts the transfer of data on the attachment MIME data stream. When **Abort** is called, any pending data may be discarded.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_OPERATION)** | [Abort](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nf-wsdattachment-iwsdoutboundattachment-abort) was called before [Write](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nf-wsdattachment-iwsdoutboundattachment-write) was called. You must call **Write** before terminating the attachment stream. |

## Remarks

The **Abort** method may be called when a [Close](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nf-wsdattachment-iwsdoutboundattachment-close) or [Write](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nf-wsdattachment-iwsdoutboundattachment-write) method call failed with the error **STG_S_BLOCK**.

[Close](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nf-wsdattachment-iwsdoutboundattachment-close) must not be called once **Abort** has been called on an attachment stream.

## See also

[IWSDOutboundAttachment](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nn-wsdattachment-iwsdoutboundattachment)

[IWSDOutboundAttachment::Close](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nf-wsdattachment-iwsdoutboundattachment-close)

[IWSDOutboundAttachment::Write](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nf-wsdattachment-iwsdoutboundattachment-write)