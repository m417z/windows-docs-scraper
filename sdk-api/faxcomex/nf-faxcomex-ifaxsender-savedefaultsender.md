# IFaxSender::SaveDefaultSender

## Description

The **IFaxSender::SaveDefaultSender** method stores information about the default sender from the [FaxSender](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsender) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To load the default sender information into a [FaxSender](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsender) object, use the [IFaxSender::get_LoadDefaultSender](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsender-loaddefaultsender-vb) method.

This method can return remote procedure call (RPC) return values. For more information, see [RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## See also

[FaxSender](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsender)

[IFaxSender](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxsender)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-sending-a-fax)