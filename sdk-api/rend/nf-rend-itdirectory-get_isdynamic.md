# ITDirectory::get_IsDynamic

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**get_IsDynamic** method gets an indicator of whether the object on the server needs to be refreshed.

## Parameters

### `pfDynamic` [out]

Pointer to a Boolean **VARIANT**; VARIANT_TRUE if server needs to be refreshed and VARIANT_FALSE if it does not.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pfDynamic* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_FAIL** | Unspecified error. |
| **E_NOTIMPL** | This method is not yet implemented. |

## See also

[ITDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectory)