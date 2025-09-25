# ICEnroll3::EnumAlgs

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **EnumAlgs** method retrieves the IDs of cryptographic algorithms in a given algorithm class that are supported by the current [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). This method was first defined in the [ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3) interface.

## Parameters

### `dwIndex` [in]

Specifies the ordinal position of the algorithm whose ID will be retrieved. Specify zero for the first algorithm.

### `algClass` [in]

A cryptographic algorithm class. The IDs returned by this method will be in the specified class. Specify one of the following:

* ALG_CLASS_HASH
* ALG_CLASS_KEY_EXCHANGE
* ALG_CLASS_MSG_ENCRYPT
* ALG_CLASS_DATA_ENCRYPT
* ALG_CLASS_SIGNATURE

### `pdwAlgID` [out]

A pointer to a variable to receive a cryptographic algorithm ID that is supported by the current CSP.

## Return value

### C++

The return value is an **HRESULT**. A value of S_OK indicates success. When there are no more algorithms to enumerate, the value ERROR_NO_MORE_ITEMS is returned.

### VB

A cryptographic algorithm ID which is supported by the current CSP. When there are no more algorithms to enumerate, the value ERROR_NO_MORE_ITEMS is returned.

## Remarks

For algorithm ID and class constants used by this method, see Wincrypt.h.

#### Examples

```cpp
#include <windows.h>
#include <stdio.h>
#include <Xenroll.h>

DWORD     dwAlgID;
DWORD     dwIndex;

BSTR      bstrAlgName = NULL;

HRESULT   hr, hr2;

// Loop through the AlgIDs.
dwIndex = 0;
while ( TRUE )
{
    // Enumerate the alg IDs for a specific class.
    hr = pEnroll->EnumAlgs(dwIndex, ALG_CLASS_SIGNATURE, &dwAlgID);
    if ( S_OK != hr )
    {
       break;
    }

    // Do something with the AlgID.
    // For example, retrieve the corresponding name.
    hr2 = pEnroll->GetAlgName( dwAlgID, &bstrAlgName);
    if ( FAILED( hr2 ) )
        printf("Failed GetAlgName [%x]\n", hr);
    else
        printf("AlgID: %d Name: %S\n", dwAlgID, bstrAlgName );

    // Reuse the BSTR variable in next iteration.
    if ( NULL != bstrAlgName )
    {
        SysFreeString( bstrAlgName );
        bstrAlgName = NULL;
    }

    // Increment the index.
    dwIndex++;
}

```

## See also

[CEnroll](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376007(v=vs.85))

[ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3)

[ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4)