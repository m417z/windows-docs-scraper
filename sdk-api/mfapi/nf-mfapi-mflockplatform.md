# MFLockPlatform function

## Description

Blocks the [MFShutdown](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfshutdown) function.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

This function prevents work queue threads from being shut down when [MFShutdown](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfshutdown) is called. Use this function to ensure that asynchronous operations complete gracefully before the platform shuts down.

This function holds a lock on the Media Foundation platform. To unlock the platform, call [MFUnlockPlatform](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfunlockplatform). The application must call **MFUnlockPlatform** once for every call to **MFLockPlatform**.

The [MFShutdown](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfshutdown) function blocks until the platform is unlocked, or until a fixed wait period has elapsed. (The wait period is a few seconds.) To avoid memory leaks, the application should unlock the platform before the wait period ends. For example, cancel any asynchronous operations that are waiting to complete and are holding a lock on the platform.

The default implementation of the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface automatically locks the Media Foundation platform when the result object is created. Releasing the interface unlocks the platform. Therefore, in most cases your application does not need to lock the platform directly. For more information, see [Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues).

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Foundation Platform APIs](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-platform-apis)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)