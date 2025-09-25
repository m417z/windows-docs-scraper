## Description

The **WWAN_NR_SERVING_CELLS** structure represents the measured results list of 5G NR serving cells.

## Members

### `ElementCount`

The count of NR serving cell entries following this element, with a maximum of 32 NR serving cells.

### `NRServingCells`

The array of NR serving cell records, each specified as a [**WWAN_NR_SERVING_CELLS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_nr_serving_cells_info) structure.

## Remarks

## See also

[**WWAN_BASE_STATIONS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_base_stations_info)

[**WWAN_NR_SERVING_CELLS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_nr_serving_cells_info)

[**WWAN_NR_NEIGHBOR_CELLS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_nr_neighbor_cells_info)

[**WWAN_NR_NEIGHBOR_CELLS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_nr_neighbor_cells)