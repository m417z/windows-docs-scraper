## Description

The **WWAN_NR_NEIGHBOR_CELLS** structure represents the measured results list of neighboring NR cells.

## Members

### `ElementCount`

The count of neighbor cell entries following this element, with a maximum of 8 best NR or EUTRA neighbor cells.

### `NRNeighborCells`

The array of NR neighbor cell records, each specified as a [**WWAN_NR_NEIGHBOR_CELLS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_nr_neighbor_cells_info) structure.

## Remarks

## See also

[**WWAN_BASE_STATIONS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_base_stations_info)

[**WWAN_NR_NEIGHBOR_CELLS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_nr_neighbor_cells_info)

[**WWAN_NR_SERVING_CELLS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_nr_serving_cells)

[**WWAN_NR_SERVING_CELLS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_nr_serving_cells_info)