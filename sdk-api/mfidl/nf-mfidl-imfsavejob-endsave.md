# IMFSaveJob::EndSave

## Description

Completes the operation started by [IMFSaveJob::BeginSave](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsavejob-beginsave).

## Parameters

### `pResult` [in]

Pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface. Pass in the same pointer that your callback object received in the [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFSaveJob](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsavejob)