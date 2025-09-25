## Description

The OS calls **EVT_IDD_CX_PARSE_MONITOR_DESCRIPTION2** to ask the driver to parse a monitor description into a list of modes that the monitor supports. The OS calls this callback version (instead of **EVT_IDD_CX_PARSE_MONITOR_DESCRIPTION**) to allow the driver to report extra information needed for HDR10 or WCG monitor modes.

## Parameters

### `pInArgs`

[in] Pointer to an [**IDARG_IN_PARSEMONITORDESCRIPTION2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_parsemonitordescription2) structure that contains the input arguments for this callback function.

### `pOutArgs`

[out] Pointer to an [**IDARG_OUT_PARSEMONITORDESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_parsemonitordescription) structure that contains the output arguments for this callback function.

## Return value

**EVT_IDD_CX_PARSE_MONITOR_DESCRIPTION2** returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value. If the operation is successful, it returns STATUS_SUCCESS or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

A version 1.10 or later indirect display driver that supports HDR must expose this function to report modes. Setting the following [**IDDCX_WIRE_BITS_PER_COMPONENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_wire_bits_per_component) values is equivalent to creating a mode via the pre-1.10 functions:

* **BitsPerComponent.Rgb** to [**IDDCX_BITS_PER_COMPONENT_8**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_bits_per_component)
* **BitsPerComponent.YCbCr444**, **BitsPerComponent.YCbCr422** and **BitsPerComponent.YCbCr420** to **IDDCX_BITS_PER_COMPONENT_NONE**

Version 1.10 and later drivers that don't set the [**IDDCX_ADAPTER_FLAGS_CAN_PROCESS_FP16**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_adapter_flags) adapter flag can continue to report only the pre-1.10 function.

The [**IDDCX_MONITOR_MODE2::BitsPerComponent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_monitor_mode2) field is designed to allow multiple formats and bit depths to be reported in a single mode. For example, a driver can report 8 and 10 bits per component in RGB by setting both **IDDCX_BITS_PER_COMPONENT_8** and **IDDCX_BITS_PER_COMPONENT_10** in **IDDCX_MONITOR_MODE2::BitsPerComponent::Rgb**. A driver should only report different bits per component as unique modes if other mode details also differ.

Drivers returning modes with SDR WCG or HDR parameters will fail if they have not also reported [**IDDCX_ADAPTER_FLAGS_CAN_PROCESS_FP16**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_adapter_flags) in the [**IddCxAdapterInitAsync**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterinitasync) call. SDR WCG and HDR parameters can be:

* Any value for **IDDCX_WIRE_BITS_PER_COMPONENT::BitsPerComponent.Rgb** other than **IDDCX_BITS_PER_COMPONENT_8**, or
* Any **IDDCX_WIRE_BITS_PER_COMPONENT::BitsPerComponent** value for **YCbCr444**, **YCbCr422**, or **YCbCr420** other than **IDDCX_BITS_PER_COMPONENT_NONE**.

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**IDARG_IN_PARSEMONITORDESCRIPTION2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_parsemonitordescription2)

[**IDARG_OUT_PARSEMONITORDESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_parsemonitordescription)