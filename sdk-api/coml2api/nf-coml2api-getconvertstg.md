# GetConvertStg function

## Description

The
**GetConvertStg** function returns the current value of the convert bit for the specified storage object.

## Parameters

### `pStg` [in]

[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer to the storage object from which the convert bit is to be retrieved.

## Return value

[IStorage::OpenStream](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-openstream),
[IStorage::OpenStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-openstorage), and
[ISequentialStream::Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read) storage and stream access errors.

## Remarks

The
**GetConvertStg** function is called by object servers that support the conversion of an object from one format to another. The server must be able to read the storage object using the format of its previous class identifier (CLSID) and write the object using the format of its new CLSID to support the object's conversion. For example, a spreadsheet created by one application can be converted to the format used by a different application.

The convert bit is set by a call to the
[SetConvertStg](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-setconvertstg) function. A container application can call this function on the request of an end user, or a setup program can call it when installing a new version of an application. An end user requests converting an object through the **Convert To** dialog box. When an object is converted, the new CLSID is permanently assigned to the object, so the object is subsequently associated with the new CLSID.

Then, when the object is activated, its server calls the
**GetConvertStg** function to retrieve the value of the convert bit from the storage object. If the bit is set, the object's CLSID has been changed, and the server must read the old format and write the new format for the storage object.

After retrieving the bit value, the object application should clear the convert bit by calling the
[SetConvertStg](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-setconvertstg) function with its *fConvert* parameter set to **FALSE**.

## See also

[SetConvertStg](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-setconvertstg)