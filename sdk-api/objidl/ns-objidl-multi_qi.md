# MULTI_QI structure

## Description

Represents an interface in a query for multiple interfaces.

## Members

### `pIID`

A pointer to an interface identifier.

### `pItf`

A pointer to the interface requested in **pIID**. This member must be **NULL** on input.

### `hr`

The return value of the [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) call to locate the requested interface. Common return values include S_OK and E_NOINTERFACE. This member must be 0 on input.

## Remarks

To optimize network performance, most remote activation functions take an array of **MULTI_QI** structures rather than just a single IID as input and a single pointer to the requested interface on the object as output, as do local activation functions. This allows a set of pointers to interfaces to be returned from the same object in a single round-trip to the server. In network scenarios, requesting multiple interfaces at the time of object construction can save considerable time over using a number of calls to [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) for unique interfaces, each of which would require a round-trip to the server.

## See also

[CoCreateInstanceEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstanceex)

[CoGetInstanceFromFile](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cogetinstancefromfile)

[CoGetInstanceFromIStorage](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-cogetinstancefromistorage)

[IMultiQI](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imultiqi)