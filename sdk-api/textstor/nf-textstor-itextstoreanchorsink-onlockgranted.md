# ITextStoreAnchorSink::OnLockGranted

## Description

Called to grant a document lock.

## Parameters

### `dwLockFlags` [in]

Contains a set of flags that identify the type of lock requested and other lock request data. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **TS_LF_READ** | The lock is read-only. |
| **TS_LF_READWRITE** | The lock is read/write. |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *dwLockFlags* is invalid. |
| **E_UNEXPECTED** | The wrong type of lock was granted. |

## Remarks

A document lock is requested by calling [ITextStoreAnchor::RequestLock](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-requestlock). The application grants the lock request by calling **ITextStoreAnchorSink::OnLockGranted** with the requested lock type. The lock is only valid during the **OnLockGranted** call. When **OnLockGranted** returns, the document is considered unlocked.

The lock type, specified in *dwLockFlags*, must match the requested lock type in the corresponding call to **ITextStoreAnchor::RequestLock**.

Calls to **ITextStoreAnchor::RequestLock** from within **OnLockGranted** will return an error value.

Applications must not call any of the [ITextStoreAnchorSink](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchorsink) methods from within the context of **OnLockGranted**.

If a synchronous lock request is made from within **ITextStoreAnchor::RequestLock**, then the caller must also provide the return value from **ITextStoreAnchor::RequestLock**.

## See also

[Document Locks](https://learn.microsoft.com/windows/desktop/TSF/document-locks)

[ITextStoreAnchor::RequestLock](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-requestlock)

[ITextStoreAnchorSink](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchorsink)

[TS_LF_* Constants](https://learn.microsoft.com/windows/desktop/TSF/ts-lf--constants)