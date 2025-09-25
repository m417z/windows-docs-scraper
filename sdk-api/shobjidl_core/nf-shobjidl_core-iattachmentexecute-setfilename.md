# IAttachmentExecute::SetFileName

## Description

Specifies and stores the proposed name of the file.

## Parameters

### `pszFileName` [in]

Type: **LPCWSTR**

A pointer to a string that contains the file name.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code, including the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *pszFileName* value is is set to **NULL**, points to an empty string, or points to a file name longer than **MAX_PATH**. |
| **E_UNEXPECTED** | The file name cannot be stored. |

## Remarks

No path information should be included at *pszFileName*, just the file's name.

**IAttachmentExecute::SetFileName** can be used by the calling application to check the validity of the file name before copying the file locally. The file name is checked for name collisions against other files stored at the local path location.

**IAttachmentExecute::SetFileName** is optional.

## See also

[IAttachmentExecute](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iattachmentexecute)

[IAttachmentExecute::SetLocalPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iattachmentexecute-setlocalpath)