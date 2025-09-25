# CoGetInstanceFromFile function

## Description

Creates a new object and initializes it from a file using [IPersistFile::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-load).

## Parameters

### `pServerInfo` [in, optional]

A pointer to a [COSERVERINFO](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-coserverinfo) structure that specifies the computer on which to instantiate the object and the authentication setting to be used. This parameter can be **NULL**, in which case the object is instantiated on the current computer, at the computer specified under the [RemoteServerName](https://learn.microsoft.com/windows/desktop/com/remoteservername) registry value for the class, or at the computer where the *pwszName* file resides if the [ActivateAtStorage](https://learn.microsoft.com/windows/desktop/com/activateatstorage) value is specified for the class or there is no local registry information.

### `pClsid` [in, optional]

A pointer to the class identifier of the object to be created. This parameter can be **NULL**, in which case there is a call to [GetClassFile](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-getclassfile), using *pwszName* as its parameter to get the class of the object to be instantiated.

### `punkOuter` [in, optional]

When non-**NULL**, indicates the instance is being created as part of an aggregate, and *punkOuter* is to be used as the pointer to the new instance's controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown). Aggregation is not supported cross-process or cross-computer. When instantiating an object out of process, CLASS_E_NOAGGREGATION will be returned if *punkOuter* is non-**NULL**.

### `dwClsCtx` [in]

Values from the [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx) enumeration.

### `grfMode` [in]

Specifies how the file is to be opened. See [STGM Constants](https://learn.microsoft.com/windows/desktop/Stg/stgm-constants).

### `pwszName` [in]

The file used to initialize the object with [IPersistFile::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-load). This parameter cannot be **NULL**.

### `dwCount` [in]

The number of structures in *pResults*. This parameter must be greater than 0.

### `pResults` [in, out]

An array of [MULTI_QI](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-multi_qi) structures. Each structure has three members: the identifier for a requested interface (**pIID**), the location to return the interface pointer (**pItf**) and the return value of the call to [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) (**hr**).

## Return value

This function can return the standard return value E_INVALIDARG, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The function retrieved all of the interfaces successfully. |
| **CO_S_NOTALLINTERFACES** | At least one, but not all of the interfaces requested in the *pResults* array were successfully retrieved. The **hr** member of each of the [MULTI_QI](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-multi_qi) structures indicates with S_OK or E_NOINTERFACE whether the specific interface was returned. |
| **E_NOINTERFACE** | None of the interfaces requested in the *pResults* array were successfully retrieved. |

## Remarks

**CoGetInstanceFromFile** creates a new object and initializes it from a file using [IPersistFile::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-load). The result of this function is similar to creating an instance with a call to [CoCreateInstanceEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstanceex), followed by an initializing call to **IPersistFile::Load**, with the following important distinctions:

* Fewer network round trips are required by this function when instantiating an object on a remote computer.
* In the case where *dwClsCtx* is set to CLSCTX_REMOTE_SERVER and *pServerInfo* is **NULL**, if the class is registered with the [ActivateAtStorage](https://learn.microsoft.com/windows/desktop/com/activateatstorage) sub-key or has no associated registry information, this function will instantiate an object on the computer where *pwszName* resides, providing the least possible network traffic.

## See also

[CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx)

[CoCreateInstanceEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstanceex)

[CoGetInstanceFromIStorage](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cogetinstancefromistorage)