# ITextStoreACP::RequestLock

## Description

The **ITextStoreACP::RequestLock** method is called by the TSF manager to provide a document lock in order to modify the document. This method calls the [ITextStoreACPSink::OnLockGranted](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacpsink-onlockgranted) method to create the document lock.

## Parameters

### `dwLockFlags` [in]

Specifies the type of lock requested.

| Value | Meaning |
| --- | --- |
| **TS_LF_READ** | The document has a read-only lock and cannot be modified. |
| **TS_LF_READWRITE** | The document has a read/write lock and can be modified. |
| **TS_LF_SYNC** | The document has a synchronous-lock if this flag is combined with other flags. |

### `phrSession` [out]

If the lock request is synchronous, receives an HRESULT value from the [ITextStoreAnchorSink::OnLockGranted](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchorsink-onlockgranted) method that specifies the result of the lock request.

If the lock request is asynchronous and the result is [TS_S_ASYNC](https://learn.microsoft.com/windows/desktop/TSF/text-store-return-values), the document receives an asynchronous lock. If the lock request is asynchronous and the result is TS_E_SYNCHRONOUS, the document cannot be locked synchronously.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

This method uses the **ITextStoreACPSink::OnLockGranted** method to lock the document. Applications must never modify the document or send change notifications using the [ITextStoreACPSink::OnTextChange](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacpsink-ontextchange) method from within the **ITextStoreACP::RequestLock** method. If the application has pending changes to report, the application can only respond to the asynchronous lock request.

Applications should not attempt to queue multiple **ITextStoreACP::RequestLock** method calls, because the application requires only a single callback. If the caller makes several read requests and one or more write requests, however, the callback should be for write access.

Successful requests for synchronous locks supersede requests for asynchronous locks. Unsuccessful requests for synchronous locks do not supersede requests for asynchronous locks. The implementation must still serve the outstanding asynchronous request, if one exists.

If the lock is granted before the **ITextStoreACP::RequestLock** method returns, the *phrSession* parameter will receive the HRESULT returned by the **ITextStoreACPSink::OnLockGranted** method. If the call is successful, but the lock will be granted later, the *phrSession* parameter receives the TS_S_ASYNC flag. The *phrSession* parameter should be ignored if **ITextStoreACP::RequestLock** returns anything other than S_OK.

A caller should never call this method reentrantly, except in the case that the caller holds a read-only lock. In this case the method can be called reentrantly to ask for an asynchronous write lock. The write lock will be granted later, after the read-only lock ends.

For more information about document locks, see [Document Locks](https://learn.microsoft.com/windows/desktop/TSF/document-locks).

## See also

[Document Locks](https://learn.microsoft.com/windows/desktop/TSF/document-locks)

[ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp)

[ITextStoreACPSink::OnLockGranted](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacpsink-onlockgranted)

[TS_LF_* Constants](https://learn.microsoft.com/windows/desktop/TSF/ts-lf--constants)

[Text Store Return Values](https://learn.microsoft.com/windows/desktop/TSF/text-store-return-values)