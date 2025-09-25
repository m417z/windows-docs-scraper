# WdfWmiInstanceFireEvent function

## Description

[Applies to KMDF only]

The **WdfWmiInstanceFireEvent** method sends a WMI event to WMI clients that have registered to receive event notification.

## Parameters

### `WmiInstance` [in]

A handle to a WMI instance object that the driver obtained from a previous call to [WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate).

### `EventDataSize` [in, optional]

The size, in bytes, of the event data that *EventData* points to.

### `EventData` [in, optional]

A pointer to the event data, or **NULL** if there is no event data.

## Return value

**WdfWmiInstanceFireEvent** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory. |
| **STATUS_UNSUCCESSFUL** | The framework's attempt to communicate with WMI failed. |
| **STATUS_BUFFER_OVERFLOW** | The event data buffer was too large. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Your driver should call **WdfWmiInstanceFireEvent** only if a WMI client has registered for event notification. The driver can determine if it should call **WdfWmiInstanceFireEvent** by providing an [EvtWmiProviderFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_provider_function_control) callback function or calling [WdfWmiProviderIsEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiproviderisenabled).

The driver should place its event-specific data, if any, in the buffer that the *EventData* parameter points to. The framework adds all of the necessary WMI header information.

For more information about the **WdfWmiInstanceFireEvent** method, see [Supporting WMI in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-wmi-in-kmdf-drivers).

#### Examples

The following code example sends a WMI event to WMI clients.

```cpp
MY_WMI_EVENT_DATA eventData;
NTSTATUS  status;

status = WdfWmiInstanceFireEvent(
                                 WmiInstance,
                                 sizeof(eventData),
                                 (PVOID)&eventData
                                 );
```

## See also

[EvtWmiProviderFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_provider_function_control)

[WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate)

[WdfWmiProviderIsEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiproviderisenabled)