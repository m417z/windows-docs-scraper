# IWSDInboundAttachment::Close

## Description

Closes the current attachment MIME data stream.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |

## Remarks

This method can be used to terminate the transfer of an incoming attachment while the transfer is in progress.

Usually, **Close** must be called before calling **Release()** on the [IWSDInboundAttachment](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nn-wsdattachment-iwsdinboundattachment) interface. The only time a **Close** call is not required is when [Read](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nf-wsdattachment-iwsdinboundattachment-read) returns S_FALSE, which indicates that the end of the attachment stream has been reached. In that case, simply call **Release()** on the **IWSDInboundAttachment** interface.

## See also

[IWSDInboundAttachment](https://learn.microsoft.com/windows/desktop/api/wsdattachment/nn-wsdattachment-iwsdinboundattachment)