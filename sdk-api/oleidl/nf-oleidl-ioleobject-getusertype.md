# IOleObject::GetUserType

## Description

Retrieves the user-type name of an object for display in user-interface elements such as menus, list boxes, and dialog boxes.

## Parameters

### `dwFormOfType` [in]

The form of the user-type name to be presented to users. Possible values are obtained from the [USERCLASSTYPE](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-userclasstype) enumeration.

### `pszUserType` [out]

Address of [LPOLESTR](https://learn.microsoft.com/windows/desktop/api/ocidl/ns-ocidl-calpolestr) pointer variable that receives a pointer to the user type string. The caller must free *pszUserType* using the current [IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc) instance. If an error occurs, the implementation must set *pszUserType* to **NULL**.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **OLE_S_USEREG** | Delegate to the default handler's implementation using the registry to provide the requested information. |

## Remarks

Containers call **IOleObject::GetUserType** in order to represent embedded objects in list boxes, menus, and dialog boxes by their normal, user-recognizable names. Examples include "Word Document," "Excel Chart," and "Paintbrush Object." The information returned by **IOleObject::GetUserType** is the user-readable equivalent of the binary class identifier returned by [IOleObject::GetUserClassID](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getuserclassid).

### Notes to Callers

The default handler's implementation of **IOleObject::GetUserType** uses the object's class identifier (the *pClsid* parameter returned by [IOleObject::GetUserClassID](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getuserclassid)) and the *dwFormOfType* parameter together as a key into the registry. If an entry is found that matches the key exactly, then the user type specified by that entry is returned. If only the CLSID part of the key matches, then the lowest-numbered entry available (usually the full name) is used. If the CLSID is not found, or there are no user types registered for the class, the user type currently found in the object's storage is used.

You should not cache the string returned from **IOleObject::GetUserType**. Instead, call this method each and every time the string is needed. This guarantees correct results when the embedded object is being converted from one type into another without the caller's knowledge. Calling this method is inexpensive because the default handler implements it using the registry.

### Notes to Implementers

You can use the implementation provided by the default handler by returning OLE_S_USEREG as your application's implementation of this method. If the user type name is an empty string, the message "Unknown Object" is returned.

You can call the OLE helper function [OleRegGetUserType](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olereggetusertype) to return the appropriate user type.

## See also

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[IOleObject::GetUserClassID](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getuserclassid)

[IOleObject::SetHostNames](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-sethostnames)

[OleRegGetUserType](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olereggetusertype)

[ReadFmtUserTypeStg](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-readfmtusertypestg)

[USERCLASSTYPE](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-userclasstype)