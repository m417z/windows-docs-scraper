# BITS_JOB_PROPERTY_ID enumeration

The **BITS_JOB_PROPERTY_ID** enumeration specifies the ID of the property for the Delivery Optimization job. This enumeration is used in the [**BITS_JOB_PROPERTY_VALUE**](https://learn.microsoft.com/windows/win32/delivery_optimization/bits-job-property-value-) union to determine the type of value contained in the union.

## Constants

**BITS_JOB_PROPERTY_ID_COST_FLAGS**

The ID that is used to [control transfer behavior](https://www.bing.com/search?q=control+transfer+behavior) over cellular and/or similar networks. This property may be changed while a transfer is ongoing the new cost flags will take effect immediately.

This property uses the **BITS_JOB_PROPERTY_VALUE** s **Dword** field.

**BITS_JOB_PROPERTY_NOTIFICATION_CLSID**

The ID that is used to [register a COM callback](https://www.bing.com/search?q=register+a+COM+callback) by CLSID to receive notifications about the progress and completion of a Delivery Optimization job. The CLSID must refer to a class associated with a registered out-of-process COM server. It may also be set to **GUID_NULL** to clear a previously set notification CLSID.

This property uses the **BITS_JOB_PROPERTY_VALUE** s **CLsID** field.

**BITS_JOB_PROPERTY_DYNAMIC_CONTENT**

Not supported.

**BITS_JOB_PROPERTY_HIGH_PERFORMANCE**

Not supported.

**BITS_JOB_PROPERTY_MAX_DOWNLOAD_SIZE**

Not supported.

**BITS_JOB_PROPERTY_USE_STORED_CREDENTIALS**

Not supported.

**BITS_JOB_PROPERTY_MINIMUM_NOTIFICATION_INTERVAL_MS**

Not supported.

**BITS_JOB_PROPERTY_ON_DEMAND_MODE**

Not supported.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1709 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server, version 1709 \[desktop apps only\]<br> |
| Header<br> | Deliveryoptimization.h |

## See also

[**BITS_JOB_PROPERTY_ID**](https://learn.microsoft.com/windows/win32/delivery_optimization/bits-job-property-id)

[**BITS_JOB_PROPERTY_VALUE**](https://learn.microsoft.com/windows/win32/delivery_optimization/bits-job-property-value-)

[**BITS_JOB_TRANSFER_POLICY**](https://learn.microsoft.com/windows/win32/delivery_optimization/bits-job-transfer-policy-)

[**IBackgroundCopyJob5::SetProperty**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob5-setproperty)

[**IBackgroundCopyJob5::GetProperty**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob5-getproperty)

