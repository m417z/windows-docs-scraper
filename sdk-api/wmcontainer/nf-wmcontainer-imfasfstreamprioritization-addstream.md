# IMFASFStreamPrioritization::AddStream

## Description

**Note** This interface is not implemented in this version of Media Foundation.

Adds a stream to the stream priority list.

## Parameters

### `wStreamNumber` [in]

Stream number of the stream to add.

### `wStreamFlags` [in]

If **TRUE**, the stream is mandatory.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDREQUEST** | Invalid stream number. |

## Remarks

The stream priority list is built by appending entries to the list with each call to **AddStream**. The list is evaluated in descending order of importance. The most important stream should be added first, and the least important should be added last.

## See also

[IMFASFStreamPrioritization](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamprioritization)