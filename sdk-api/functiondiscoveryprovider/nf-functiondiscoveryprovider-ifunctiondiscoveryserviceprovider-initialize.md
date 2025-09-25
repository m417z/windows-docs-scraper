# IFunctionDiscoveryServiceProvider::Initialize

## Description

[Function Discovery is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Initializes an object that provides a specific interface that has been bound to the resource represented by the function instance.

## Parameters

### `pIFunctionInstance` [in]

A pointer to an [IFunctionInstance](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryapi/nn-functiondiscoveryapi-ifunctioninstance) interface that represents the underlying resource.

### `riid` [in]

A reference to the identifier of the interface to be used to communicate with the object.

### `ppv` [out]

The interface pointer requested in *riid*. Upon successful return, **ppv* contains the requested interface pointer. Upon failure, **ppv* contains **NULL**.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One of the parameters contains an invalid argument. |

## Remarks

Any error code indicates failure. The provider should return an appropriate error code if it is unable to create the desired object.

## See also

[IFunctionDiscoveryServiceProvider](https://learn.microsoft.com/windows/desktop/api/functiondiscoveryprovider/nn-functiondiscoveryprovider-ifunctiondiscoveryserviceprovider)