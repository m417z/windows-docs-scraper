# IOleContainer::LockContainer

## Description

Keeps the container for embedded objects running until explicitly released.

## Parameters

### `fLock` [in]

Indicates whether to lock (**TRUE**) or unlock (**FALSE**) a container.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The operation failed. |
| **E_OUTOFMEMORY** | Insufficient memory available for the operation. |

## Remarks

An embedded object calls **LockContainer** to keep its container running when the object has link clients that require an update. If an end user selects **File Close** from the container's menu, however, the container ignores all outstanding **LockContainer** locks and closes the document anyway.

## See also

[CoLockObjectExternal](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-colockobjectexternal)

[IOleContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecontainer)

[IRunnableObject::Run](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunnableobject-run)