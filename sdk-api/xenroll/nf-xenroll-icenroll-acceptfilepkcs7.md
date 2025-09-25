# ICEnroll::acceptFilePKCS7

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **acceptFilePKCS7** method accepts and processes a file that contains a PKCS #7 message containing a certificate. This method was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

## Parameters

### `wszPKCS7FileName` [in]

Specifies the name of the file that contains the PKCS #7 message.

## Return value

### VB

The return value is an **HRESULT**. A value of S_OK indicates success. Upon successful completion of this function, the PKCS #7 message in the file will be accepted.

## Remarks

By default, the My, Ca, Root, and Request system stores are used to store the certificates. However, you can specify other stores by assigning the following properties before calling this method:

* [MyStoreName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_mystorename)
* [CAStoreName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_castorename)
* [RootStoreName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_rootstorename)
* [RequestStoreName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_requeststorename)

The **acceptFilePKCS7** method differs from
[acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7) only in that a file supplies the certificate.

#### Examples

```cpp
HRESULT  hr;
BSTR     bstrFileName;

// Allocate a BSTR referencing an existing file,
// for example, "myPKCS7.fil".
bstrFileName = SysAllocString(TEXT("<FILENAMEHERE>"));
if (NULL == bstrFileName)
{
    //handle error
}

// pEnroll is a previously instantiated ICEnroll interface pointer.
hr = pEnroll->acceptFilePKCS7( bstrFileName );
if (FAILED(hr))
    printf("Failed acceptFilePKCS7 - %x\n", hr );
else
	printf("Accepted PKCS #7 from file %ws successfully\n",
	bstrFileName );

// Free BSTR when done.
if (bstrFileName)
    SysFreeString(bstrFileName);
```

## See also

[CAStoreName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_castorename)

[CEnroll](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376007(v=vs.85))

[ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll)

[ICEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll2)

[ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3)

[ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4)

[MyStoreName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_mystorename)

[RequestStoreName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_requeststorename)

[RootStoreName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_rootstorename)

[acceptPKCS7](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-acceptpkcs7)