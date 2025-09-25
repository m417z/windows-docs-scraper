# FaxDevVirtualDeviceCreation function

## Description

The fax service calls the **FaxDevVirtualDeviceCreation** function during initialization to allow the fax service provider (FSP) to present virtual fax devices. Each FSP that presents virtual fax devices to the fax service must export the **FaxDevVirtualDeviceCreation** function.

## Parameters

### `DeviceCount` [out]

Type: **LPDWORD**

Pointer to an unsigned **DWORD** variable that receives the number of virtual fax devices the fax service must create for the FSP. If the FSP sets this parameter to zero, the initialization of the provider will fail.

### `DeviceNamePrefix` [out]

Type: **LPWSTR**

Pointer to a variable that receives a null-terminated Unicode character string, limited to 128 **WCHAR** characters. The FSP must set this string to the name prefix for the virtual fax device. The fax service appends the value of the *DeviceIdPrefix* parameter to this string. The result is a unique device name for each virtual fax device the fax service creates.

### `DeviceIdPrefix` [out]

Type: **LPDWORD**

Pointer to an unsigned **DWORD** variable that receives a nonzero value. The FSP must set this member to a unique numeric value that identifies the virtual fax device. The fax service adds this value to a sequential number, beginning with zero for the first virtual device. The result is a unique device identifier for each virtual fax device the fax service creates.

### `CompletionPort` [in]

Type: **HANDLE**

Specifies a handle that the FSP must use to post I/O completion port packets to the fax service for asynchronous line status events. Currently the **FaxDevVirtualDeviceCreation** function supports only the event that signals an incoming call.

The completion port packet must be a TAPI 2.x [LINEMESSAGE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemessage) structure. The FSP must allocate memory for the structure with **LocalAlloc(**LPTR, sizeof(LINEMESSAGE)**)**. The fax service provider must pass the size of the memory allocated (which is sizeof(LINEMESSAGE) in this case) to the *dwNumberOfBytesTransferred* parameter of the [PostQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/FileIO/postqueuedcompletionstatus) method. The fax service frees any memory allocated for the completion packet structure.

The FSP must set the members of the structure as follows.

| Member | Contents |
| --- | --- |
| **hDevice** | Set to **DeviceId** from [FaxDevStartJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevstartjob) |
| **dwMessageID** | Set to 0 |
| **dwCallbackInstance** | Set to 0 |
| **dwParam1** | Set to LINEDEVSTATE_RINGING |
| **dwParam2** | Set to 0 |
| **dwParam1** | Set to 0 |

For information about line status events, see [LINEDEVSTATE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linedevstate--constants) in the TAPI documentation. For information about I/O completion ports, see [I/O Completion Ports](https://learn.microsoft.com/windows/desktop/FileIO/i-o-completion-ports).

### `CompletionKey` [in]

Type: **ULONG_PTR**

Specifies a completion key value. The FSP must use this value when the provider posts completion port packets to the fax service. The FSP should pass this opaque value to the [PostQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/FileIO/postqueuedcompletionstatus) function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, the fax service calls [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The fax service checks the FSP DLL for the **FaxDevVirtualDeviceCreation** function during initialization. If the FSP exports the function, the fax service assumes that the provider will present virtual fax devices. The fax service handles virtual fax devices the same way it handles physical fax devices. After initialization there is no difference between the functionality or operation of an FSP that presents virtual fax devices, and one that does not present them.

When an FSP uses physical fax devices, the TAPI and the telephony service provider (TSP) enumerate the devices for the fax service. If the FSP does not have physical fax devices, and it presents only virtual fax devices, a TSP will not exist, and TAPI will not enumerate the devices. In this instance, **FaxDevVirtualDeviceCreation** provides the virtual fax device enumeration for the fax service.

## See also

[Creating a Completion Packet](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-creating-a-completion-packet)

[Fax Service Provider Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-provider-functions)

[FaxDevInitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevinitialize)

[FaxDevStartJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxdev/nf-faxdev-faxdevstartjob)

[LINEMESSAGE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemessage)

[PostQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/FileIO/postqueuedcompletionstatus)

[Using a Virtual Device to Transmit a Fax](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-using-a-virtual-device-to-transmit-a-fax)

[Using the Fax Service Provider API](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-using-the-fax-service-provider-api)

[Virtual Fax Devices](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-virtual-fax-devices)