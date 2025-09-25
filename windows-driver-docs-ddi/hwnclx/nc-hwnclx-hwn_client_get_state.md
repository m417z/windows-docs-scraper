# HWN_CLIENT_GET_STATE callback

## Description

Implemented by the client driver to get hardware notification component state. It is invoked when a user requests status information.

## Parameters

### `Context` [in]

Pointer to the client driver's context information. This memory space is available for use by the client driver. It is allocated as part of the framework object context space by **WdfDeviceCreate**. For more information, see [HWN_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) and [Framework Object Context Space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space).

### `OutputBuffer` [out]

Buffer of *OutputBufferLength* bytes for writing hardware notification status. If the function succeeds, the buffer will contain a [HWN_HEADER](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) structure including one or more [HWN_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) structures.

**Note**

**OutputBufferLength** must be large enough to contain all of the requested settings. For more information, see Remarks.

### `OutputBufferLength` [in]

The size of *OutputBuffer* in bytes.

### `InputBuffer` [in]

Buffer of *InputBufferLength* bytes containing a [HWN_HEADER](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) holding one or more [HWN_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) structures where the IDs for the requested hardware notification components are stored in the **HwNId** field. This buffer can be NULL.

### `InputBufferLength` [in]

The size of *InputBuffer* in bytes.

### `BytesRead` [out]

Pointer to a variable that indicates the number of bytes read by the function.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Prototype

```cpp
HWN_CLIENT_GET_STATE HwnClientGetState;

NTSTATUS HwnClientGetState(
  _In_  PVOID  Context,
  _Out_ PVOID  OutputBuffer,
  _In_  ULONG  OutputBufferLength,
  _In_  PVOID  InputBuffer,
  _In_  ULONG  InputBufferLength,
  _Out_ PULONG BytesRead
)
{ ... }

typedef HWN_CLIENT_GET_STATE *PHWN_CLIENT_GET_STATE;
```

## Remarks

Register your implementation of this callback function by setting the appropriate member of [HWN_CLIENT_REGISTRATION_PACKET](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) and then calling [HwNRegisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/hwnclx/nf-hwnclx-hwnregisterclient).

* If *InputBuffer* is NULL, the output buffer will be used to store a [HWN_HEADER](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) structure that contains all of the settings for the hardware notifications implemented by the driver.

  The Settings for a hardware notification component are stored in a [HWN_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) structure. The **HwNSettingsInfo** field of the [HWN_HEADER](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) structure contains an array of **HWN_SETTINGS** structures.
* If *InputBuffer* is not null and is correctly formatted, it will contain a [HWN_HEADER](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) with one or more [HWN_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/create-a-hardware-notification-client-driver) structures. The IDs for the requested hardware notification components are stored in the **HwNId** field of the **HWN_SETTINGS** structure. The remaining settings should be valid settings or zero.
* If *OutputBuffer* is not large enough to contain all of the settings requested, this function should not write anything to *OutputBuffer*. Additionally, it should set *BytesRead* to 0 and return an error.

## See also

[Hardware notifications support](https://learn.microsoft.com/windows-hardware/drivers/gpiobtn/hardware-notifications-support)

[Hardware notifications reference](https://learn.microsoft.com/windows-hardware/drivers/ddi/_gpio)