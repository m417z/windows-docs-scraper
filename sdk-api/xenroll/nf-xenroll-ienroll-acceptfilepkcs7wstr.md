# IEnroll::acceptFilePKCS7WStr

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **acceptFilePKCS7WStr** method accepts and processes a PKCS #7 message containing a certificate, then stores the message to a file. This method was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

## Parameters

### `wszPKCS7FileName` [in]

Specifies the name of the file containing the PKCS #7.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. Upon successful completion of this function, the PKCS #7 in the file will be accepted.

## Remarks

By default, the MY, CA, ROOT, and REQUEST system stores are used to store the certificates. However, you can specify other stores by assigning the following properties before calling this method:

* [MyStoreNameWStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-get_mystorenamewstr)
* [CAStoreNameWStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-get_castorenamewstr)
* [RootStoreNameWStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-get_rootstorenamewstr)
* [RequestStoreNameWStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-get_requeststorenamewstr)

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)