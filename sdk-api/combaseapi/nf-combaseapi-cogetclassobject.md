# CoGetClassObject function

## Description

 Provides a pointer to an interface on a class object associated with a specified CLSID. **CoGetClassObject** locates, and if necessary, dynamically loads the executable code required to do this.

Call **CoGetClassObject** directly to create multiple objects through a class object for which there is a CLSID in the system registry. You can also retrieve a class object from a specific remote computer. Most class objects implement the [IClassFactory](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory) interface. You would then call [CreateInstance](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iclassfactory-createinstance) to create an uninitialized object. It is not always necessary to go through this process however. To create a single object, call the [CoCreateInstanceEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstanceex) function, which allows you to create an instance on a remote machine. This replaces the [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) function, which can still be used to create an instance on a local computer. Both functions encapsulate connecting to the class object, creating the instance, and releasing the class object. Two other functions, [CoGetInstanceFromFile](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cogetinstancefromfile) and [CoGetInstanceFromIStorage](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cogetinstancefromistorage), provide both instance creation on a remote system and object activation. There are numerous functions and interface methods whose purpose is to create objects of a single type and provide a pointer to an interface on that object.

## Parameters

### `rclsid` [in]

The CLSID associated with the data and code that you will use to create the objects.

### `dwClsContext` [in]

The context in which the executable code is to be run. To enable a remote activation, include CLSCTX_REMOTE_SERVER. For more information on the context values and their use, see the [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx) enumeration.

### `pvReserved` [in, optional]

A pointer to computer on which to instantiate the class object. If this parameter is **NULL**, the class object is instantiated on the current computer or at the computer specified under the class's [RemoteServerName](https://learn.microsoft.com/windows/desktop/com/remoteservername) key, according to the interpretation of the *dwClsCtx* parameter. See [COSERVERINFO](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-coserverinfo).

### `riid` [in]

Reference to the identifier of the interface, which will be supplied in _ppv_ on successful return. This interface will be used to communicate with the class object. Typically this value is IID_IClassFactory, although other values such as IID_IClassFactory2 which supports a form of licensing are allowed. All OLE-defined interface IIDs are defined in the OLE header files as IID_interfacename, where interfacename is the name of the interface.

### `ppv` [out]

The address of pointer variable that receives the interface pointer requested in *riid*. Upon successful return, **ppv* contains the requested interface pointer.

## Return value

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Location and connection to the specified class object was successful. |
| **REGDB_E_CLASSNOTREG** | The CLSID is not properly registered. This error can also indicate that the value you specified in *dwClsContext* is not in the registry. |
| **E_NOINTERFACE** | Either the object pointed to by *ppv* does not support the interface identified by *riid*, or the [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) operation on the class object returned E_NOINTERFACE. |
| **REGDB_E_READREGDB** | There was an error reading the registration database. |
| **CO_E_DLLNOTFOUND** | Either the in-process DLL or handler DLL was not found (depending on the context). |
| **CO_E_APPNOTFOUND** | The executable (.exe) was not found (CLSCTX_LOCAL_SERVER only). |
| **E_ACCESSDENIED** | There was a general access failure on load. |
| **CO_E_ERRORINDLL** | There is an error in the executable image. |
| **CO_E_APPDIDNTREG** | The executable was launched, but it did not register the class object (and it may have shut down). |

## Remarks

A class object in OLE is an intermediate object that supports an interface that permits operations common to a group of objects. The objects in this group are instances derived from the same object definition represented by a single CLSID. Usually, the interface implemented on a class object is [IClassFactory](https://learn.microsoft.com/windows/desktop/com/implementing-iclassfactory), through which you can create object instances of a given definition (class).

A call to **CoGetClassObject** creates, initializes, and gives the caller access (through a pointer to an interface specified with the *riid* parameter) to the class object. The class object is the one associated with the CLSID that you specify in the *rclsid* parameter. The details of how the system locates the associated code and data within a computer are transparent to the caller, as is the dynamic loading of any code that is not already loaded.

If the class context is CLSCTX_REMOTE_SERVER, indicating remote activation is required, the [COSERVERINFO](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-coserverinfo) structure provided in the *pServerInfo* parameter allows you to specify the computer on which the server is located. For information on the algorithm used to locate a remote server when *pServerInfo* is **NULL**, refer to the [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx) enumeration.

There are two places to find a CLSID for a class:

* The registry holds an association between CLSIDs and file suffixes, and between CLSIDs and file signatures for determining the class of an object.
* When an object is saved to persistent storage, its CLSID is stored with its data.

To create and initialize embedded or linked OLE document objects, it is not necessary to call **CoGetClassObject** directly. Instead, call the [OleCreate](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olecreate) or **OleCreate***XXX* function. These functions encapsulate the entire object instantiation and initialization process, and call, among other functions, **CoGetClassObject**.

The *riid* parameter specifies the interface the client will use to communicate with the class object. In most cases, this interface is [IClassFactory](https://learn.microsoft.com/windows/desktop/com/implementing-iclassfactory). This provides access to the [CreateInstance](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iclassfactory-createinstance) method, through which the caller can then create an uninitialized object of the kind specified in its implementation. All classes registered in the system with a CLSID must implement [IClassFactory](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory).

In rare cases, however, you may want to specify some other interface that defines operations common to a set of objects. For example, in the way OLE implements monikers, the interface on the class object is [IParseDisplayName](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iparsedisplayname), used to transform the display name of an object into a moniker.

The *dwClsContext* parameter specifies the execution context, allowing one CLSID to be associated with different pieces of code in different execution contexts. The [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx) enumeration specifies the available context flags. **CoGetClassObject** consults (as appropriate for the context indicated) both the registry and the class objects that are currently registered by calling the [CoRegisterClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterclassobject) function.

To release a class object, use the class object's [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method. The function [CoRevokeClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-corevokeclassobject) is to be used only to remove a class object's CLSID from the system registry.

## See also

[CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx)

[COSERVERINFO](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-coserverinfo)

[CoCreateInstanceEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstanceex)

[CoRegisterClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterclassobject)

[CoRevokeClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-corevokeclassobject)

[Creating an Object Through a Class Object](https://learn.microsoft.com/windows/desktop/com/creating-an-object-through-a-class-object)

[OleCreate](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olecreate)

[OleLoad](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleload)