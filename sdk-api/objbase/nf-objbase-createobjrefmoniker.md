# CreateObjrefMoniker function

## Description

Creates an OBJREF moniker based on a pointer to an object.

## Parameters

### `punk` [in, optional]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the object that the moniker is to represent.

### `ppmk` [out]

Address of a pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface on the OBJREF moniker that was created.

## Return value

This function can return the standard return values E_OUTOFMEMORY, E_UNEXPECTED, and S_OK.

## Remarks

Clients use OBJREF monikers to obtain a marshaled pointer to a running object in the servers address space.

The server typically calls **CreateObjrefMoniker** to create an OBJREF moniker and then calls [IMoniker::GetDisplayName](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-getdisplayname), and finally releases the moniker. The display name for an OBJREF moniker is of the form:

OBJREF:*nnnnnnnn*

Where *nnnnnnnn* is an arbitrarily long base-64 encoding that encapsulates the computer location, process endpoint, and interface pointer ID (IPID) of the running object

The display name can then be transferred to the client as text. For example, the display name can reside on an HTML page that the client downloads.

The client can pass the display name to [MkParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-mkparsedisplayname), which creates an OBJREF moniker based on the display name. A call to the monikers [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject) method then obtains a marshaled pointer to the running instance on the server.

For example, a server-side COM component contained in an Active Server Page can create an OBJREF moniker, obtain its display name, and write the display name to the HTML output that is sent to the client browser. A script that runs on the client side can use the display name to get access to the running object itself. A client-side Visual Basic script, for instance, could store the display name in a variable called strMyName and include this line:

`objMyInstance = GetObject(strMyName)`

The script engine internally makes the calls to [MkParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-mkparsedisplayname) and [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject), and the script can then use objMyInstance to refer directly to the running object.

## See also

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)