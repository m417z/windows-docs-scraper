# MonikerCommonPrefixWith function

## Description

Creates a new moniker based on the common prefix that this moniker (the one comprising the data of this moniker object) shares with another moniker.

This function is intended to be called only in implementations of [IMoniker::CommonPrefixWith](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-commonprefixwith).

## Parameters

### `pmkThis` [in]

A pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface on one of the monikers for which a common prefix is sought; usually the moniker in which this call is used to implement [IMoniker::CommonPrefixWith](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-commonprefixwith).

### `pmkOther` [in]

A pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface on the moniker to be compared with the first moniker.

### `ppmkCommon` [out]

The address of an [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)* pointer variable that receives the interface pointer to the moniker based on the common prefix of *pmkThis* and *pmkOther*. When successful, the function has called [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the moniker and the caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If an error occurs, the supplied interface pointer value is **NULL**.

## Return value

This function can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | A common prefix exists that is neither *pmkThis* nor *pmkOther*. |
| **MK_S_HIM** | The entire *pmkOther* moniker is a prefix of the *pmkThis* moniker. |
| **MK_S_ME** | The entire *pmkThis* moniker is a prefix of the *pmkOther* moniker. |
| **MK_S_US** | The *pmkThis* and *pmkOther* monikers are equal. |
| **MK_E_NOPREFIX** | The monikers have no common prefix. |
| **MK_E_NOTBINDABLE** | This function was called on a relative moniker. It is not meaningful to take the common prefix of relative monikers. |

## Remarks

Your implementation of [IMoniker::CommonPrefixWith](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-commonprefixwith) should first check whether the other moniker is of a type that you recognize and handle in a special way. If not, you should call **MonikerCommonPrefixWith**, passing itself as *pmkThis* and the other moniker as *pmkOther*. **MonikerCommonPrefixWith** correctly handles the cases where either moniker is a generic composite.

You should call this function only if *pmkThis* and *pmkOther* are both absolute monikers (where an absolute moniker is either a file moniker or a generic composite whose leftmost component is a file moniker, and where the file moniker represents an absolute path). Do not call this function on relative monikers.

## See also

[IMoniker::CommonPrefixWith](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-commonprefixwith)