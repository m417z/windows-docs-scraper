# ICEnroll::put_ProviderName

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **ProviderName** property sets or retrieves the name of the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) to use.

If the CSP has not been specified, the default value for this property is "Microsoft Base Cryptographic Provider", and the **ProviderName** property is set to an empty string. This property was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This property is read/write.

## Parameters

## Remarks

The **ProviderName** property affects the behavior of the following methods:

* [createPKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createpkcs10)
* [createFilePKCS10](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-createfilepkcs10)
* [enumContainers](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-enumcontainers)

#### Examples

```cpp
BSTR     bstrProvName = NULL;
BSTR     bstrMyProvName = NULL;
HRESULT  hr;

// pEnroll is previously instantiated ICEnroll interface pointer

// get the ProviderName
hr = pEnroll->get_ProviderName( &bstrProvName );
if (FAILED( hr ))
    printf("Failed get_ProviderName - %x\n", hr );
else
    printf( "ProviderName: %ws\n", bstrProvName );
// free BSTR when done
if ( NULL != bstrProvName )
    SysFreeString( bstrProvName );

// set the ProviderName value
bstrMyProvName = SysAllocString(TEXT("Microsoft Base DSS")
                                TEXT(" Cryptographic Provider"));
hr = pEnroll->put_ProviderName( bstrMyProvName );
if (FAILED( hr ))
    printf("Failed put_ProviderName - %x\n", hr );
else
    printf( "ProviderName set to %ws\n", bstrMyProvName );
// free BSTR when done
if ( NULL != bstrMyProvName )
    SysFreeString( bstrMyProvName );
```