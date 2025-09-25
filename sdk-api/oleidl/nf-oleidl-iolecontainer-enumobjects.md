# IOleContainer::EnumObjects

## Description

Enumerates the objects in the current container.

## Parameters

### `grfFlags` [in]

Specifies which objects in a container are to be enumerated, as defined in the enumeration [OLECONTF](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olecontf).

### `ppenum` [out]

A pointer to an [IEnumUnknown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumunknown) pointer variable that receives the interface pointer to the enumerator object. Each time a container receives a successful call to **EnumObjects**, it must increase the reference count on the *ppenum* pointer the method returns. It is the caller's responsibility to call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when it is done with the pointer. If an error is returned, the implementation must set *ppenum* to **NULL**.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | Object enumeration not supported. |

## Remarks

A container should implement **EnumObjects** to enable programmatic clients to find out what objects it holds. This method, however, is not called in standard linking scenarios.

## See also

[IEnumUnknown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumunknown)

[IOleContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolecontainer)

[IOleItemContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleitemcontainer)

[OLECONTF](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olecontf)