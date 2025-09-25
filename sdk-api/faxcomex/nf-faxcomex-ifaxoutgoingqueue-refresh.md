# IFaxOutgoingQueue::Refresh

## Description

The **IFaxOutgoingQueue::Refresh** method refreshes [FaxOutgoingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingqueue) object information from the fax server. When the **IFaxOutgoingQueue::Refresh** method is called, any configuration changes made after the last [IFaxOutgoingQueue::Save](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingqueue-save-vb) method call are lost.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxOutgoingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingqueue)

[IFaxOutgoingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingqueue)

[Managing Outgoing Jobs](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-outgoing-jobs)