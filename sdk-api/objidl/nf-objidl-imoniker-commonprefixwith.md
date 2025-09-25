# IMoniker::CommonPrefixWith

## Description

Creates a new moniker based on the prefix that this moniker has in common with the specified moniker.

## Parameters

### `pmkOther` [in]

A pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface on another moniker to be compared with this one to determine whether there is a common prefix.

### `ppmkPrefix` [out]

The address of an [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)* pointer variable that receives the interface pointer to the moniker that is the common prefix of this moniker and pmkOther. When successful, the implementation must call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the resulting moniker; it is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If an error occurs or if there is no common prefix, the implementation should set **ppmkPrefix* to **NULL**.

## Return value

This method can return the standard return values E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | A common prefix exists that is neither this moniker nor *pmkOther*. |
| **MK_S_NOPREFIX** | No common prefix exists. |
| **MK_S_HIM** | The entire *pmkOther* is a prefix of this moniker. |
| **MK_S_US** | The two monikers are identical. |
| **MK_S_ME** | This moniker is a prefix of the *pmkOther* moniker. |
| **MK_S_NOTBINDABLE** | This method was called on a relative moniker. It is not meaningful to take the common prefix on a relative moniker. |

## Remarks

**CommonPrefixWith** creates a new moniker that consists of the common prefixes of the moniker on this moniker object and another moniker. For example, if one moniker represents the path "c:\projects\secret\art\pict1.bmp" and another moniker represents the path "c:\projects\secret\docs\chap1.txt", the common prefix of these two monikers would be a moniker representing the path "c:\projects\secret".

### Notes to Callers

The **CommonPrefixWith** method is primarily called in the implementation of the [IMoniker::RelativePathTo](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-relativepathto) method. Clients using a moniker to locate an object rarely need to call this method.

Call this method only if *pmkOther* and this moniker are both absolute monikers. An absolute moniker is either a file moniker or a generic composite whose leftmost component is a file moniker that represents an absolute path. Do not call this method on relative monikers because it would not produce meaningful results.

### Notes to Implementers

Your implementation should first determine whether *pmkOther* is a moniker of a class that you recognize and for which you can provide special handling (for example, if it is of the same class as this moniker). If so, your implementation should determine the common prefix of the two monikers. Otherwise, it should pass both monikers in a call to the [MonikerCommonPrefixWith](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-monikercommonprefixwith) function, which correctly handles the generic case.

### Implementation-specific Notes

| Implementation | Notes |
| --- | --- |
| Anti-moniker | If the other moniker is also an anti-moniker, the method returns MK_S_US and sets ppmkPrefix to this moniker. Otherwise, the method calls the [MonikerCommonPrefixWith](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-monikercommonprefixwith) function. This function correctly handles the case where the other moniker is a generic composite. |
| Class moniker | If *pmkOther* is equal to this moniker, retrieves a pointer to this moniker and returns MK_S_US. If *pmkOther* is a class moniker but is not equal to this moniker, returns MK_E_NOPREFIX. Otherwise, returns the result of calling [MonikerCommonPrefixWith](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-monikercommonprefixwith) with itself as *pmkThis*, *pmkOther*, and *ppmkPrefix*, which handles the case where *pmkOther* is a generic composite moniker. |
| File moniker | If both monikers are file monikers, this method returns a file moniker that is based on the common components at the beginning of two file monikers. Components of a file moniker can be of the following types:<br><br>* A computer name of the form \\server\share. A computer name is treated as a single component, so two monikers representing the paths "\\myserver\public\work" and "\\myserver\private\games" do not have "\\myserver" as a common prefix.<br>* A drive designation (for example, "C:").<br>* A directory or file name.<br><br>If the other moniker is not a file moniker, this method passes both monikers in a call to the [MonikerCommonPrefixWith](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-monikercommonprefixwith) function. This function correctly handles the case where the other moniker is a generic composite.<br><br>This method returns MK_E_NOPREFIX if there is no common prefix. |
| Generic composite moniker | If the other moniker is a composite, this method compares the components of each composite from left to right. The returned common prefix moniker might also be a composite moniker, depending on how many of the leftmost components were common to both monikers. If the other moniker is not a composite, the method simply compares it to the leftmost component of this moniker.<br><br>If the monikers are equal, the method returns MK_S_US and sets *ppmkPrefix* to this moniker. If the other moniker is a prefix of this moniker, the method returns MK_S_HIM and sets *ppmkPrefix* to the other moniker. If this moniker is a prefix of the other, this method returns MK_S_ME and sets *ppmkPrefix* to this moniker.<br><br>If there is no common prefix, this method returns MK_E_NOPREFIX and sets *ppmkPrefix* to **NULL**. |
| Item moniker | If the other moniker is an item moniker that is equal to this moniker, this method sets **ppmkPrefix* to this moniker and returns MK_S_US; otherwise, the method calls the [MonikerCommonPrefixWith](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-monikercommonprefixwith) function. This function correctly handles the case where the other moniker is a generic composite. |
| OBJREF moniker | If the two monikers are equal, this method returns MK_S_US and sets **ppmkPrefix* to **NULL**. If the other moniker is not an OBJREF moniker, this method passes both monikers to the [MonikerCommonPrefixWith](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-monikercommonprefixwith) function. This function correctly handles the case where the other moniker is a generic composite.<br><br>If there is no common prefix, this method returns MK_E_NOPREFIX. |
| Pointer moniker | If the two monikers are equal, this method returns MK_S_US and sets **ppmkPrefix* to this moniker. Otherwise, the method returns MK_E_NOPREFIX and sets **ppmkPrefix* to **NULL**. |
| URL moniker | This method returns E_NOTIMPL. |

## See also

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)

[MonikerCommonPrefixWith](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-monikercommonprefixwith)