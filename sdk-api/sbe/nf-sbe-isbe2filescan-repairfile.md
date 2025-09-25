# ISBE2FileScan::RepairFile

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Repairs a corrupted .WTV file.

You can use this method if you discover possible corruption in a .WTV file and want to restore the last-known good version of the file. The following situations might result in a corrupted file:

* A process that was creating the file crashed.
* Another process was writing to the file (for example, to update metadata) at the same time that the Stream Buffer Engine (SBE) attempted to repair it. SBE tries to fix corrupted .WTV files automatically every time it loads a .WTV file for playback and discovers errors in the file.

## Parameters

### `filename` [in]

A pointer to a null-terminated wide-character string that specifies the full path name of the .WTV file.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return value | Description |
| --- | --- |
| S_OK | Success. |
| E_POINTER | Null pointer argument. |
| INVALID_HANDLE_VALUE | Invalid .WTV file. |

## See also

[ISBE2FileScan](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2filescan)