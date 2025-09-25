## Description

Called by the system to allow clients to register to receive notification callbacks for APO endpoint and system effect notifications.

## Parameters

### `apoNotifications` [out]

Output parameter that returns a pointer to an array of [APO_NOTIFICATION_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/audioengineextensionapo/ns-audioengineextensionapo-apo_notification_descriptor) specifying the set of APO changes for which notifications are requested. The callee allocates the APO_NOTIFICATION_DESCRIPTOR structures using [CoTaskMemAlloc](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemalloc); the caller must release the structures by using [CoTaskMemFree](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree) when finished.

### `count` [out]

Output parameter specifying the number of items returned in *apoNotifications*.

## Return value

An HRESULT.

## Remarks

For more information on the Windows 11 APIs for the Audio Processing Objects (APOs) that can ship with audio drivers, see [Windows 11 APIs for Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-11-apis-for-audio-processing-objects).

## See also