# DdeGetData function

## Description

Copies data from the specified Dynamic Data Exchange (DDE) object to the specified local buffer.

## Parameters

### `hData` [in]

Type: **HDDEDATA**

A handle to the DDE object that contains the data to copy.

### `pDst` [out, optional]

Type: **LPBYTE**

A pointer to the buffer that receives the data. If this parameter is **NULL**, the **DdeGetData** function returns the amount of data, in bytes, that would be copied to the buffer.

### `cbMax` [in]

Type: **DWORD**

The maximum amount of data, in bytes, to copy to the buffer pointed to by the
*pDst* parameter. Typically, this parameter specifies the length of the buffer pointed to by
*pDst*.

### `cbOff` [in]

Type: **DWORD**

An offset within the DDE object. Data is copied from the object beginning at this offset.

## Return value

Type: **DWORD**

If the
*pDst* parameter points to a buffer, the return value is the size, in bytes, of the memory object associated with the data handle or the size specified in the
*cbMax* parameter, whichever is lower.

If the
*pDst* parameter is **NULL**, the return value is the size, in bytes, of the memory object associated with the data handle.

The [DdeGetLastError](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddegetlasterror) function can be used to get the error code, which can be one of the following values:

## See also

**Conceptual**

[DdeAccessData](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeaccessdata)

[DdeCreateDataHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatedatahandle)

[DdeFreeDataHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddefreedatahandle)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**