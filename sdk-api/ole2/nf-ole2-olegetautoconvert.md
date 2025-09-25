# OleGetAutoConvert function

## Description

Determines whether the registry is set for objects of a specified CLSID to be automatically converted to another CLSID, and if so, retrieves the new CLSID.

## Parameters

### `clsidOld` [in]

The CLSID for the object.

### `pClsidNew` [out]

A pointer to a variable to receive the new CLSID, if any. If auto-conversion for *clsidOld* is not set in the registry, *clsidOld* is returned. The *pClsidNew* parameter is never **NULL**.

## Return value

This function can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | A value was successfully returned through the *pclsidNew* parameter. |
| **REGDB_E_CLASSNOTREG** | The CLSID is not properly registered in the registry. |
| **REGDB_E_READREGDB** | Error reading from the registry. |
| **REGDB_E_KEYMISSING** | Auto-convert is not active or there was no registry entry for the *clsidOld* parameter. |

## Remarks

**OleGetAutoConvert** returns the **[AutoConvertTo](https://learn.microsoft.com/windows/desktop/com/autoconvertto)** entry in the registry for the specified object. The **AutoConvertTo** subkey specifies whether objects of a given CLSID are to be automatically converted to a new CLSID. This is usually used to convert files created by older versions of an application to the current version. If there is no **AutoConvertTo** entry, this function returns the value of *clsidOld*.

The [OleDoAutoConvert](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oledoautoconvert) function calls **OleGetAutoConvert** to determine whether the object specified is to be converted. A container application that supports object conversion should call **OleDoAutoConvert** each time it loads an object. If the container uses the [OleLoad](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleload) helper function, it need not call **OleDoAutoConvert** explicitly because **OleLoad** calls it internally.

To set up automatic conversion of a given class, you can call the [OleSetAutoConvert](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetautoconvert) function (typically in the setup program of an application installation). This function uses the **AutoConvertTo** subkey to tag a class of objects for automatic conversion to a different class of objects. This is a subkey of the CLSID key.

## See also

[AutoConvertTo](https://learn.microsoft.com/windows/desktop/com/autoconvertto)

[OleDoAutoConvert](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oledoautoconvert)

[OleSetAutoConvert](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetautoconvert)