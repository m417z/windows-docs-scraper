# IWbemConfigureRefresher::AddRefresher

## Description

The
**IWbemConfigureRefresher::AddRefresher** method adds a refresher to a refresher. The newly added refresher is called a "child refresher" or "nested refresher". You can use this method to create a single refresher containing more than one refresher that can be updated using a single call to the
[Refresh](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemrefresher-refresh) method.

## Parameters

### `pRefresher` [in]

Pointer to a
[IWbemRefresher](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemrefresher) object to nest in this refresher.

### `lFlags`

Reserved. This parameter must be 0 (zero).

### `plId` [out]

Pointer to an integer returned by the provider that uniquely identifies the refreshable object.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

Users should not add recursively nested refreshers. The returned identifier can be used by the
[Remove](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemconfigurerefresher-remove) function to remove the refresher. Although it is not necessary for the client to explicitly remove added refreshers, the client must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the refreshers when they are no longer required.

## See also

[Accessing Performance Data in C++](https://learn.microsoft.com/windows/desktop/WmiSdk/accessing-performance-data-in-c--)

[IWbemConfigureRefresher](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemconfigurerefresher)

[Making an Instance Provider into a High-Performance Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/making-an-instance-provider-into-a-high-performance-provider)

[Performance Counter Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/performance-counter-provider)