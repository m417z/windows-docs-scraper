# IOleObject::GetUserClassID

## Description

Retrieves an object's class identifier, the CLSID corresponding to the string identifying the object to an end user.

## Parameters

### `pClsid` [out]

Pointer to the class identifier (CLSID) to be returned. An object's CLSID is the binary equivalent of the user-type name returned by [IOleObject::GetUserType](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getusertype).

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The operation failed. |

## Remarks

**IOleObject::GetUserClassID** returns the CLSID associated with the object in the registration database. Normally, this value is identical to the CLSID stored with the object, which is returned by [IPersist::GetClassID](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersist-getclassid). For linked objects, this is the CLSID of the last bound link source. If the object is running in an application different from the one in which it was created and for the purpose of being edited is emulating a class that the container application recognizes, the CLSID returned will be that of the class being emulated rather than that of the object's own class.

## See also

[GetConvertStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-getconvertstg)

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[IOleObject::GetUserType](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getusertype)

[IPersist::GetClassID](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersist-getclassid)

[OleDoAutoConvert](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oledoautoconvert)

[OleSetAutoConvert](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetautoconvert)

[SetConvertStg](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-setconvertstg)