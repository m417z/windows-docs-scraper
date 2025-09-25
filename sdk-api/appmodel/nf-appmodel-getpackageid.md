# GetPackageId function

## Description

Gets the package identifier (ID) for the specified process.

## Parameters

### `hProcess` [in]

Type: **HANDLE**

A handle to the process that has the **PROCESS_QUERY_INFORMATION** or **PROCESS_QUERY_LIMITED_INFORMATION** access right. For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `bufferLength` [in, out]

Type: **UINT32***

On input, the size of *buffer*, in bytes. On output, the size of the structure returned, in bytes.

### `buffer` [out, optional]

Type: **BYTE***

The package ID, represented as a [PACKAGE_ID](https://learn.microsoft.com/windows/desktop/api/appmodel/ns-appmodel-package_id) structure.

## Return value

Type: **LONG**

If the function succeeds it returns **ERROR_SUCCESS**. Otherwise, the function returns an error code. The possible error codes include the following.

| Return code | Description |
| --- | --- |
| **APPMODEL_ERROR_NO_PACKAGE** | The process has no package identity. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer is not large enough to hold the data. The required size is specified by *bufferLength*. |

## See also

[GetCurrentPackageId](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getcurrentpackageid)

[GetPackageFamilyName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackagefamilyname)

[GetPackageFullName](https://learn.microsoft.com/windows/desktop/api/appmodel/nf-appmodel-getpackagefullname)