# NPDirectoryNotify function

## Description

 Notifies the network provider of certain directory operations. The **NPDirectoryNotify** function is used by File Manager. This function can be used to perform special operations on certain directories.

## Parameters

### `hwnd` [in]

A handle to a window that should own any messages or dialog boxes in the event the network provider needs to interact with the user.

### `lpDir` [in]

Pointer to the fully qualified name of the directory.

### `dwOper` [in]

Indicates the operation about to be performed. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **WNDN_MKDIR** | File Manager is about to create a directory with the given name. |
| **WNDN_RMDIR** | File Manager is about to remove the directory. |
| **WNDN_MVDIR** | File Manager is about to rename the directory. |

## Return value

This function should return WN_SUCCESS if it is successful. This indicates to the caller that it should continue and perform the operation. Otherwise, it should return the appropriate code, which may include:

| Return code | Description |
| --- | --- |
| **WN_CANCEL** | The provider would have handled the operation, but the user canceled it. The caller should not perform the operation. |
| **ERROR_CONTINUE** | The network provider has already handled the operation. The caller should proceed normally but should not perform the operation. |
| **WN_NOT_SUPPORTED** | The network does not have special directory handling. This is treated as WN_SUCCESS. |