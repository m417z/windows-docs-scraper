# CoTreatAsClass function

## Description

Establishes or removes an emulation, in which objects of one class are treated as objects of a different class.

## Parameters

### `clsidOld` [in]

The CLSID of the object to be emulated.

### `clsidNew` [in]

The CLSID of the object that should emulate the original object. This replaces any existing emulation for *clsidOld*. This parameter can be CLSID_NULL, in which case any existing emulation for *clsidOld* is removed.

## Return value

This function can return the standard return values E_INVALIDARG, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The emulation was successfully established or removed. |
| **REGDB_E_CLASSNOTREG** | The *clsidOld* parameter is not properly registered in the registration database. |
| **REGDB_E_READREGDB** | Error reading from registration database. |
| **REGDB_E_WRITEREGDB** | Error writing to registration database. |

## Remarks

This function sets the **TreatAs** entry in the registry for the specified object, allowing the object to be emulated by another application. Emulation allows an application to open and edit an object of a different format, while retaining the original format of the object. After this entry is set, whenever any function such as [CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject) specifies the object's original CLSID (*clsidOld*), it is transparently forwarded to the new CLSID (*clsidNew*), thus launching the application associated with the **TreatAs** CLSID. When the object is saved, it can be saved in its native format, which may result in loss of edits not supported by the original format.

If your application supports emulation, call **CoTreatAsClass** in the following situations:

* In response to an end-user request (through a conversion dialog box) that a specified object be treated as an object of a different class (an object created under one application be run under another application, while retaining the original format information).
* In a setup program, to register that one class of objects be treated as objects of a different class.

An example of the first case is that an end user might wish to edit a spreadsheet created by one application using a different application that can read and write the spreadsheet format of the original application. For an application that supports emulation, **CoTreatAsClass** can be called to implement a **Treat As** option in a conversion dialog box.

An example of the use of **CoTreatAsClass** in a setup program would be in an updated version of an application. When the application is updated, the objects created with the earlier version can be activated and treated as objects of the new version, while retaining the previous format information. This would allow you to give the user the option to convert when they save, or to save it in the previous format, possibly losing format information not available in the older version.

One result of setting an emulation is that when you enumerate verbs, as in the [IOleObject::EnumVerbs](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumverbs) method implementation in the default handler, this would enumerate the verbs from *clsidNew* instead of *clsidOld*.

To ensure that existing emulation information is removed when you install an application, your setup programs should call **CoTreatAsClass**, setting the *clsidNew* parameter to CLSID_NULL to remove any existing emulation for the classes they install.

If there is no CLSID assigned to the **AutoTreatAs** key in the registry, setting *clsidNew* and *clsidOld* to the same value removes the **TreatAs** entry, so there is no emulation. If there is a CLSID assigned to the **AutoTreatAs** key, that CLSID is assigned to the **TreatAs** key.

**CoTreatAsClass** does not validate whether an appropriate registry entry for clsidNew currently exists.

## See also

[CoGetTreatAsClass](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogettreatasclass)