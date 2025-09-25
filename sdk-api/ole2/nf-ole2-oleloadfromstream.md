# OleLoadFromStream function

## Description

Loads an object from the stream.

## Parameters

### `pStm` [in]

Pointer to the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface on the stream from which the object is to be loaded.

### `iidInterface` [in]

Interface identifier (IID) the caller wants to use to communicate with the object after it is loaded.

### `ppvObj` [out]

Address of pointer variable that receives the interface pointer requested in riid. Upon successful return, **ppvObj* contains the requested interface pointer on the newly loaded object.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory for the operation. |
| **E_NOINTERFACE** | The object does not support the specified interface. |

This function can also return any of the error values returned by the [ReadClassStm](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-readclassstm) and [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) functions, and the [IPersistStream::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststream-load) method.

## Remarks

**Important**

Security Note: Calling this method with untrusted data is a security risk. Call this method only with trusted data.

This function can be used to load an object that supports the [IPersistStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststream) interface. The CLSID of the object must immediately precede the object's data in the stream, which is accomplished by the companion function [OleSaveToStream](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olesavetostream) (or the operations it wraps, which are described under that topic).

If the CLSID for the stream is CLSID_NULL, the *ppvObj* parameter is set to **NULL**.

## See also

[OleSaveToStream](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olesavetostream)