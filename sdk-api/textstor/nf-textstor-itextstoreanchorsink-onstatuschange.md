# ITextStoreAnchorSink::OnStatusChange

## Description

Called when the text stream status changes.

## Parameters

### `dwFlags` [in]

Contains a value that specifies the new status. For more information about possible values, see the **dwDynamicFlags** member of the [TS_STATUS](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_status) structure.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

Applications should call this method whenever [ITextStoreAnchor::GetStatus](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-getstatus) returns a new value for any of the **dwDynamicFlags** member of **TS_STATUS** .

## See also

[ITextStoreAnchor::GetStatus](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-getstatus)

[ITextStoreAnchorSink](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchorsink)

[TS_STATUS](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_status)