# MFCreateTopology function

## Description

Creates a topology object.

## Parameters

### `ppTopo`

Receives a pointer to the [IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology) interface of the topology object. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)