# WDF_WMI_BUFFER_APPEND_STRING function

## Description

[Applies to KMDF only]

The **WDF_WMI_BUFFER_APPEND_STRING** function copies a specified Unicode string into a specified buffer in the format that WMI requires.

## Parameters

### `Buffer` [out]

A pointer to a destination buffer that receives the string.

### `BufferLength` [in]

The length, in bytes, of the destination buffer that receives the string.

### `String` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the string to be copied.

### `RequiredSize` [out]

A pointer to a location that receives the number of bytes that are required to store the specified string in the destination buffer.

## Return value

**WDF_WMI_BUFFER_APPEND_STRING** returns STATUS_SUCCESS if the operation succeeds. If the destination buffer is too small to hold the Unicode string that the *String* parameter specifies, the function returns STATUS_BUFFER_TOO_SMALL.

## Remarks

WMI requires that strings that an [EvtWmiInstanceQueryInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_query_instance) callback function returns be preceded by a byte count. The **WDF_WMI_BUFFER_APPEND_STRING** function calculates the byte count, stores it in the destination buffer, and then copies the string from the [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure into the destination buffer.

When **WDF_WMI_BUFFER_APPEND_STRING** returns, the location that the *RequiredSize* parameter points to contains the total number of bytes that were written to the buffer. To find the first buffer address that follows the string, your driver can pass the *RequiredSize* value to the WDF_PTR_ADD_OFFSET macro that is defined in *Wdfcore.h*.

#### Examples

The following code example is from the [Serial](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver. This example is an [EvtWmiInstanceQueryInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_query_instance) callback function that obtains a device's symbolic name and copies the name into the callback function's output buffer.

```cpp
NTSTATUS
EvtWmiQueryPortName(
    IN  WDFWMIINSTANCE WmiInstance,
    IN  ULONG OutBufferSize,
    IN  PVOID OutBuffer,
    OUT PULONG BufferUsed
    )
{
    WDFDEVICE device;
    PSERIAL_DEVICE_EXTENSION pDevExt;
    WCHAR pRegName[SYMBOLIC_NAME_LENGTH];
    UNICODE_STRING string;
    USHORT nameSize = sizeof(pRegName);
    NTSTATUS status;

    PAGED_CODE();

    device = WdfWmiInstanceGetDevice(WmiInstance);
    pDevExt = SerialGetDeviceExtension(device);

    status = SerialReadSymName(
                               device,
                               pRegName,
                               &nameSize
                               );
    if (!NT_SUCCESS(status)) {
        return status;
    }
    RtlInitUnicodeString(
                         &string,
                         pRegName
                         );
    return WDF_WMI_BUFFER_APPEND_STRING(
                                        OutBuffer,
                                        OutBufferSize,
                                        &string,
                                        BufferUsed
                                        );
}
```

## See also

[EvtWmiInstanceQueryInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_query_instance)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)