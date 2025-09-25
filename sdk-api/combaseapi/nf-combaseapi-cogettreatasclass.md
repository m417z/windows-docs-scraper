# CoGetTreatAsClass function

## Description

Returns the CLSID of an object that can emulate the specified object.

## Parameters

### `clsidOld` [in]

The CLSID of the object that can be emulated (treated as) an object with a different CLSID.

### `pClsidNew` [out]

A pointer to where the CLSID that can emulate *clsidOld* objects is retrieved. This parameter cannot be **NULL**. If there is no emulation information for *clsidOld* objects, the *clsidOld* parameter is supplied.

## Return value

This function can return the following values, as well as any error values returned by the [CLSIDFromString](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-clsidfromstring) function.

| Return code | Description |
| --- | --- |
| **S_OK** | A new CLSID was successfully returned. |
| **S_FALSE** | There is no emulation information for the *clsidOld* parameter, so the *pClsidNew* parameter is set to *clsidOld*. |
| **REGDB_E_READREGDB** | There was an error reading the registry. |

## Remarks

**CoGetTreatAsClass** returns the [TreatAs](https://learn.microsoft.com/windows/desktop/com/treatas) entry in the registry for the specified object. The **TreatAs** entry, if set, is the CLSID of a registered object (an application) that can emulate the object in question. The **TreatAs** entry is set through a call to the [CoTreatAsClass](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cotreatasclass) function. Emulation allows an application to open and edit an object of a different format, while retaining the original format of the object. Objects of the original CLSID are activated and treated as objects of the second CLSID. When the object is saved, this may result in loss of edits not supported by the original format. If there is no **TreatAs** entry for the specified object, this function returns the CLSID of the original object (*clsidOld*).

## See also

[CoTreatAsClass](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cotreatasclass)