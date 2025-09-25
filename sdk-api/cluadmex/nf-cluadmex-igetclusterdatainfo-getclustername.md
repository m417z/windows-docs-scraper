# IGetClusterDataInfo::GetClusterName

## Description

[This method is available for use in the operating systems specified in the Requirements
section. Support for this method was removed in Windows Server 2008.]

Returns the name of the cluster.

## Parameters

### `lpszName` [out]

Pointer to a null-terminated Unicode string containing the name of the cluster; or
**NULL** to indicate that the caller is requesting only the length of the name. Although
declared as a **BSTR**, this parameter is implemented as an
**LPWSTR**.

### `pcchName` [in, out]

On input, pointer to the size of the buffer, in characters, pointed to by the
*lpszName* parameter. On output, pointer to the total number of characters in the
buffer including the **NULL**-terminating character.

## Return value

If **GetClusterName** is not
successful, it can return other **HRESULT** values.

| Return code/value | Description |
| --- | --- |
| **NOERROR**<br><br>0 | The operation was successful. |
| **E_INVALIDARG**<br><br>0x80070057 | One or more of the parameters are invalid. |
| **HRESULT_FROM_WIN32(ERROR_MORE_DATA)**<br><br>0x800700ea | The buffer pointed to by *lpszName* is too small to hold the requested name. [GetClusterName](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nf-cluadmex-igetclusterdatainfo-getclustername) returns the required number of characters in the content of *pcchName*. |

## Remarks

If the *lpszName* parameter is set to **NULL** and the
*pcchName* parameter is not set to **NULL**, the
**GetClusterName** method returns
**NOERROR**.

## See also

[IGetClusterDataInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cluadmex/nn-cluadmex-igetclusterdatainfo)