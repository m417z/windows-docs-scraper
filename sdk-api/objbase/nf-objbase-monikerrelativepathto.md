# MonikerRelativePathTo function

## Description

Provides a moniker that, when composed onto the end of the first specified moniker (or one with a similar structure), yields the second specified moniker.

This function is intended for use only by [IMoniker::RelativePathTo](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-relativepathto) implementations.

## Parameters

### `pmkSrc` [in]

A pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface on the moniker that, when composed with the relative moniker to be created, produces *pmkDest*. This moniker identifies the "source" of the relative moniker to be created.

### `pmkDest` [in]

A pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface on the moniker to be expressed relative to *pmkSrc*. This moniker identifies the destination of the relative moniker to be created.

### `ppmkRelPath` [out]

The address of an [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)* pointer variable that receives the interface pointer to the new relative moniker. When successful, the function has called [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the moniker and the caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If an error occurs, the interface pointer value is **NULL**.

### `dwReserved` [in]

This parameter is reserved and must be nonzero.

## Return value

This function can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | A meaningful relative path has been returned. |
| **MK_S_HIM** | The only form of the relative path is the other moniker. |
| **MK_E_NOTBINDABLE** | The *pmkSrc* parameter is a relative moniker, such as an item moniker, and must be composed with the moniker of its container before a relative path can be determined. |

## Remarks

Your implementation of [IMoniker::RelativePathTo](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-relativepathto) should first check whether the other moniker is of a type you recognize and handle in a special way. If not, you should call **MonikerRelativePathTo**, passing itself as *pmkThis* and the other moniker as *pmkOther*. **MonikerRelativePathTo** correctly handles the cases where either moniker is a generic composite.

You should call this function only if *pmkSrc* and *pmkDest* are both absolute monikers, where an absolute moniker is either a file moniker or a generic composite whose leftmost component is a file moniker, and where the file moniker represents an absolute path. Do not call this function on relative monikers.

## See also

[IMoniker::RelativePathTo](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-relativepathto)