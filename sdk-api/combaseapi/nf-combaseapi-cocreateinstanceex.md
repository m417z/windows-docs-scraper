# CoCreateInstanceEx function

## Description

Creates an instance of a specific class on a specific computer.

## Parameters

### `Clsid` [in]

The CLSID of the object to be created.

### `punkOuter` [in]

If this parameter non-**NULL**, indicates the instance is being created as part of an aggregate, and *punkOuter* is to be used as the new instance's controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown). Aggregation is currently not supported cross-process or cross-computer. When instantiating an object out of process, CLASS_E_NOAGGREGATION will be returned if *punkOuter* is non-**NULL**.

### `dwClsCtx` [in]

A value from the [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx) enumeration.

### `pServerInfo` [in]

Information about the computer on which to instantiate the object. See [COSERVERINFO](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-coserverinfo). This parameter can be **NULL**, in which case the object is instantiated on the local computer or at the computer specified in the registry under the class's [RemoteServerName](https://learn.microsoft.com/windows/desktop/com/remoteservername) value, according to the interpretation of the *dwClsCtx* parameter.

### `dwCount` [in]

The number of structures in *pResults*. This value must be greater than 0.

### `pResults` [in, out]

An array of [MULTI_QI](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-multi_qi) structures. Each structure has three members: the identifier for a requested interface (**pIID**), the location to return the interface pointer (**pItf**) and the return value of the call to [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) (**hr**).

## Return value

This function can return the standard return value E_INVALIDARG, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |
| **REGDB_E_CLASSNOTREG** | A specified class is not registered in the registration database. Also can indicate that the type of server you requested in the [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx) enumeration is not registered or the values for the server types in the registry are corrupt. |
| **CLASS_E_NOAGGREGATION** | This class cannot be created as part of an aggregate. |
| **CO_S_NOTALLINTERFACES** | At least one, but not all of the interfaces requested in the *pResults* array were successfully retrieved. The **hr** member of each of the [MULTI_QI](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-multi_qi) structures in *pResults* indicates with S_OK or E_NOINTERFACE whether the specific interface was returned. |
| **E_NOINTERFACE** | None of the interfaces requested in the *pResults* array were successfully retrieved. |

## Remarks

**CoCreateInstanceEx** creates a single uninitialized object associated with the given CLSID on a specified remote computer. This is an extension of the function [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance), which creates an object on the local computer only. In addition, rather than requesting a single interface and obtaining a single pointer to that interface, **CoCreateInstanceEx** makes it possible to specify an array of structures, each pointing to an interface identifier (IID) on input, and, on return, containing (if available) a pointer to the requested interface and the return value of the [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) call for that interface. This permits fewer round trips between computers.

This function encapsulates three calls: first, to [CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject) to connect to the class object associated with the specified CLSID, specifying the location of the class; second, to [IClassFactory::CreateInstance](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iclassfactory-createinstance) to create an uninitialized instance, and finally, to [IClassFactory::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release), to release the class object.

The object so created must still be initialized through a call to one of the initialization interfaces (such as [IPersistStorage::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-load)). Two functions, [CoGetInstanceFromFile](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cogetinstancefromfile) and [CoGetInstanceFromIStorage](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cogetinstancefromistorage) encapsulate both the instance creation and initialization from the obvious sources.

The [COSERVERINFO](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-coserverinfo) structure passed as the *pServerInfo* parameter contains the security settings that COM will use when creating a new instance of the specified object. Note that this parameter does not influence the security settings used when making method calls on the instantiated object. Those security settings are configurable, on a per-interface basis, with the [CoSetProxyBlanket](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cosetproxyblanket) function. Also see, [IClientSecurity::SetBlanket](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclientsecurity-setblanket).

## See also

[CoGetInstanceFromFile](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cogetinstancefromfile)

[CoGetInstanceFromIStorage](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cogetinstancefromistorage)