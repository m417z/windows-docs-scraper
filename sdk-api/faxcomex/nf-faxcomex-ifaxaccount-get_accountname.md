# IFaxAccount::get_AccountName

## Description

Retrieves the name of a particular fax account on the server.

This property is read-only.

## Parameters

## Remarks

If the account is not in the local domain, the format of name returned is \<domain_name>\<user_name>.

If the account is in the domain but not on the server, the format name returned is \<computer_name>\<user_name> where \<computer_name> is the name of the server that holds the account.

If the account is on the same server as the fax server, just the \<user_name> of the account is returned.

## See also

[FaxAccount](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccount)

[IFaxAccount](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccount)