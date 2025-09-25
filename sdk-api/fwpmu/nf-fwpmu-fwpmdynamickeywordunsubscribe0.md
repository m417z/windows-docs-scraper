## Description

Cancels the delivery of notifications regarding changes to particular dynamic keyword address ([FW_DYNAMIC_KEYWORD_ADDRESS0](https://learn.microsoft.com/windows/win32/api/netfw/ns-netfw-fw_dynamic_keyword_address0)) objects.

For more info, and code examples, see [Firewall dynamic keywords](https://learn.microsoft.com/windows/win32/ics/firewall-dynamic-keywords).

## Parameters

### `subscriptionHandle`

Type: \_In\_ **[HANDLE](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The subscription handle that was returned from [FwpmDynamicKeywordSubscribe0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmdynamickeywordsubscribe0).

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If the function succeeds, then it returns **ERROR_SUCCESS**.

## Remarks

**FwpmDynamicKeywordUnsubscribe0** waits for all callback functions to complete before returning.

## See also

* [Firewall dynamic keywords](https://learn.microsoft.com/windows/win32/ics/firewall-dynamic-keywords)
* [FW_DYNAMIC_KEYWORD_ADDRESS0](https://learn.microsoft.com/windows/win32/api/netfw/ns-netfw-fw_dynamic_keyword_address0)