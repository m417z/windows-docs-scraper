# IBackgroundCopyJob::GetNotifyInterface

## Description

Retrieves the interface pointer to your implementation of the
[IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback) interface.

## Parameters

### `pVal` [out]

Interface pointer to your implementation of the
[IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback) interface. When done, release *ppNotifyInterface*.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Notification interface pointer was successfully retrieved. |
| **E_INVALIDARG** | Must pass the address of the *ppNotifyInterface* interface pointer. |

## See also

[IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback)

[IBackgroundCopyJob::GetNotifyFlags](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getnotifyflags)

[IBackgroundCopyJob::SetNotifyInterface](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setnotifyinterface)