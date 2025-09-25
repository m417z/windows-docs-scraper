# IFaxIncomingQueue::Refresh

## Description

The **Refresh** method refreshes [FaxIncomingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingqueue) object information from the fax server. When the **Refresh** method is called, any configuration changes made after the last [Save](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingqueue-save-vb) method call are lost.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxIncomingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingqueue)

[IFaxIncomingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingqueue)