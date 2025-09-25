# _DXGKARG_HISTORYBUFFERPRECISION structure

## Description

Indicates info about the precision of history buffer data used by the display miniport driver.

## Members

### `PrecisionBits`

The number of valid bits that are used in each time stamp. This number doesn't include bits used for junk values.

This precision value has three valid ranges:

| **Value** | **Meaning** |
|:--|:--|
| 0 | No bits contain useful data, and the DirectX graphics kernel subsystem will call the [DxgkDdiFormatHistoryBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_formathistorybuffer) function to provide valid data to output to the Event Tracing for Windows (ETW) facility. When the driver processes this call, it sets a new precision value as the output parameter of the function. |
| 32 | The driver should log 32-bit time stamps using the full 32 bits of precision. |
| 33–64 | The driver should log 64-bit time stamps. This value defines the number of bits used to store data per time stamp.<br>To reduce the cost of formatting the data, the driver can include junk values in the 64-bit time stamps. For example, the driver could write 64-bit time stamps with 55 valid bits of precision. In this case the upper 9 bits are considered junk values and are stripped off by ETW. |

Values between 0 and 32 are unsupported and invalid.

If the hardware supports 64-bit time stamps but only 32 bits are usable, the driver must ensure that the data is presented correctly to the DirectX graphics kernel subsystem. If the driver has no other alternatives to present the data, it should provide the precision value when the [DxgkDdiFormatHistoryBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_formathistorybuffer) function is next called.

## Remarks

In a call to the [DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function, the output data size, [DXGKARG_QUERYADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo).**OutputDataSize**, is:

```cpp
sizeof(DXGKARG_HISTORYBUFFERPRECISION) * m_DriverCaps.GpuEngineTopology.NbAsymetricProcessingNodes
```

## See also

[DXGKARG_QUERYADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo)

[DxgkDdiFormatHistoryBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_formathistorybuffer)

[DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)