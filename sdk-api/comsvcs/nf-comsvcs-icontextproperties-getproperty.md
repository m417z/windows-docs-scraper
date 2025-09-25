# IContextProperties::GetProperty

## Description

Retrieves a context object property.

## Parameters

### `name` [in]

The name of the context object property to be retrieved.

The following are IIS intrinsic properties.

* Application
* Request
* Response
* Server
* Session

The following is the COMTI intrinsic property:

* host-security-callback.cedar.microsoft.com

### `pProperty` [out]

A pointer to the property.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

To retrieve an IIS object, call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) using the VT_DISPATCH member of the returned **VARIANT** for the interface to the IIS object (for example, IResponse for the Response object).

## See also

[IContextProperties](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icontextproperties)