# DdeCreateDataHandle function

## Description

Creates a Dynamic Data Exchange (DDE) object and fills the object with data from the specified buffer. A DDE application uses this function during transactions that involve passing data to the partner application.

## Parameters

### `idInst` [in]

Type: **DWORD**

The application instance identifier obtained by a previous call to the [DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea) function.

### `pSrc` [in, optional]

Type: **LPBYTE**

The data to be copied to the DDE object. If this parameter is **NULL**, no data is copied to the object.

### `cb` [in]

Type: **DWORD**

The amount of memory, in bytes, to copy from the buffer pointed to by
*pSrc*. (include the terminating NULL, if the data is a string). If this parameter is zero, the
*pSrc* parameter is ignored.

### `cbOff` [in]

Type: **DWORD**

An offset, in bytes, from the beginning of the buffer pointed to by the
*pSrc* parameter. The data beginning at this offset is copied from the buffer to the DDE object.

### `hszItem` [in, optional]

Type: **HSZ**

A handle to the string that specifies the data item corresponding to the DDE object. This handle must have been created by a previous call to the [DdeCreateStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatestringhandlea) function. If the data handle is to be used in an [XTYP_EXECUTE](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-execute) transaction, this parameter must be 0L.

### `wFmt` [in]

Type: **UINT**

The standard clipboard format of the data.

### `afCmd` [in]

Type: **UINT**

The creation flags. This parameter can be **HDATA_APPOWNED**, which specifies that the server application calling the **DdeCreateDataHandle** function owns the data handle this function creates. This flag enables the application to share the data handle with other DDEML applications rather than creating a separate handle to pass to each application. If this flag is specified, the application must eventually free the shared memory object associated with the handle by using the [DdeFreeDataHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddefreedatahandle) function. If this flag is not specified, the handle becomes invalid in the application that created the handle after the data handle is returned by the application's DDE callback function or is used as a parameter in another DDEML function.

## Return value

Type: **HDDEDATA**

If the function succeeds, the return value is a data handle.

If the function fails, the return value is 0L.

The [DdeGetLastError](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddegetlasterror) function can be used to get the error code, which can be one of the following values:

## Remarks

Any unfilled locations in the DDE object are undefined.

After a data handle has been used as a parameter in another DDEML function or has been returned by a DDE callback function, the handle can be used only for read access to the DDE object identified by the handle.

## See also

**Conceptual**

[DdeAccessData](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeaccessdata)

[DdeCreateStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatestringhandlea)

[DdeFreeDataHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddefreedatahandle)

[DdeGetData](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddegetdata)

[DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**