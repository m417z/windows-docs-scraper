# ITRendezvous::CreateDirectory

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**CreateDirectory** method creates an ITDirectory object corresponding to a directory of the given type and name.

## Parameters

### `DirectoryType` [in]

The type of the directory. See
[DIRECTORY_TYPE](https://learn.microsoft.com/windows/desktop/api/rend/ne-rend-directory_type).

### `pName` [in]

Pointer to a **BSTR** containing the name of the directory to be created.

### `ppDir` [out]

Pointer to receive an
[ITDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectory) object of the type specified above.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pName* or *ppDir* parameter is an invalid pointer. |
| **E_INVALIDARG** | The *DirectoryType* parameter is not valid. |

## Remarks

For directories of type DT_NTDS, *pName* is ignored because Rendezvous supports using only the local domain controller (DC).

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pName* parameter and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

TAPI calls the **AddRef** method on the
[ITDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectory) interface returned by **ITRendezvous::CreateDirectory**. The application must call **Release** on the
**ITDirectory** interface to free resources associated with it.

This function may send data over the wire in unencrypted form; therefore, someone eavesdropping on the network may be able to read the data. The security risk of sending the data in clear text should be considered before using this method.

## See also

[DIRECTORY_TYPE](https://learn.microsoft.com/windows/desktop/api/rend/ne-rend-directory_type)

[ITDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectory)

[ITRendezvous](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itrendezvous)