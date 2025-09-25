# ITextStoreACPSink::OnStatusChange

## Description

Called when the status of the document changes.

## Parameters

### `dwFlags` [in]

Contains a value that specifies the new status. For more information about possible values, see the **dwDynamicFlags** member of the [TS_STATUS](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_status) structure.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[ITextStoreACPSink](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacpsink)

[TS_STATUS](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_status)