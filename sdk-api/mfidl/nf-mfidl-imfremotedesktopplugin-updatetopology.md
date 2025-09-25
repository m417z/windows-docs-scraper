# IMFRemoteDesktopPlugin::UpdateTopology

## Description

Modifies a topology for use in a Terminal Services environment.

## Parameters

### `pTopology` [in, out]

Pointer to the [IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology) interface of the topology.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If the application is running in a Terminal Services client session, call this method before calling [IMFMediaSession::SetTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-settopology) on the Media Session.

## See also

[IMFRemoteDesktopPlugin](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfremotedesktopplugin)