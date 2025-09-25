# QueryActCtxSettingsW function

## Description

The **QueryActCtxSettingsW** function specifies the activation context, and the namespace and name of the attribute that is to be queried.

## Parameters

### `dwFlags` [in, optional]

This value must be 0.

### `hActCtx` [in, optional]

A handle to the activation context that is being queried.

### `settingsNameSpace` [in, optional]

A pointer to a string that contains the value **"http://schemas.microsoft.com/SMI/2005/WindowsSettings"** or **NULL**. These values are equivalent.

**Windows 8 and Windows Server 2012:** A pointer to a string that contains the value **"http://schemas.microsoft.com/SMI/2011/WindowsSettings"** is also a valid parameter. A **NULL** is still equivalent to the previous value.

### `settingName` [in]

The name of the attribute to be queried.

### `pvBuffer` [out]

A pointer to the buffer that receives the query result.

### `dwBuffer` [in]

The size of the buffer in characters that receives the query result.

### `pdwWrittenOrRequired` [out, optional]

A pointer to a value which is the number of characters written to the buffer specified by *pvBuffer* or that is required to hold the query result.

## Return value

If the function succeeds, it returns **TRUE**. Otherwise, it returns **FALSE**.

This function sets errors that can be retrieved by calling
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). For an example, see
[Retrieving the Last-Error Code](https://learn.microsoft.com/windows/desktop/Debug/retrieving-the-last-error-code). For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).