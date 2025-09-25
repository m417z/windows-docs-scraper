## Description

Defines constants that specify types of notifications raised by [IDXCoreAdapter](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nn-dxcore_interface-idxcoreadapter) or [IDXCoreAdapterList](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nn-dxcore_interface-idxcoreadapterlist) objects.

You can register and unregister for these notifications by calling [IDXCoreAdapterFactory::RegisterEventNotification](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapterfactory-registereventnotification) and [IDXCoreAdapterFactory::UnregisterEventNotification](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapterfactory-unregistereventnotification), respectively.

## Constants

### `AdapterListStale:0`

This notification is raised by an [IDXCoreAdapterList](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nn-dxcore_interface-idxcoreadapterlist) object when the adapter list becomes stale. The fresh-to-stale transition is one-way, and one-time, so this notification is raised at most one time.

### `AdapterNoLongerValid:1`

This notification is raised by an [IDXCoreAdapter](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nn-dxcore_interface-idxcoreadapter) object when the adapter becomes no longer valid. The valid-to-invalid transition is one-way, and one-time, so this notification is raised at most one time.

### `AdapterBudgetChange:2`

This notification is raised by an [IDXCoreAdapter](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nn-dxcore_interface-idxcoreadapter) object when an adapter budget change occurs. This notification can occur many times. Using this notification is functionally similar to [IDXGIAdapter3::RegisterVideoMemoryBudgetChangeNotificationEvent](https://learn.microsoft.com/windows/win32/api/dxgi1_4/nf-dxgi1_4-idxgiadapter3-registervideomemorybudgetchangenotificationevent). In response to this event, you should call [IDXCoreAdapter::QueryState](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapter-querystate) (with [DXCoreAdapterState::AdapterMemoryBudget](https://learn.microsoft.com/windows/win32/api/dxcore_interface/ne-dxcore_interface-dxcoreadapterstate)) to evaluate the current memory budget state.

### `AdapterHardwareContentProtectionTeardown:3`

This notification is raised by an [IDXCoreAdapter](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nn-dxcore_interface-idxcoreadapter) object to notify of an adapter's hardware content protection teardown. This notification can occur many times. It is functionally similar to [IDXGIAdapter3::RegisterHardwareContentProtectionTeardownStatusEvent](https://learn.microsoft.com/windows/win32/api/dxgi1_4/nf-dxgi1_4-idxgiadapter3-registerhardwarecontentprotectionteardownstatusevent). In response to this event, you should re-evaluate the current crypto session status; for example, by calling [ID3D11VideoContext1::CheckCryptoSessionStatus](https://learn.microsoft.com/windows/win32/api/d3d11_1/nf-d3d11_1-id3d11videocontext1-checkcryptosessionstatus) to determine the impact of the hardware teardown for a specific [ID3D11CryptoSession](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11cryptosession) interface.

## See also

[IDXCoreAdapterFactory::RegisterEventNotification](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapterfactory-registereventnotification), [IDXCoreAdapterFactory::UnregisterEventNotification](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapterfactory-unregistereventnotification), [IDXCoreAdapter](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nn-dxcore_interface-idxcoreadapter), [IDXCoreAdapterList](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nn-dxcore_interface-idxcoreadapterlist), [DXCore reference](https://learn.microsoft.com/windows/win32/dxcore/dxcore-reference), [Using DXCore to enumerate adapters](https://learn.microsoft.com/windows/win32/dxcore/dxcore-enum-adapters)