# SetSocketMediaStreamingMode function

## Description

The
**SetSocketMediaStreamingMode** function indicates whether the network is to be used for transferring streaming media that requires quality of service.

## Parameters

### `value`

Indicates whether the network is to be used for transferring streaming media that requires quality of service. This ensures that sockets opened as low latency will get the right quality of service over 802.11 wireless networks.

## Return value

If no error occurs,
**SetSocketMediaStreamingMode** returns S_OK. Otherwise, an error code is returned as an HRESULT.

## Remarks

The
**SetSocketMediaStreamingMode** function is used to indicate whether the network is to be used for transferring streaming media that requires quality of service. This function is normally used by Voice over IP (VoIP) or similar apps that require a consistent quality of service. The **SetSocketMediaStreamingMode** function can be used by Windows Store apps or desktop apps.

There can be quality of service issues for media streaming when used over an 802.11 wireless network. The 802.11 network driver will periodically scan for other nearby infrastructure networks (ESS) or ad-hoc networks (IBSS). This allows the wireless network adapter to find other networks and possibly connected to a network with a stronger signal. Most current 802.11 network drivers scan all of the available channels as a series at once. When the 802.11 network driver is scanning for other networks and listening on other channels, it cannot receive packets for the app. The time spent scanning for other networks can introduce a noticeable gap (100 milliseconds or more) when a VoIP app would be unable to receive the audio stream. This scanning process is longer for 802.11 network adapters that are dual band (2.4GHz and 5GHz) since even more channels are scanned. This can result in the audio to be perceived as stuttering.

When the **SetSocketMediaStreamingMode** function is called with the *value* parameter set to **TRUE** and the socket will be transferring over an 802.11 wireless network adapter, the system will notify the wireless network driver to stop scanning for other networks. This eliminates stuttering by VoIP and similar audio apps when used over 802.11 wireless networks, but also affects any apps running on the local computer or device.

There are cases where turning off scans may cause problems. When scans are disabled, the local computer stays connected to the same network even if the signal becomes weaker and weaker as the user moves away from the network.

A VoIP or similar app should close all low latency sockets to restore the media streaming mode of the 802.11 wireless network driver. This will re-enable scanning for other wireless networks.

The **SetSocketMediaStreamingMode** function has no effect if the socket will not be sending or receiving packets over an 802.11 wireless adapter.

## See also

[Adding support for networking](https://learn.microsoft.com/previous-versions/windows/apps/hh452752(v=win.10))

[Windows.Networking.BackgroundTransfer](https://learn.microsoft.com/uwp/api/windows.networking.backgroundtransfer)

[Windows.Networking.Sockets](https://learn.microsoft.com/uwp/api/windows.networking.sockets)