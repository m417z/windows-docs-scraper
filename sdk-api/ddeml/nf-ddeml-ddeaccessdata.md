# DdeAccessData function

## Description

Provides access to the data in the specified Dynamic Data Exchange (DDE) object. An application must call the [DdeUnaccessData](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeunaccessdata) function when it has finished accessing the data in the object.

## Parameters

### `hData` [in]

Type: **HDDEDATA**

A handle to the DDE object to be accessed.

### `pcbDataSize` [out, optional]

Type: **LPDWORD**

A pointer to a variable that receives the size, in bytes, of the DDE object identified by the
*hData* parameter. If this parameter is **NULL**, no size information is returned.

## Return value

Type: **LPBYTE**

If the function succeeds, the return value is a pointer to the first byte of data in the DDE object.

If the function fails, the return value is **NULL**.

The [DdeGetLastError](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddegetlasterror) function can be used to get the error code, which can be one of the following values:

## Remarks

If the
*hData* parameter has not been passed to a Dynamic Data Exchange Management Library (DDEML) function, an application can use the pointer returned by **DdeAccessData** for read-write access to the DDE object. If
*hData* has already been passed to a DDEML function, the pointer should be used only for read access to the memory object.

## See also

**Conceptual**

[DdeAddData](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeadddata)

[DdeCreateDataHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatedatahandle)

[DdeFreeDataHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddefreedatahandle)

[DdeUnaccessData](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeunaccessdata)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**