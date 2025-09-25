# PUSB_BUSIFFN_ENUM_LOG_ENTRY callback

## Description

This callback function is not supported.

The *EnumLogEntry* routine makes a log entry.

## Syntax

```cpp
typedef NTSTATUS
  (USB_BUSIFFN *PUSB_BUSIFFN_ENUM_LOG_ENTRY) (
    IN PVOID,
    IN ULONG,
    IN ULONG,
    IN ULONG,
    IN ULONG
);
```

## Parameters

### `unnamedParam1` [in]

Handle to the bus context returned in the *BusContext* member of the [USB_BUS_INTERFACE_USBDI_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbbusif/ns-usbbusif-_usb_bus_interface_usbdi_v2) structure by an IRP_MN_QUERY_INTERFACE request.

### `unnamedParam2` [in]

Vendor-defined data to store in the enumeration log.

### `unnamedParam3` [in]

Vendor-defined data to store in the enumeration log.

### `unnamedParam4` [in]

Vendor-defined data to store in the enumeration log.

### `unnamedParam5` [in]

Vendor-defined data to store in the enumeration log.

## Return value

The *EnumLogEntry* routine always returns STATUS_SUCCESS.

## Remarks

The routine definition that is provided in the example is a routine whose parameters are just placeholder names. The actual prototype of the routine is declared in *usbbusif.h*.

## -example

```cpp
USB_BUSIFFN_ENUM_LOG_ENTRY EnumLogEntry;

NTSTATUS EnumLogEntry(
  _In_ PVOID BusContext,
  _In_ ULONG DriverTag,
  _In_ ULONG EnumTag,
  _In_ ULONG P1,
  _In_ ULONG P2
)
{ ... }
```