# OleRegGetMiscStatus function

## Description

Returns miscellaneous information about the presentation and behaviors supported by the specified CLSID from the registry.

This function is used by developers of custom DLL object applications to emulate the behavior of the OLE default handler.

## Parameters

### `clsid` [in]

The CLSID of the class for which status information is to be requested.

### `dwAspect` [in]

The presentation aspect of the class for which information is requested. Possible values are taken from the [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect) enumeration.

### `pdwStatus` [out]

A pointer to the variable that receives the status information.

## Return value

This function can return the standard return value E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The status information was returned successfully. |
| **REGDB_E_CLASSNOTREG** | No CLSID is registered for the class object. |
| **REGDB_E_READREGDB** | There was an error reading from the registry. |
| **OLE_E_REGDB_KEY** | The **GetMiscStatus** key is missing from the registry. |

## Remarks

Object applications can ask OLE to get miscellaneous status information in one of two ways. One way is to call **OleRegGetMiscStatus**. The other is to return OLE_S_USEREG in response to calls by the default object handler to [IOleObject::GetMiscStatus](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getmiscstatus). OLE_S_USEREG instructs the default handler to call **OleRegGetMiscStatus**. Because DLL object applications cannot return OLE_S_USEREG, they must call **OleRegGetMiscStatus** rather than delegating the job to the object handler.

**OleRegGetMiscStatus** and its sibling functions, [OleRegGetUserType](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olereggetusertype), [OleRegEnumFormatEtc](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleregenumformatetc), and [OleRegEnumVerbs](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleregenumverbs), provide a way for developers of custom DLL object applications to emulate the behavior of OLE's default object handler in getting information about objects from the registry. By using these functions, you avoid the considerable work of writing your own, and the pitfalls inherent in working directly in the registry. In addition, you get future enhancements and optimizations of these functions without having to code them yourself.

## See also

[IOleObject::GetMiscStatus](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getmiscstatus)

[OleRegEnumFormatEtc](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleregenumformatetc)

[OleRegEnumVerbs](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleregenumverbs)

[OleRegGetUserType](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olereggetusertype)