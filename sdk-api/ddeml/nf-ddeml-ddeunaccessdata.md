# DdeUnaccessData function

## Description

Unaccesses a Dynamic Data Exchange (DDE) object. An application must call this function after it has finished accessing the object.

## Parameters

### `hData` [in]

Type: **HDDEDATA**

A handle to the DDE object.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

The [DdeGetLastError](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddegetlasterror) function can be used to get the error code, which can be one of the following values:

## See also

**Conceptual**

[DdeAccessData](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeaccessdata)

[DdeAddData](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeadddata)

[DdeCreateDataHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatedatahandle)

[DdeFreeDataHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddefreedatahandle)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**