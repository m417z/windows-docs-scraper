# ICEnroll2::addNameValuePairToSignature

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **addNameValuePairToSignature** method
adds the authenticated name-value pair of an [attribute](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) to the request. It is up to the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) to interpret the meaning of the name-value pair.
This method was first defined in the [ICEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll2) interface.

## Parameters

### `Name` [in]

The name of the attribute, such as "2.5.4.6" for the country/region name.

### `Value` [in]

The value of the attribute, such as "US".

## Return value

### VB

The return value is an **HRESULT**, with **S_OK** returned if the call is successful.

## Remarks

The **addNameValuePairToSignature** method is used to add attributes to the request.

#### Examples

```cpp
BSTR bstrName = NULL;
BSTR bstrValue = NULL;
HRESULT hr;

// Allocate the name. Alternatively, (L"2.5.4.6").
bstrName = SysAllocString(TEXT(szOID_COUNTRY_NAME));
// Allocate the value.
bstrValue = SysAllocString(L"US");

if (NULL == bstrName || NULL == bstrValue)
{
    // handle error
}

// add the name-value pair to the signature
// pEnroll is previously instantiated ICEnroll4 interface pointer
hr = pEnroll->addNameValuePairToSignature( bstrName, bstrValue );
if ( FAILED( hr ) )
    printf("Failed addNameValuePairToSignature - %x\n", hr );
else
    printf("addNameValuePairToSignature(%ws, %ws) succeeded\n",
            bstrName,
            bstrValue );

// free BSTRs
if (bstrName )
    SysFreeString( bstrName );
if (bstrValue )
    SysFreeString( bstrValue );
```