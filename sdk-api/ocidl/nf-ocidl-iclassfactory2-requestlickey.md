# IClassFactory2::RequestLicKey

## Description

Creates a license key that the caller can save and use later to create an instance of the licensed object.

## Parameters

### `dwReserved` [in]

This parameter is reserved and must be zero.

### `pBstrKey` [out]

A pointer to the caller-allocated variable that receives the callee-allocated license key on successful return from this method. This parameter is set to **NULL** on any failure.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The license key was successfully created. |
| **E_NOTIMPL** | This class factory does not support run-time license keys. |
| **E_POINTER** | The address passed in *pbstrKey* is not valid. For example, it may be **NULL**. |
| **CLASS_E_NOTLICENSED** | This class factory supports run-time licensing, but the current machine itself is not licensed. Thus, a run-time key is not available on this machine. |

## Remarks

The caller can save the license key for subsequent calls to [IClassFactory2::CreateInstanceLic](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iclassfactory2-createinstancelic) to create objects on an otherwise unlicensed machine.

### Notes to Callers

The caller must free the **BSTR** with the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function when the key is no longer needed. The value of *fRuntimeKeyAvail* is returned through a previous call to [IClassFactory2::GetLicInfo](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iclassfactory2-getlicinfo).

### Notes to Implementers

This method allocates the **BSTR** key with [SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) or [SysAllocStringLen](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstringlen), and the caller becomes responsible for this **BSTR** after this method returns successfully.

This method need not be implemented when a class factory does not support run-time license keys.

## See also

[IClassFactory2](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iclassfactory2)