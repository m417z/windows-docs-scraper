# WDF_PTR_ADD_OFFSET macro

The **WDF_PTR_ADD_OFFSET** macro adds an offset value to an address and returns the resulting address.

## Parameters

*_ptr*
Specifies an address.

*_offset*
Specifies the offset value in bytes.

## Return value

Returns a pointer to the resulting address.

## Remarks

This macro invokes [**WDF_PTR_ADD_OFFSET_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-ptr-add-offset-type) with the *_type* parameter set to PVOID.

The macro is defined as follows:

```ManagedCPlusPlus
#define WDF_PTR_ADD_OFFSET(_ptr, _offset) \
        WDF_PTR_ADD_OFFSET_TYPE(_ptr, _offset, PVOID)
```

Here is an example from the Toaster sample (toaster\\func\\featured\\wmi.c). In the example, the driver calls **WDF_PTR_ADD_OFFSET** to add an offset to an address to determine a destination buffer address to pass to the [**WDF_WMI_BUFFER_APPEND_STRING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdf_wmi_buffer_append_string) function.

```cpp
        //
        // Write the instance name
        //
        size -= wnodeSize;
        status = WDF_WMI_BUFFER_APPEND_STRING(
            WDF_PTR_ADD_OFFSET(wnode, wnode->OffsetInstanceName),
            size,
            &deviceName,
            &length
            );

        //
        // Size was precomputed, this should never fail
        //
        ASSERT(NT_SUCCESS(status));

        //
        // Write the data, which is the model name as a string
        //
        size -= wnodeInstanceNameSize;
        WDF_WMI_BUFFER_APPEND_STRING(
            WDF_PTR_ADD_OFFSET(wnode,  wnode->DataBlockOffset),
            size,
            &modelName,
            &length
            );
```

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356) |
| Minimum KMDF version | 1.5 |
| Minimum UMDF version | 2.0 |
| Header | Wdfcore.h (include Wdf.h) |