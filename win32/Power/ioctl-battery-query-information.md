# IOCTL\_BATTERY\_QUERY\_INFORMATION control code

Retrieves a variety of information for the battery.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```C++
BOOL DeviceIoControl(
  (HANDLE) hDevice,                // handle to battery
  IOCTL_BATTERY_QUERY_INFORMATION, // dwIoControlCode
  (LPVOID) lpInBuffer,             // input buffer
  (DWORD) nInBufferSize,           // size of input buffer
  (LPVOID) lpOutBuffer,            // output buffer
  (DWORD) nOutBufferSize,          // size of output buffer
  (LPDWORD) lpBytesReturned,       // number of bytes returned
  (LPOVERLAPPED) lpOverlapped      // OVERLAPPED structure
);
```

## Parameters

*hDevice*

A handle to the battery on which information is to be returned. To retrieve a device handle, call the [**CreateFile**](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

*dwIoControlCode*

The control code for the operation. This value identifies the specific operation to be performed and the type of device on which to perform it. Use **IOCTL\_BATTERY\_QUERY\_INFORMATION** for this operation.

*lpInBuffer*

A pointer to a [**BATTERY\_QUERY\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/battery-query-information-str) structure.

*nInBufferSize*

The size of the input buffer, in bytes.

*lpOutBuffer*

A pointer to the return buffer. The data type (and, therefore, size) of the return buffer depends on the information requested in the **BATTERY\_QUERY\_INFORMATION\_LEVEL** member of the input [**BATTERY\_QUERY\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/battery-query-information-str) structure.

The following table shows the data returned by a given information level.

| Information level | Data returned |
|-----------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **BatteryDeviceName** | **Null**-terminated Unicode string that specifies the battery's name. |
| **BatteryEstimatedTime** | A **ULONG** that specifies estimated battery run time, in seconds. If the rate of drain provided in the **AtRate** member of the [**BATTERY\_QUERY\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/battery-query-information-str) structure is zero, this calculation is based on the present rate of drain. If **AtRate** is nonzero, the time returned is the expected run time for the given rate. If the estimated time is unknown (for example, the battery is not discharging and **AtRate** is zero), **BATTERY\_UNKNOWN\_TIME** is returned. Note that this value is not very accurate on some battery systems. The value may vary widely depending on present power usage, which could be affected by disk activity and other factors. There is no notification mechanism for changes in this value. |
| **BatteryGranularityInformation** | A variable-length array of [**BATTERY\_REPORTING\_SCALE**](https://learn.microsoft.com/windows/desktop/api/WinNT/ns-winnt-battery_reporting_scale) structures that contains the reporting granularity for the battery capacity that is returned from [**IOCTL\_BATTERY\_QUERY\_STATUS**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-query-status). Multiple entries are returned when the granularity depends on the present capacity of the battery. See **BATTERY\_REPORTING\_SCALE** for the interpretation of the array of entries. The number of entries is indicated by the size of the buffer returned, and can be calculated as (*lpBytesReturned* / sizeof (**BATTERY\_REPORTING\_SCALE**)). The maximum number of entries that will be returned is four. |
| **BatteryInformation** | A [**BATTERY\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/battery-information-str) structure. |
| **BatteryManufactureDate** | A [**BATTERY\_MANUFACTURE\_DATE**](https://learn.microsoft.com/windows/win32/power/battery-manufacture-date-str) structure. |
| **BatteryManufactureName** | **Null**-terminated Unicode string that contains the name of the manufacturer of the battery. |
| **BatterySerialNumber** | **Null**-terminated Unicode string that contains the battery's serial number. |
| **BatteryTemperature** | A **ULONG** that contains the battery's current temperature, in 10ths of a degree Kelvin. |
| **BatteryUniqueID** | **Null**-terminated Unicode string that uniquely identifies the battery. This value can be used to track a specific battery. In the case of smart batteries, this ID will be the concatenation of the manufacturer's name, device name, date of manufacture, and a printable representation of the serial number. This value is not intended to be displayed to the user.<br> |

*nOutBufferSize*

The size of the output buffer, in bytes. Depending on the information level of data requested, this may be a variably sized buffer.

*lpBytesReturned*

A pointer to a variable that receives the size of the data returned in the *lpOutBuffer* buffer, in bytes.

If the output buffer is too small to return any data then the call fails, [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns the error code **ERROR\_INSUFFICIENT\_BUFFER**, and the returned byte count is zero.

If *lpOverlapped* is **NULL** (nonoverlapped I/O), *lpBytesReturned* cannot be **NULL**.

If *lpOverlapped* is not **NULL** (overlapped I/O), *lpBytesReturned* can be **NULL**. If this is an overlapped operation, you can retrieve the number of bytes returned by calling the [**GetOverlappedResult**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getoverlappedresult) function. If *hDevice* is associated with an I/O completion port, you can get the number of bytes returned by calling the [**GetQueuedCompletionStatus**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function.

*lpOverlapped*

A pointer to an [**OVERLAPPED**](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure.

If *hDevice* was opened with the **FILE\_FLAG\_OVERLAPPED** flag, *lpOverlapped* must point to a valid [**OVERLAPPED**](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. In this case, [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) is performed as an overlapped (asynchronous) operation. If the device was opened with the **FILE\_FLAG\_OVERLAPPED** flag and *lpOverlapped* is **NULL**, the function fails in unpredictable ways.

If *hDevice* was opened without specifying the **FILE\_FLAG\_OVERLAPPED** flag, *lpOverlapped* is ignored and the [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) function does not return until the operation has been completed, or until an error occurs.

## Return value

If the operation completes successfully, [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) returns a nonzero value.

If the operation fails or is pending, [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) returns zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Some information about batteries is optional or may be meaningless for some batteries. If the particular type of data requested is not available for the current battery, then **ERROR\_INVALID\_FUNCTION** is returned.

All requests for battery information will complete with the status of ERROR_NO_SUCH_DEVICE (or ERROR_FILE_NOT_FOUND in **Windows 10 version 1809 and earlier**) whenever the BatteryTag element of the request does not match that of the current battery tag. This ensures that the returned battery information matches that of the requested battery (see [Battery Tags](https://learn.microsoft.com/windows/win32/power/battery-information) for more information).

## Remarks

This battery IOCTL retrieves a variety of information for the battery. The input parameter structure, [**BATTERY\_QUERY\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/battery-query-information-str), indicates the type of information to be returned and when the battery information should be returned. The data type and contents of the output buffer vary based on the data requested.

For the implications of overlapped I/O on this operation, see the Remarks section of the [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) topic.

## Examples

For an example, see [Enumerating Battery Devices](https://learn.microsoft.com/windows/win32/power/enumerating-battery-devices).

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Poclass.h;

BatClass.h on Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP | ## See also [Battery Information](https://learn.microsoft.com/windows/win32/power/battery-information) [Power Management Control Codes](https://learn.microsoft.com/windows/win32/power/power-management-control-codes) [**DeviceIoControl**](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol) [**BATTERY\_QUERY\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/battery-query-information-str) [**BATTERY\_REPORTING\_SCALE**](https://learn.microsoft.com/windows/desktop/api/WinNT/ns-winnt-battery_reporting_scale) [**IOCTL\_BATTERY\_QUERY\_STATUS**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-query-status) [**IOCTL\_BATTERY\_QUERY\_TAG**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-query-tag) [**IOCTL\_BATTERY\_SET\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-set-information)