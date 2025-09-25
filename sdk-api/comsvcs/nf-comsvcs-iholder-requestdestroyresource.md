# IHolder::RequestDestroyResource

## Description

Deletes a resource, calling its destructor to free memory and other associated system resources.

## Parameters

### `__MIDL__IHolder0009` [in]

The resource to be destroyed.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | *ResId* is not a valid resource handle. |
| **E_FAIL** | The method failed. The resource has not been destroyed. |

## See also

[IHolder](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iholder)