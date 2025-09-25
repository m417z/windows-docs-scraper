# ICEnroll3::GetAlgName

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **GetAlgName** method retrieves the name of a cryptographic algorithm given its ID. The values retrieved by this method depend on the current [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). This method was first defined in the [ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3) interface.

## Parameters

### `algID` [in]

A value that represents a cryptographic algorithm, as defined in Wincrypt.h. For example, CALG_MD2 is a defined algorithm identifier. For this method to be successful, the current CSP must support the *algID* algorithm.

### `pbstr` [out]

Upon success, a pointer to a **BSTR** that represents the name of the algorithm specified by *algID*. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

### C++

The return value is an **HRESULT**. A value of S_OK indicates success. If a CSP does not support this method or does not support the *algID* cryptographic algorithm, an error is returned.

### VB

The return value is a string that represents the name of the algorithm specified by *algID*. If a CSP does not support this method, an error is returned.

## Remarks

This method may be used to display the names of algorithms whose IDs are retrieved by calling
[EnumAlgs](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll3-enumalgs).

Constants for the cryptographic algorithms are defined in Wincrypt.h.

#### Examples

```cpp
BSTR      bstrAlgName = NULL;

HRESULT   hr;

// Retrieve the algorithm name.
// dwAlgID is a DWORD variable for an algorithm ID.
hr = pEnroll->GetAlgName( dwAlgID, &bstrAlgName);
if (FAILED(hr))
    printf("Failed GetAlgName [%x]\n", hr);
else
    printf("AlgID: %d Name: %S\n", dwAlgID, bstrAlgName );

// Free BSTR resource.
if ( NULL != bstrAlgName )
{
    SysFreeString( bstrAlgName );
    bstrAlgName = NULL;
}
```

## See also

[CEnroll](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376007(v=vs.85))

[EnumAlgs](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll3-enumalgs)

[ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3)

[ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4)