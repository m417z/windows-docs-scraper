# MFUnlockPlatform function

## Description

Unlocks the Media Foundation platform after it was locked by a call to the [MFLockPlatform](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mflockplatform) function.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

The application must call **MFUnlockPlatform** once for every call to [MFLockPlatform](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mflockplatform).

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Foundation Platform APIs](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-platform-apis)

[Work Queues](https://learn.microsoft.com/windows/desktop/medfound/work-queues)