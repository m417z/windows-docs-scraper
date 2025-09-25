# IDARG_IN_ADAPTER_INIT structure

## Description

The **IDARG_IN_ADAPTER_INIT** structure contains the information needed to initialize an adapter that will be hosted on a Windows Driver Framework (WDF) device.

## Members

### `WdfDevice`

The WDF object representing the device that will be hosting this WDDM adapter object.

### `pCaps`

Pointer to an [**IDDCX_ADAPTER_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_adapter_caps) structure containing information about the capabilities of the adapter.

### `ObjectAttributes`

Pointer to a [**WDF_OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure containing object attributes used to initialize the WDF adapter object.

## Remarks

For more information about WDF objects, see [Introduction to Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/introduction-to-framework-objects).

## See also

[**IDARG_OUT_ADAPTER_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_adapter_init)

[**IDDCX_ADAPTER_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_adapter_caps)

[**IddCxAdapterInitAsync**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterinitasync)

[**WDF_OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)