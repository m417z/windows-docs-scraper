# ICEnroll::put_SPCFileName

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **SPCFileName** property sets or retrieves the name of the file to which to write the base64-encoded PKCS #7 (in **BSTR** form) as returned from the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

This property was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

This property is read/write.

## Parameters

## Remarks

The file is written as a binary PKCS #7. Specifying this file does not affect the acceptance of the certificates into any of the user's stores.

If the file already exists, the user is notified and prompted for permission to overwrite it.

**SPCFileName** affects the behavior of the following methods:

* [acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7)
* [acceptFilePKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptfilepkcs7)

#### Examples

```cpp
BSTR     bstrSPCFile = NULL;
BSTR     bstrNewSPCFile = NULL;
HRESULT  hr;

// pEnroll is previously instantiated ICEnroll interface pointer

// get the SPCFileName
hr = pEnroll->get_SPCFileName( &bstrSPCFile );
if (FAILED( hr ))
    printf("Failed get_SPCFileName - %x\n", hr );
else
    printf( "SPCFileName: %ws\n", bstrSPCFile );
// free BSTR when done
if ( NULL != bstrSPCFile )
    SysFreeString( bstrSPCFile );

// set the SPCFileName, for example, "MyFile.SPC".
bstrNewSPCFile = SysAllocString(TEXT("<FILENAMEHERE>"));

hr = pEnroll->put_SPCFileName( bstrNewSPCFile );
if (FAILED( hr ))
    printf("Failed put_SPCFileName - %x\n", hr );
else
    printf( "SPCFileName set to %ws\n", bstrNewSPCFile );
// free BSTR when done
if ( NULL != bstrNewSPCFile )
    SysFreeString( bstrNewSPCFile );
```