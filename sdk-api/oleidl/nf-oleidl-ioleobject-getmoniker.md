# IOleObject::GetMoniker

## Description

Retrieves an embedded object's moniker, which the caller can use to link to the object.

## Parameters

### `dwAssign` [in]

Determines how the moniker is assigned to the object. Depending on the value of *dwAssign*, **IOleObject::GetMoniker** does one of the following:

* Obtains a moniker only if one has already been assigned.
* Forces assignment of a moniker, if necessary, in order to satisfy the call.
* Obtains a temporary moniker.

Values for *dwAssign* are specified in the enumeration [OLEGETMONIKER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olegetmoniker).

**Note** You cannot pass [OLEGETMONIKER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olegetmoniker)_UNASSIGN when calling **IOleObject::GetMoniker**. This value is valid only when calling **IOleObject::GetMoniker**.

### `dwWhichMoniker` [in]

Specifies the form of the moniker being requested. Possible values are taken from the enumeration [OLEWHICHMK](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olewhichmk).

### `ppmk` [out]

Address of [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) pointer variable that receives the interface pointer to the object's moniker. If an error occurs, *ppmk* must be set to **NULL**. Each time an object receives a call to **IOleObject::GetMoniker**, it must increase the reference count on *ppmk*. It is the caller's responsibility to call Release when it is done with *ppmk*.

## Return value

This method returns S_OK on success.

## Remarks

The **IOleObject::GetMoniker** method returns an object's moniker. Like [IOleObject::SetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setmoniker), this method is important only in the context of managing links to embedded objects and even in that case is optional. A potential link client that requires an object's moniker to bind to the object can call this method to obtain that moniker. The default implementation of **IOleObject::GetMoniker** calls the [IOleClientSite::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-getmoniker), returning E_UNEXPECTED if the object is not running or does not have a valid pointer to a client site.

## See also

[CreateItemMoniker](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createitemmoniker)

[IOleClientSite::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-getmoniker)

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[IOleObject::SetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setmoniker)

[OLEGETMONIKER](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olegetmoniker)

[OLEWHICHMK](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olewhichmk)