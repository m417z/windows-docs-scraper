# ProgIDFromCLSID function

## Description

Retrieves the ProgID for a given CLSID.

## Parameters

### `clsid` [in]

The CLSID for which the ProgID is to be requested.

### `lplpszProgID` [out]

The address of a pointer variable that receives the ProgID string. The string that represents *clsid* includes enclosing braces.

## Return value

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The ProgID was returned successfully. |
| **REGDB_E_CLASSNOTREG** | Class not registered in the registry. |
| **REGDB_E_READREGDB** | There was an error reading from the registry. |

## Remarks

Every OLE object class listed in the **Insert Object** dialog box must have a programmatic identifier (ProgID), a string that uniquely identifies a given class, stored in the registry. In addition to determining the eligibility for the **Insert Object** dialog box, the ProgID can be used as an identifier in a macro programming language to identify a class. Finally, the ProgID is also the class name used for an object of an OLE class that is placed in an OLE 1 container.

**ProgIDFromCLSID** uses entries in the registry to do the conversion. OLE application authors are responsible for ensuring that the registry is configured correctly in the application's setup program.

The ProgID string must be different than the class name of any OLE 1 application, including the OLE 1 version of the same application, if there is one. In addition, a ProgID string must not contain more than 39 characters, start with a digit, or, except for a single period, contain any punctuation (including underscores).

The ProgID must never be shown to the user in the user interface. If you need a short displayable string for an object, call [IOleObject::GetUserType](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olereggetusertype).

Call the [CLSIDFromProgID](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-clsidfromprogid) function to find the CLSID associated with a given ProgID. Be sure to free the returned ProgID when you are finished with it by calling the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## See also

[CLSIDFromProgID](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-clsidfromprogid)