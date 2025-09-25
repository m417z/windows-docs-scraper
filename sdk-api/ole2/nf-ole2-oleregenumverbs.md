# OleRegEnumVerbs function

## Description

Supplies an enumeration of the registered verbs for the specified class. Developers of custom DLL object applications use this function to emulate the behavior of the default object handler.

## Parameters

### `clsid` [in]

Class identifier whose verbs are being requested.

### `ppenum` [out]

Address of [IEnumOLEVERB](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ienumoleverb)* pointer variable that receives the interface pointer to the new enumeration object.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **OLEOBJ_E_NOVERBS** | No verbs are registered for the class. |
| **REGDB_E_CLASSNOTREG** | No CLSID is registered for the class object. |
| **REGDB_E_READREGDB** | An error occurred reading the registry. |
| **OLE_E_REGDB_KEY** | The DataFormats/GetSet key is missing from the registry. |

## Remarks

Object applications can ask OLE to create an enumeration object for [OLEVERB](https://learn.microsoft.com/windows/desktop/api/oleidl/ns-oleidl-oleverb) structures to enumerate supported verbs in one of two ways. One way is to call **OleRegEnumVerbs**. The other way is to return OLE_S_USEREG in response to calls by the default object handler to [IOleObject::EnumVerbs](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumverbs). OLE_S_USEREG instructs the default handler to call **OleRegEnumVerbs**. Because DLL object applications cannot return OLE_S_USEREG, they must call **OleRegEnumVerbs** rather than delegating the job to the object handler. With the supplied [IEnumOLEVERB](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ienumoleverb) pointer to the object, you can call the standard enumeration object methods to do the enumeration.

The **OleRegEnumVerbs** function and its sibling functions, [OleRegGetUserType](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olereggetusertype), [OleRegGetMiscStatus](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olereggetmiscstatus), and [OleRegEnumFormatEtc](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleregenumformatetc), provide a way for developers of custom DLL object applications to emulate the behavior of OLE's default object handler in getting information about objects from the registry. By using these functions, you avoid the considerable work of writing your own, and the pitfalls inherent in working directly in the registry. In addition, you get future enhancements and optimizations of these functions without having to code them yourself.

## See also

[IEnumOLEVERB](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ienumoleverb)

[IOleObject::EnumVerbs](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-enumverbs)