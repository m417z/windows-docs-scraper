# IOCTL_BTH_HCI_VENDOR_COMMAND IOCTL

## Description

 The IOCTL_BTH_HCI_VENDOR_COMMAND request allows Bluetooth applications to send vendor-specific
commands to radios.

## Parameters

### Major code

### Input buffer

The
**AssociatedIrp.SystemBuffer** member points to a
[BTH_VENDOR_SPECIFIC_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_vendor_specific_command) structure. The structure contains a manufacturer identifier, a link
management protocol (LMP) version, an HCI command header, and the associated vendor command data that
includes optional pattern data to match an event to the command.

### Input buffer length

The length of a
[BTH_VENDOR_SPECIFIC_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_vendor_specific_command) structure.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a buffer that contains the event data returned from the radio. The data is available in the **EventInfo** member of the [BTH_VENDOR_EVENT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_vendor_event_info) structure.

```
typedef struct _BTH_VENDOR_EVENT_INFO {
  BTH_ADDR BthAddress;
  ULONG    EventSize;
  UCHAR    EventInfo[1];
} BTH_VENDOR_EVENT_INFO, *PBTH_VENDOR_EVENT_INFO;
```

The **EventSize** member provides the size of the vendor-specific event data returned from the radio.

### Output buffer length

The length of a [BTH_VENDOR_EVENT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_vendor_event_info) structure.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the
**Information** member of the STATUS_BLOCK structure is set to the size, in bytes, of the buffer that
holds the command response.

The
**Status** member is set to one of the values in the following table.

| Status value | Description |
| --- | --- |
| STATUS_SUCCESS | The IOCTL completed successfully. |
| STATUS_BUFFER_TOO_SMALL | The input buffer that was passed was too small. |
| STATUS_INVALID_PARAMETER | The input buffer that was passed was invalid. |
| STATUS_PRIVILEGE_NOT_HELD | The caller does not have the required privileges. |
| STATUS_INSUFFICIENT_RESOURCES | There was insufficient memory available to process the request. |

## Remarks

The IOCTL_BTH_HCI_VENDOR_COMMAND request provides a mechanism that allows vendors to create commands
that are specific to their Bluetooth radios.

The manufacturer ID and link management protocol (LMP) version values that are in the
[BTH_VENDOR_SPECIFIC_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_vendor_specific_command) structure help to prevent the sending of vendor-specific commands to
the wrong radio. The LMP version enables the vendors to send vendor-specific commands to radios that have
a matching LMP version. If the LMP version is zero, all radios from that vendor will receive the
vendor-specific command.

Patterns are required if a vendor-specific command does not follow the standard HCI flow control and a
vendor-specific event is generated in response to the vendor-specific command.

If patterns are required, the command should be followed by
[BTH_VENDOR_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_vendor_pattern) structures for patterns
that are present in the event. These patterns allow the Bluetooth driver stack to match vendor-specific
events with the corresponding vendor-specific commands.

The BTH_VENDOR_PATTERN structure specifies such patterns that follow the vendor-specific command data
that is specified in the
**Data** member of BTH_VENDOR_SPECIFIC_COMMAND structure. The maximum total size of all the patterns
that follow the command should not be greater than 255.

**Warning** The process that submits IOCTL_BTH_HCI_VENDOR_COMMAND must have the
SE_LOAD_DRIVER_NAME privilege. A process that is running in the system or an administrator context can
elevate its privilege by using the SDK
**LookupPrivilegeValue** and
**AdjustTokenPrivileges** functions. The following code example demonstrates how to obtain this
privilege. Note that the example does not demonstrate error handling.

```
HANDLE procToken;
LUID luid;
TOKEN_PRIVILEGES tp;

OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &procToken);

LookupPrivilegeValue(NULL, SE_LOAD_DRIVER_NAME, &luid);

Tp.PrivilegeCount = 1;
Tp.privileges[0].Luid = luid;
Tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

AdjustTokenPrivileges(procToken, FALSE, &tp, sizeof(TOKEN_PRIVILEGES), (PTOKEN_PRIVILEGES) NULL, (PDWORD)NULL);
```

The event that is generated because of this command is copied into the output buffer (including the
event header).

## See also

[BTH_COMMAND_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_command_header)

[BTH_VENDOR_PATTERN](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_vendor_pattern)

[BTH_VENDOR_SPECIFIC_COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_vendor_specific_command)