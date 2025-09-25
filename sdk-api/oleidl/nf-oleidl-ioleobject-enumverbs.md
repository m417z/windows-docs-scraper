# IOleObject::EnumVerbs

## Description

Exposes a pull-down menu listing the verbs available for an object in ascending order by verb number.

## Parameters

### `ppEnumOleVerb` [out]

Address of [IEnumOLEVERB](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ienumoleverb) pointer variable that receives the interface pointer to the new enumerator object. Each time an object receives a call to **IOleObject::EnumVerbs**, it must increase the reference count on *ppEnumOleVerb*. It is the caller's responsibility to call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when it is done with *ppEnumOleVerb*. If an error occurs, *ppEnumOleVerb* must be set to **NULL**.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **OLE_S_USEREG** | Delegate to the default handler to use the entries in the registry to provide the enumeration. |
| **OLEOBJ_E_NOVERBS** | Object does not support any verbs. |

## See also

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[IOleObject::DoVerb](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb)

[OleRegEnumVerbs](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleregenumverbs)