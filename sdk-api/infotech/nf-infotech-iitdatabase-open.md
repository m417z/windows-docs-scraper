# IITDatabase::Open

## Description

Opens a database.

## Parameters

### `lpszHost` [in]

Host name. You can pass NULL if calling the **Open** method locally, otherwise this string should contain the host description string, described below.

### `lpszMoniker` [in]

Name of database file to open. This should include the full path to the file name, if calling locally. If calling using HTTP, this should contain the ISAPI extension DLL name followed by the relative path to the database file, for example:

`isapiext.dll?path1\path2\db.its`

### `dwFlags` [in]

Currently not used.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The database was successfully opened. |
| **STG_E*** | [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface errors that can occur as storage is opened. |

## See also

[IITDatabase](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nn-infotech-iitdatabase)