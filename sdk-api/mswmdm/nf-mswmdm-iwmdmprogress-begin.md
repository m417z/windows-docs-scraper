# IWMDMProgress::Begin

## Description

The **Begin** method indicates that an operation is beginning. An estimate of the duration of the operation is provided when possible.

## Parameters

### `dwEstimatedTicks` [in]

**DWORD** specifying the estimated number of ticks that are needed for the operation to complete.

## Return value

The application should return one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation should continue. |
| **WMDM_E_USER_CANCELLED** | Windows Media Device Manager should cancel the current operation without waiting for it to finish. If the application is using block mode, then Windows Media Device Manager will return this error to the application. |

## Remarks

This operation is called by various methods to indicate that an operation is beginning. The number of ticks passed in *dwEstimatedTicks* is an estimate of how many ticks are needed for the operation to complete. During the course of the operation, the [Progress](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress-progress) method is called to indicate how many ticks have transpired. Applications can use the estimate to configure display mechanisms that show progress.

The [IWMDMProgress3::Begin3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress3-begin3) method provides more information about what action is occurring.

#### Examples

The following C++ code is an implementation of the **Begin** method.

```cpp

HRESULT Begin(DWORD  dwEstimatedTicks)
{
    // TODO: Display the message: "IWMDMProgress::Begin called.: "
    // followed by the dwEstimatedTicks value.
    return S_OK;
}

```

## See also

[Enabling Notifications](https://learn.microsoft.com/windows/desktop/WMDM/enabling-notifications)

[IWMDMProgress Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress)

[IWMDMProgress3::Begin3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress3-begin3)