# DdeFreeDataHandle function

## Description

Frees a Dynamic Data Exchange (DDE) object and deletes the data handle associated with the object.

## Parameters

### `hData` [in]

Type: **HDDEDATA**

A handle to the DDE object to be freed. This handle must have been created by a previous call to the [DdeCreateDataHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatedatahandle) function or returned by the [DdeClientTransaction](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeclienttransaction) function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

The [DdeGetLastError](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddegetlasterror) function can be used to get the error code, which can be one of the following values:

## Remarks

An application must call **DdeFreeDataHandle** under the following circumstances:

* To free a DDE object that the application allocated by calling the [DdeCreateDataHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatedatahandle) function if the object's data handle was never passed by the application to another Dynamic Data Exchange Management Library (DDEML) function
* To free a DDE object that the application allocated by specifying the **HDATA_APPOWNED** flag in a call to [DdeCreateDataHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatedatahandle)
* To free a DDE object whose handle the application received from the [DdeClientTransaction](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeclienttransaction) function

The system automatically frees an unowned object when its handle is returned by a DDE callback function or is used as a parameter in a DDEML function.

## See also

**Conceptual**

[DdeAccessData](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeaccessdata)

[DdeClientTransaction](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeclienttransaction)

[DdeCreateDataHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatedatahandle)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**