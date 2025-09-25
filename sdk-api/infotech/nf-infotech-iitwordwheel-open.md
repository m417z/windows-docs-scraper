# IITWordWheel::Open

## Description

Opens a word wheel.

## Parameters

### `lpITDB` [in]

Pointer to [database object](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nn-infotech-iitdatabase).

### `lpszMoniker` [in]

Name of word wheel.

### `dwFlags` [in]

One or more of the following values:

| Value | Meaning |
| --- | --- |
| **ITWW_OPEN_CONNECT** | **Note** If the word wheel resides on a remote computer, connect to the computer during this call to retrieve initialization data. Otherwise the connection is delayed until the first API call that requires this data. |

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The word wheel was successfully opened. |
| **E_ALREADYOPEN** | Word wheel is already open. |
| **E_INVALIDARG** | The [IITDatabase](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nn-infotech-iitdatabase)* interface or *lpszMoniker* parameter was NULL. |
| **STG_E*** | [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) interface errors that can occur as storage is opened. |

## See also

[IITWordWheel](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nn-infotech-iitwordwheel)