# BITS_FILE_PROPERTY_VALUE structure

The **BITS_FILE_PROPERTY_VALUE** union provides the property value of the Delivery Optimization file based on a value from the [**BITS_FILE_PROPERTY_ID**](https://learn.microsoft.com/windows/win32/delivery_optimization/bits-file-property-id-) enumeration.

## Members

**String**

This value is used when using the property ID enum value **BITS_FILE_PROPERTY_ID_HTTP_RESPONSE_HEADERS**.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1709 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server, version 1709 \[desktop apps only\]<br> |
| Header<br> | Deliveryoptimization.h |

## See also

[**BITS_FILE_PROPERTY_ID**](https://learn.microsoft.com/windows/win32/delivery_optimization/bits-file-property-id-)

[**IBackgroundCopyFile5.GetProperty**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyfile5-getproperty)

[**IBackgroundCopyFile5.SetProperty**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyfile5-setproperty)

