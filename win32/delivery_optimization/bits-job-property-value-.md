# BITS_JOB_PROPERTY_VALUE structure

The **BITS_JOB_PROPERTY_VALUE** union provides the property value of the Delivery Optimization job based on the value of the [**BITS_JOB_PROPERTY_ID**](https://learn.microsoft.com/windows/win32/delivery_optimization/bits-job-property-id) enumeration.

## Members

**Dword**

This value is returned when using the enum property ID **BITS_JOB_PROPERTY_ID_COST_FLAGS** and is applied as the [transfer policy](https://www.bing.com/search?q=transfer+policy) on the Delivery Optimization job.

**ClsID**

This value is returned when using the enum property ID **BITS_JOB_PROPERTY_NOTIFICATION_CLSID** and represents the CLSID of the callback object to register with the Delivery Optimization job.

**Enable**

Not supported.

**Uint64**

Not supported.

**Target**

Not supported.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1709 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server, version 1709 \[desktop apps only\]<br> |
| Header<br> | Deliveryoptimization.h |

## See also

[**BITS_JOB_PROPERTY_ID**](https://learn.microsoft.com/windows/win32/delivery_optimization/bits-job-property-id)

[**BITS_JOB_TRANSFER_POLICY**](https://learn.microsoft.com/windows/win32/delivery_optimization/bits-job-transfer-policy-)

