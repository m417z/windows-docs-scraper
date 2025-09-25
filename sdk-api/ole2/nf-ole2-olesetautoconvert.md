# OleSetAutoConvert function

## Description

Specifies a CLSID for automatic conversion to a different class when an object of that class is loaded.

## Parameters

### `clsidOld` [in]

The CLSID of the object class to be converted.

### `clsidNew` [in]

The CLSID of the object class that should replace *clsidOld*. This new CLSID replaces any existing auto-conversion information in the registry for *clsidOld*. If this value is CLSID_NULL, any existing auto-conversion information for *clsidOld* is removed from the registry.

## Return value

This function can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The object was tagged successfully. |
| **REGDB_E_CLASSNOTREG** | The CLSID is not properly registered in the registry. |
| **REGDB_E_READREGDB** | Error reading from the registry. |
| **REGDB_E_WRITEREGDB** | Error writing to the registry. |
| **REGDB_E_KEYMISSING** | Cannot read a key from the registry. |

## Remarks

**OleSetAutoConvert** goes to the system registry, finds the **[AutoConvertTo](https://learn.microsoft.com/windows/desktop/com/autoconvertto)** subkey under the CLSID specified by *clsidOld*, and sets it to *clsidNew*. This function does not validate whether an appropriate registry entry for *clsidNew* currently exists. These entries appear in the registry as subkeys of the CLSID key.

Object conversion means that the object's data is permanently associated with a new CLSID. Automatic conversion is typically specified in the setup program of a new version of an object application, so objects created by its older versions can be automatically updated to the new version.

For example, it may be necessary to convert spreadsheets that were created with earlier versions of a spreadsheet application to the new version. The spreadsheet objects from earlier versions have different CLSIDs than the new version. For each earlier version that you want automatically updated, you would call **OleSetAutoConvert** in the setup program, specifying the CLSID of the old version, and that of the new one. Then, whenever a user loads an object from a previous version, it would be automatically updated. To support automatic conversion of objects, a server that supports conversion must be prepared to manually convert objects that have the format of an earlier version of the server. Automatic conversion relies internally on this manual-conversion support.

Before setting the desired **AutoConvertTo** value, setup programs should also call **OleSetAutoConvert** to remove any existing conversion for the new class, by specifying the new class as the *clsidOld* parameter, and setting the *clsidNew* parameter to CLSID_NULL.

## See also

[AutoConvertTo](https://learn.microsoft.com/windows/desktop/com/autoconvertto)

[OleDoAutoConvert](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oledoautoconvert)

[OleGetAutoConvert](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olegetautoconvert)