# IFaxAccountIncomingQueue::GetJobs

## Description

Returns the collection of inbound fax jobs in the queue for the current fax account.

## Parameters

### `pFaxIncomingJobs` [out, retval]

Type: **[IFaxIncomingJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingjobs)****

A [FaxIncomingJobs](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingjobs) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [far2SUBMIT_LOW](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum_2) access rights.

If the setting "All incoming faxes are viewable by everyone" is true (see [IncomingFaxesArePublic](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxconfiguration-incomingfaxesarepublic-vb)) or if the current user has [far2MANAGE_RECEIVE_FOLDER](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum_2) access rights, then the set returned includes all the messages present in the fax server incoming queue.

## See also

[FaxAccountIncomingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingqueue)

[IFaxAccountIncomingQueue](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccountincomingqueue)