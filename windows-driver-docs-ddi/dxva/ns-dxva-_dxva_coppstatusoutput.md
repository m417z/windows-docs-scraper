# _DXVA_COPPStatusOutput structure

## Description

The DXVA_COPPStatusOutput structure describes the status returned from a query on a protected video session that is associated with a DirectX VA COPP device.

## Members

### `macKDI`

Specifies a message authentication code (MAC) GUID for the status at **COPPStatus**. The application that requested the status can use the MAC to verify that the transmission of the status was secure (that is, it was not tampered with in transit from the driver).

### `cbSizeData`

Specifies the size, in bytes, of the status data at **COPPStatus**.

### `COPPStatus`

Specifies an array that contains the status data. The display driver should return status data in one of the following ways, depending on the input value that was specified in the **guidStatusRequestID** member of the [DXVA_COPPStatusInput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppstatusinput) structure:

| ****Input value**** | ****Output status data**** |
|:--|:--|
| DXVA_COPPQueryDisplayData | Pointer to a [DXVA_COPPStatusDisplayData](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppstatusdisplaydata) structure |
| DXVA_COPPQueryProtectionType, DXVA_COPPQueryConnectorType, DXVA_COPPQueryLocalProtectionLevel, DXVA_COPPQueryGlobalProtectionLevel or DXVA_COPPQueryBusData| Pointer to a [DXVA_COPPStatusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppstatusdata) structure |
| DXVA_COPPQueryHDCPKeyData | Pointer to a [DXVA_COPPStatusHDCPKeyData](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppstatushdcpkeydata) structure |
| DXVA_COPPQuerySignaling | Pointer to a [DXVA_COPPStatusSignalingCmdData](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppstatussignalingcmddata) structure |

## Remarks

Status requests are passed in the *pInput* parameter of the [COPPQueryStatus](https://learn.microsoft.com/windows-hardware/drivers/display/coppquerystatus) function. The [DXVA_COPPStatusInput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppstatusinput) structure describes a request for status. Status information is returned through the *pOutput* parameter of *COPPQueryStatus*.

## See also

[COPPQueryStatus](https://learn.microsoft.com/windows-hardware/drivers/display/coppquerystatus)

[DXVA_COPPSetProtectionLevelCmdData](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppsetprotectionlevelcmddata)

[DXVA_COPPStatusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppstatusdata)

[DXVA_COPPStatusDisplayData](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppstatusdisplaydata)

[DXVA_COPPStatusHDCPKeyData](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppstatushdcpkeydata)

[DXVA_COPPStatusInput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppstatusinput)

[DXVA_COPPStatusSignalingCmdData](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_coppstatussignalingcmddata)