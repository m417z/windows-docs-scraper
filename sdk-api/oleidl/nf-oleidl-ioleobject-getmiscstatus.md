# IOleObject::GetMiscStatus

## Description

Retrieves the status of an object at creation and loading.

## Parameters

### `dwAspect` [in]

The aspect of an object about which status information is being requested. The value is obtained from the enumeration [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect).

### `pdwStatus` [out]

Pointer to where the status information is returned. This parameter cannot be **NULL**.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **OLE_S_USEREG** | Delegate the retrieval of miscellaneous status information to the default handler's implementation of this method. |
| **CO_E_CLASSNOTREG** | There is no CLSID registered for the object. |
| **CO_E_READREGDB** | Error accessing the registry. |

## Remarks

A container normally calls **IOleObject::GetMiscStatus** when it creates or loads an object in order to determine how to display the object and what types of behaviors it supports.

Objects store status information in the registry. If the object is not running, the default handler's implementation of **IOleObject::GetMiscStatus** retrieves this information from the registry. If the object is running, the default handler invokes **IOleObject::GetMiscStatus** on the object itself.

The information that is actually stored in the registry varies with individual objects. The status values to be returned are defined in the enumeration [OLEMISC](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olemisc).

The default value of **IOleObject::GetMiscStatus** is used if a subkey corresponding to the specified [DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect) is not found. To set an OLE control, specify DVASPECT==1. This will cause the following to occur in the registry:

```
HKEY_CLASSES_ROOT\CLSID\ . . .
   MiscStatus = 1
```

### Notes to Implementers

Implementation normally consists of delegating the call to the default handler.

## See also

[DVASPECT](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-dvaspect)

[FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc)

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[OLEMISC](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olemisc)