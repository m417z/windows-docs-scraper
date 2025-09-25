# SetConvertStg function

## Description

The
**SetConvertStg** function sets the convert bit in a storage object to indicate that the object is to be converted to a new class when it is opened. The setting can be retrieved with a call to the
[GetConvertStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-getconvertstg) function.

## Parameters

### `pStg`

[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer to the storage object in which to set the conversion bit.

### `fConvert`

If **TRUE**, sets the conversion bit for the object to indicate the object is to be converted when opened. If **FALSE**, clears the conversion bit.

## Return value

See the
[IStorage::CreateStream](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-createstream),
[IStorage::OpenStream](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-openstream),
[ISequentialStream::Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read), and
[ISequentialStream::Write](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-write) methods for possible storage and stream access errors.

## Remarks

The
**SetConvertStg** function determines the status of the convert bit in a contained object. It is called by both the container application and the server in the process of converting an object from one class to another. When a user specifies through a **Convert To** dialog (which the container produces with a call to the
[OleUIConvert](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuiconverta) function) that an object is to be converted, the container must take the following steps:

1. Unload the object if it is currently loaded.
2. Call
   [WriteClassStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-writeclassstg) to write the new CLSID to the object storage.
3. Call
   [WriteFmtUserTypeStg](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-writefmtusertypestg) to write the new user-type name and the existing main format to the storage.
4. Call
   **SetConvertStg** with the *fConvert* parameter set to **TRUE** to indicate that the object has been tagged for conversion to a new class the next time it is loaded.
5. Just before the object is loaded, call
   [OleDoAutoConvert](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oledoautoconvert) to handle any needed object conversion, unless you call
   [OleLoad](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleload), which calls it internally.

When an object is initialized from a storage object and the server is the destination of a convert-to operation, the object server should do the following:

1. Call the
   [GetConvertStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-getconvertstg) function to retrieve the value of the conversion bit.
2. If the bit is set, the server reads the data out of the object according to the format associated with the new CLSID.
3. When the object is asked to save itself, the object should call the
   [WriteFmtUserTypeStg](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-writefmtusertypestg) function using the normal native format and user type of the object.
4. The object should then call
   **SetConvertStg** with the *fConvert* parameter set to **FALSE** to reset the object's conversion bit.

## See also

[GetConvertStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-getconvertstg)