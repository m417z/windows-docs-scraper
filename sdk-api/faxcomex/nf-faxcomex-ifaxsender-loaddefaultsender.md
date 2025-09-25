# IFaxSender::LoadDefaultSender

## Description

The **IFaxSender::get_LoadDefaultSender** method fills the [FaxSender](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsender) object with the default sender information.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The default sender information is saved using the [IFaxSender::SaveDefaultSender](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsender-savedefaultsender-vb) method.

This method can return remote procedure call (RPC) return values. For more information, see [RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## See also

[FaxSender](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxsender)

[IFaxSender](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxsender)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-broadcasting-a-fax)