# IRichEditOle::GetObject

## Description

Retrieves information, stored in a [REOBJECT](https://learn.microsoft.com/windows/desktop/api/richole/ns-richole-reobject) structure, about an object in a rich edit control.

## Parameters

### `iob`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Zero-based index that specifies which object to return information about. If this parameter is **REO_IOB_USE_CP**, information about the object at the character position specified by the [REOBJECT](https://learn.microsoft.com/windows/desktop/api/richole/ns-richole-reobject) structure is returned.

### `lpreobject`

Type: **[REOBJECT](https://learn.microsoft.com/windows/desktop/api/richole/ns-richole-reobject)***

Structure that receives information about the object. The reference count of the interfaces returned in this structure has been incremented; it is the responsibility of the caller to use the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method to decrement the count.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Operation flags that specify which interfaces to return in the structure. The *dwFlags* parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **REO_GETOBJ_POLEOBJ** | Get object interface. |
| **REO_GETOBJ_PSTG** | Get storage interface. |
| **REO_GETOBJ_POLESITE** | Get site interface. |
| **REO_GETOBJ_NO_INTERFACES** | Get no interfaces. |
| **REO_GETOBJ_ALL_INTERFACES** | Get all interfaces. |

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **S_OK** if successful, or an error value otherwise. **E_INVALIDARG** is returned if no buffer for the [REOBJECT](https://learn.microsoft.com/windows/desktop/api/richole/ns-richole-reobject) structure was given or if the *iob* value or character position is invalid.

## See also

[IRichEditOle](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditole)

[REOBJECT](https://learn.microsoft.com/windows/desktop/api/richole/ns-richole-reobject)

**Reference**