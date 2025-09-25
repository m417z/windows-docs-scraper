# ISyncMgrSynchronizeCallback::LogError

## Description

Called by a registered application to log information, warning, or an error message into the error tab on the synchronization manager status dialog box.

## Parameters

### `dwErrorLevel` [in]

Type: **DWORD**

The error level. Values are taken from the [SYNCMGRLOGLEVEL](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrloglevel) enumeration.

### `pszErrorText` [in]

Type: **LPCWSTR**

A pointer to error text to be displayed in the error tab.

### `pSyncLogError` [in]

Type: **const [SYNCMGRLOGERRORINFO](https://learn.microsoft.com/windows/desktop/api/mobsync/ns-mobsync-syncmgrlogerrorinfo)***

A pointer to the [SYNCMGRLOGERRORINFO](https://learn.microsoft.com/windows/desktop/api/mobsync/ns-mobsync-syncmgrlogerrorinfo) structure that contains additional error information. Registered applications that do not provide this data can pass **NULL**.

## Return value

Type: **HRESULT**

This method supports the standard return values E_INVALIDARG, E_UNEXPECTED, and E_OUTOFMEMORY, and the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The error information is logged successfully. |

## See also

[ISyncMgrSynchronizeCallback](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronizecallback)

[SYNCMGRLOGERRORINFO](https://learn.microsoft.com/windows/desktop/api/mobsync/ns-mobsync-syncmgrlogerrorinfo)

[SYNCMGRLOGLEVEL](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrloglevel)