# IMFSourceOpenMonitor::OnSourceEvent

## Description

Called by the network source when the open operation begins or ends.

## Parameters

### `pEvent` [in]

Pointer to the [IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The networks source calls this method with the following event types.

* [MEConnectStart](https://learn.microsoft.com/windows/desktop/medfound/meconnectstart)
* [MEConnectEnd](https://learn.microsoft.com/windows/desktop/medfound/meconnectend)

For more information, see [How to Get Events from the Network Source](https://learn.microsoft.com/windows/desktop/medfound/how-to-get-events-from-the-network-source).

## See also

[IMFSourceOpenMonitor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsourceopenmonitor)