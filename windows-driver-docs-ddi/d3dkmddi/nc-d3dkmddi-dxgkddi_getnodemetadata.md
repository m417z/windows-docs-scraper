# DXGKDDI_GETNODEMETADATA callback function

## Description

From a provided adapter handle, **DXGKDDI_GETNODEMETADATA** returns the metadata of an engine on a specified GPU node.

## Parameters

### `hAdapter` [in]

[in] A handle that identifies a display adapter. *Dxgkrnl* previously provided this handle to the display miniport driver (KMD) in the **DxgkInterface** parameter of the [**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device) function.

### `NodeOrdinalAndAdapterIndex`

[in] An index of a node for which engine information is obtained. This node is within the physical adapter defined by the **hAdapter** parameter.

### `pGetNodeMetadata`

[out] Pointer to a [**DXGKARG_GETNODEMETADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_nodemetadata) structure in which KMD returns the metadata of the engine specified by **NodeOrdinal**.

Note that the **DXGKARG_GETNODEMETADATA** structure is declared as a [**DXGK_NODEMETADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_nodemetadata) structure.

## Return value

Returns one of the following values:

| Return code | Description |
| ----------- | ----------- |
| **STATUS_SUCCESS** | **DxgkDdiGetNodeMetadata** successfully retrieved the engine information. |
| **STATUS_INVALID_PARAMETER** | The **hAdapter** or **pGetNodeMetadata** parameter is invalid, or **NodeOrdinal** is greater than or equal to the number of nodes on the adapter. |

If the **hAdapter** and **pGetNodeMetadata** parameters are valid, and **NodeOrdinal** has a value in the range of 0 to (*number of nodes* - 1), all calls to this function must be successful.

## Remarks

KMD sets the bits for every feature that the specified GPU node supports. The OS allows UMD to use only those metadata capabilities that KMD reports support for.

WDDM 1.3 and later display miniport drivers (KMDs) must implement **DXGKDDI_GETNODEMETADATA**.

For more information on how to implement this function, see [Enumerating GPU engine capabilities](https://learn.microsoft.com/windows-hardware/drivers/display/enumerating-gpu-nodes).

## See also

[**DXGK_NODEMETADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_nodemetadata)

[**DxgkDdiStartDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)