# IWMDMProgress::Progress

## Description

The **Progress** method indicates that an operation is still in progress.

## Parameters

### `dwTranspiredTicks` [in]

**DWORD** specifying the number of ticks that have transpired so far.

## Return value

The application should return one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation should continue. |
| **WMDM_E_USER_CANCELLED** | Windows Media Device Manager should cancel the current operation without waiting for it to finish. If the application is using block mode, then Windows Media Device Manager will return this error to the application. |

## Remarks

This method is called by all other Windows Media Device Manager methods. The intention is that **Progress** will be called once per estimated tick. However, the *dwTranspiredTicks* parameter must be checked on each call because the operation being performed may not guarantee a call once for each estimated tick.

The application returns S_OK to the calling method to indicate that the operation should continue. The application returns WMDM_E_USER_CANCELLED to indicate that the operation should be cancelled. If the application is using block mode and returns WMDM_E_USER_CANCELLED, then Windows Media Device Manager will return this same error to the application.

#### Examples

The following C++ code is a simple implementation of the **Progress** method.

```cpp

HRESULT Progress(DWORD  dwTranspiredTicks)
{
    // TODO: Display the message: "IWMDMProgress::Progress called"
    // followed by the dwTranspiredTicks value.
    return S_OK;
}

```

## See also

[Enabling Notifications](https://learn.microsoft.com/windows/desktop/WMDM/enabling-notifications)

[IWMDMProgress Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress)

[IWMDMProgress3::Progress3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress3-progress3)