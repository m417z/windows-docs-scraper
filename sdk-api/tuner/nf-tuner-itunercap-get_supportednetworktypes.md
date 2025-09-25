# ITunerCap::get_SupportedNetworkTypes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **get_SupportedNetworkTypes** method retrieves a list of the network types that are supported by the TV tuner.

## Parameters

### `ulcNetworkTypesMax` [in]

The maximum number of network-type GUIDs that the *pguidNetworkTypes* buffer can hold.

### `pulcNetworkTypes` [out]

Receives a count of the number of network-type GUIDs actually written to the *pguidNetworkTypes* buffer.

### `pguidNetworkTypes` [in, out]

Receives an array of network-type GUIDs. For the list of valid network-type GUIDs, see [Default Tuning Spaces](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/default-tuning-spaces).

## Return value

When the method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## See also

[ITunerCap Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-itunercap)