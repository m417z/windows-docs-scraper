# OleRegGetUserType function

## Description

Gets the user type of the specified class from the registry.

Developers of custom DLL object applications use this function to emulate the behavior of the OLE default handler.

## Parameters

### `clsid` [in]

The CLSID of the class for which the user type is to be requested.

### `dwFormOfType` [in]

The form of the user-presentable string. Possible values are taken from the enumeration [USERCLASSTYPE](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-userclasstype).

### `pszUserType` [out]

A pointer to a string that receives the user type.

## Return value

This function can return the standard return value E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The user type was returned successfully. |
| **REGDB_E_CLASSNOTREG** | No CLSID is registered for the class object. |
| **REGDB_E_READREGDB** | There was an error reading from the registry. |
| **OLE_E_REGDB_KEY** | The **ProgID** = *MainUserTypeName* and **CLSID** = *MainUserTypeName* keys are missing from the registry. |

## Remarks

Object applications can ask OLE to get the user type name of a specified class in one of two ways. One way is to call **OleRegGetUserType**. The other is to return OLE_S_USEREG in response to calls by the default object handler to [IOleObject::GetUserType](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getusertype). OLE_S_USEREG instructs the default handler to call **OleRegGetUserType**. Because DLL object applications cannot return OLE_S_USEREG, they must call **OleRegGetUserType**, rather than delegating the job to the object handler.

The **OleRegGetUserType** function and its sibling functions, [OleRegGetMiscStatus](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olereggetmiscstatus), [OleRegEnumFormatEtc](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleregenumformatetc), and [OleRegEnumVerbs](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleregenumverbs), provide a way for developers of custom DLL object applications to emulate the behavior of OLE's default object handler in getting information about objects from the registry. By using these functions, you avoid the considerable work of writing your own, and the pitfalls inherent in working directly in the registry. In addition, you get future enhancements and optimizations of these functions without having to code them yourself.

## See also

[IOleObject::GetUserType](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getusertype)

[OleRegEnumFormatEtc](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleregenumformatetc)

[OleRegEnumVerbs](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleregenumverbs)

[OleRegGetMiscStatus](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olereggetmiscstatus)