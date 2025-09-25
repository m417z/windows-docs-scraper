# IMcastScope::get_ScopeDescription

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**get_ScopeDescription** method obtains a textual description associated with this scope. The description is used only for clarifying the purpose or meaning of a scope and is not needed for any subsequent calls.

## Parameters

### `ppDescription` [out]

Pointer to a **BSTR** that will receive a description of this scope. The description was established when this scope was configured on the multicast server.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The caller passed in an invalid pointer argument. |
| **E_OUTOFMEMORY** | Not enough memory exists to allocate the string. |

## Remarks

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *ppDescription* parameter.

## See also

[IMcastScope](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastscope)