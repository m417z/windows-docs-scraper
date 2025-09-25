# _IRB_REQ_GET_LOCAL_HOST_INFORMATION structure

## Description

This structure contains the fields necessary for the 1394 bus driver to carry out a GetLocalHostInformation request.

## Members

### `nLevel`

Specifies what level of information is desired from this call. The following flags are provided.

| Flag | Description |
| --- | --- |
| GET_HOST_UNIQUE_ID | Requests the port driver to return the 64-bit unique identifier. |
| GET_HOST_CAPABILITIES | Requests the port driver to return the host controller's capability flags. |
| GET_HOST_DDI_VERSION | Requests the DDI version of the 1394 bus driver. |
| GET_POWER_SUPPLIED | Requests the port driver to return the power characteristics of the bus. |
| GET_PHYS_ADDR_ROUTINE | Requests the port driver to return the host controller's physical address mapping function. |
| GET_HOST_CONFIG_ROM | Requests the port driver to return the host controller's configuration ROM. |
| GET_HOST_CSR_CONTENTS | Requests the port driver to return the speed or topology maps from the host controller's CSR. See the IEEE 1394 Specification for a description of CSRs.<br><br>**Note** In Windows 7, setting **nLevel** to GET_HOST_CSR_CONTENTS and specifying the SPEED_MAP_LOCATION as **CsrBaseAddress** is not supported. The speed map is obsolete in the IEEE-1394a specification. |
| GET_HOST_DMA_CAPABILITIES | Requests the port driver to return the host controller's capability flags and the size of the DMA buffer (PAGESIZE multiplied by the number of mapping registers). |

### `Information`

Points to an information block to be filled in, depending on what level of information is desired. Each block has its own particular structure.

| Flag | Structure |
| --- | --- |
| GET_HOST_UNIQUE_ID | [GET_LOCAL_HOST_INFO1](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_get_local_host_info1) |
| GET_HOST_CAPABILITIES | [GET_LOCAL_HOST_INFO2](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_get_local_host_info2) |
| GET_POWER_SUPPLIED | [GET_LOCAL_HOST_INFO3](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_get_local_host_info3) |
| GET_PHYS_ADDR_ROUTINE | [GET_LOCAL_HOST_INFO4](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_get_local_host_info4) |
| GET_HOST_CONFIG_ROM | [GET_LOCAL_HOST_INFO5](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_get_local_host_info5) |
| GET_HOST_CSR_CONTENTS | [GET_LOCAL_HOST_INFO6](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_get_local_host_info6) |
| GET_HOST_DMA_CAPABILITIES | [GET_LOCAL_HOST_INFO7](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_get_local_host_info7_w2k) |
| GET_HOST_DDI_VERSION | [GET_LOCAL_HOST_INFO8](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_get_local_host_info8) |