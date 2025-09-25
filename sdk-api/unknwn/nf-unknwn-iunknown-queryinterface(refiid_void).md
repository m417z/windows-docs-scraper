## Description

Queries a COM object for a pointer to one of its interface; identifying the interface by a reference to its interface identifier (IID). If the COM object implements the interface, then it returns a pointer to that interface after calling [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on it.

## Parameters

### `riid`

Type: **REFIID**

A reference to the interface identifier (IID) of the interface being queried for.

### `ppvObject`

Type: **[void](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)\*\***

The address of a pointer to an interface with the IID specified in the *riid* parameter. Because you pass the address of an interface pointer, the method can overwrite that address with the pointer to the interface being queried for. Upon successful return, *\*ppvObject* (the dereferenced address) contains a pointer to the requested interface. If the object doesn't support the interface, the method sets *\*ppvObject* (the dereferenced address) to `nullptr`.

## Return value

This method returns **S_OK** if the interface is supported, and **E_NOINTERFACE** otherwise. If *ppvObject* (the address) is `nullptr`, then this method returns **E_POINTER**.

## Remarks

For any given COM object (also known as a COM component), a specific query for the [IUnknown interface](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) on any of the object's interfaces must always return the same pointer value. This enables a client to determine whether two pointers point to the same component by calling **QueryInterface** with **IID_IUnknown** and comparing the results. It is specifically not the case that queries for interfaces other than **IUnknown** (even the same interface through the same pointer) must return the same pointer value.

There are four requirements for implementations of **QueryInterface** (In these cases, "must succeed" means "must succeed barring catastrophic failure.").

- The set of interfaces accessible on an object through **QueryInterface** must be static, not dynamic. This means that if a call to **QueryInterface** for a pointer to a specified interface succeeds the first time, then it must succeed again. If the call fails the first time, then it must fail on all subsequent calls.
- It must be reflexive—if a client holds a pointer to an interface on an object, and the client queries for that interface, then the call must succeed.
- It must be symmetric—if a client holding a pointer to one interface queries successfully for another, then a query through the obtained pointer for the first interface must succeed.
- It must be transitive—if a client holding a pointer to one interface queries successfully for a second, and through that pointer queries successfully for a third interface, then a query for the first interface through the pointer for the third interface must succeed.

### Notes to implementers

Implementations of **QueryInterface** must never check ACLs. The main reason for this rule is that COM requires that an object supporting a particular interface always return success when queried for that interface. Another reason is that checking ACLs on **QueryInterface** does not provide any real security because any client who has access to a particular interface can hand it directly to another client without any calls back to the server. Also, because COM caches interface pointers, it does not call **QueryInterface** on the server every time a client does a query.

## See also

* [IUnknown interface](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)