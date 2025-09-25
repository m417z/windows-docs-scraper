# DdeAddData function

## Description

Adds data to the specified Dynamic Data Exchange (DDE) object. An application can add data starting at any offset from the beginning of the object. If new data overlaps data already in the object, the new data overwrites the old data in the bytes where the overlap occurs. The contents of locations in the object that have not been written to are undefined.

## Parameters

### `hData` [in]

Type: **HDDEDATA**

A handle to the DDE object that receives additional data.

### `pSrc` [in]

Type: **LPBYTE**

The data to be added to the DDE object.

### `cb` [in]

Type: **DWORD**

The length, in bytes, of the data to be added to the DDE object, including the terminating **NULL**, if the data is a string.

### `cbOff` [in]

Type: **DWORD**

An offset, in bytes, from the beginning of the DDE object. The additional data is copied to the object beginning at this offset.

## Return value

Type: **HDDEDATA**

If the function succeeds, the return value is a new handle to the DDE object. The new handle is used in all references to the object.

If the function fails, the return value is zero.

The [DdeGetLastError](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddegetlasterror) function can be used to get the error code, which can be one of the following values:

## Remarks

After a data handle has been used as a parameter in another [Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library) function or has been returned by a DDE callback function, the handle can be used only for read access to the DDE object identified by the handle.

If the amount of memory originally allocated is less than is needed to hold the added data, **DdeAddData** reallocates a global memory object of the appropriate size.

## See also

**Conceptual**

[DdeAccessData](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeaccessdata)

[DdeCreateDataHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatedatahandle)

[DdeUnaccessData](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeunaccessdata)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**