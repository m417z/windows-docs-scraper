# ITRequest::MakeCall

## Description

The
**MakeCall** method makes a call to the designated party.

## Parameters

### `pDestAddress` [in]

Pointer to a **BSTR** containing the destination address for the call.

### `pAppName` [in]

Pointer to a **BSTR** containing the name of the application.

### `pCalledParty` [in]

Pointer to a **BSTR** containing the called party name.

### `pComment` [in]

Pointer to a **BSTR** containing a comment.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPIERR_NOREQUESTRECIPIENT** | No application exists that can handle the assisted telephony request. |
| **TAPIERR_INVALDESTADDRESS** | The destination address is not valid. |
| **TAPIERR_REQUESTQUEUEFULL** | The TAPI Server request queue is full and cannot handle another assisted telephony request. |

## Remarks

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pDestAddress, pAppName, pCalledParty,* and *pComment* parameters. The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variables are no longer needed.

## See also

[ITRequest](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itrequest)