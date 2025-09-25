# OleDoAutoConvert function

## Description

Automatically converts an object to a new class if automatic conversion for that object class is set in the registry.

## Parameters

### `pStg` [in]

A pointer to the [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface on the storage object to be converted.

### `pClsidNew` [out]

A pointer to the new CLSID for the object being converted. If there was no automatic conversion, this may be the same as the original class.

## Return value

This function can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | No conversion is needed or a conversion was successfully completed. |
| **REGDB_E_KEYMISSING** | The function cannot read a key from the registry. |

This function can also return any of the error values returned by the [OleGetAutoConvert](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olegetautoconvert) function. When accessing storage and stream objects, see the [IStorage::OpenStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-openstorage) and [IStorage::OpenStream](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-openstream) methods for possible errors. When it is not possible to determine the existing CLSID or when it is not possible to update the storage object with new information, see the [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface for other error return values.

## Remarks

**OleDoAutoConvert** automatically converts an object if automatic conversion has previously been specified in the registry by the [OleSetAutoConvert](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetautoconvert) function. Object conversion means that the object is permanently associated with a new CLSID. Automatic conversion is typically specified by the setup program for a new version of an object application, so that objects created by its older versions can be automatically updated.

The storage object must be in the unloaded state when **OleDoAutoConvert** is called.

A container application that supports object conversion should call **OleDoAutoConvert** each time it loads an object. If the container uses the [OleLoad](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleload) helper function, it need not call **OleDoAutoConvert** explicitly because **OleLoad** calls it internally.

**OleDoAutoConvert** first determines whether any conversion is required by calling the [OleGetAutoConvert](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olegetautoconvert) function, which, if no conversion is required, returns S_OK. If the object requires conversion, **OleDoAutoConvert** modifies and converts the storage object by activating the new object application. The new object application reads the existing data format, but saves the object in the new native format for the object application.

If the object to be automatically converted is an OLE 1 object, the ItemName string is stored in a stream called "\1Ole10ItemName." If this stream does not exist, the object's item name is **NULL**.

## See also

[OleGetAutoConvert](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olegetautoconvert)

[OleSetAutoConvert](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetautoconvert)