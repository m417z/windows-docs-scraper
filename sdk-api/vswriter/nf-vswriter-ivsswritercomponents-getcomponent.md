# IVssWriterComponents::GetComponent

## Description

The
**GetComponent** method returns an
[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent) interface to one of a given writer's components explicitly stored in the Backup Components Document.

## Parameters

### `iComponent` [in]

Number of the component. The value of this parameter is an integer from 0
to *n*–1 inclusive, where *n* is the total number of components returned by
[IVssWriterComponents::GetComponentCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsswritercomponents-getcomponentcount).

### `ppComponent` [out]

Doubly indirect pointer to an instance of the
[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent) object that contains component information.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the component. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_OBJECT_NOT_FOUND** | The specified component was not found. |

## Remarks

The caller is responsible for calling [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) to release system resources held by the returned
[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent) object.

## See also

[IVssWriterComponents](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswritercomponents)