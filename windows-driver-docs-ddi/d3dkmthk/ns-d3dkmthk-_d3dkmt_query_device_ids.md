# D3DKMT_QUERY_DEVICE_IDS structure

## Description

The **D3DKMT_QUERY_DEVICE_IDS** structure is used to query for device IDs.

## Members

### `PhysicalAdapterIndex`

[in] The physical adapter index in the LDA (linked display adapter) chain.

### `DeviceIds`

[out] A [**D3DKMT_DEVICE_IDS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_device_ids) structure that contains IDs associated with the device.

## See also

[**D3DKMTQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)