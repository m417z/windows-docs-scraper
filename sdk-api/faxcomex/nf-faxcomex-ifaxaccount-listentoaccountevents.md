# IFaxAccount::ListenToAccountEvents

## Description

Sets the flags of a [FAX_ACCOUNT_EVENTS_TYPE_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_account_events_type_enum) variable that represents the events for which the account is listening.

## Parameters

### `EventTypes` [in]

Type: **[FAX_ACCOUNT_EVENTS_TYPE_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_account_events_type_enum)**

A variable that specifies the types of events for which the account is listening.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[FaxAccount](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccount)

[IFaxAccount](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccount)