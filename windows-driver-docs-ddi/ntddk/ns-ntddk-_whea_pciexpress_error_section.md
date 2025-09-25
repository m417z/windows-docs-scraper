## Description

The **WHEA_PCIEXPRESS_ERROR_SECTION** structure describes PCI Express (PCIe) error data.

## Members

### `ValidBits`

A [WHEA_PCIEXPRESS_ERROR_SECTION_VALIDBITS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pciexpress_error_section_validbits) union that specifies which members of this structure contain valid data.

### `PortType`

The device type or port type of the PCIe component where the error occurred. Possible values are:

#### WheaPciExpressEndpoint

A PCIe endpoint device.

#### WheaPciExpressLegacyEndpoint

A legacy PCIe endpoint device.

#### WheaPciExpressRootPort

A root port of a PCIe root complex.

#### WheaPciExpressUpstreamSwitchPort

An upstream port of a PCIe switch.

#### WheaPciExpressDownstreamSwitchPort

A downstream port of a PCIe switch.

#### WheaPciExpressToPciXBridge

A PCIe-to-PCI or PCI-X bridge.

#### WheaPciXToExpressBridge

A PCI or PCI-X-to-PCIe bridge.

#### WheaPciExpressRootComplexIntegratedEndpoint

A PCIe endpoint device that is integrated into the root complex.

#### WheaPciExpressRootComplexEventCollector

A PCIe root complex event collector.

This member contains valid data only if the **ValidBits.PortType** bit is set.

### `Version`

A **WHEA_PCIEXPRESS_VERSION** union that contains the version of the PCIe specification that is supported by the hardware platform. The **WHEA_PCIEXPRESS_VERSION** union is defined as follows:

```cpp
typedef union _WHEA_PCIEXPRESS_VERSION {
  struct {
    UCHAR  MinorVersion;
    UCHAR  MajorVersion;
    USHORT  Reserved;
  };
  ULONG  AsULONG;
} WHEA_PCIEXPRESS_VERSION, *PWHEA_PCIEXPRESS_VERSION;
```

#### MinorVersion

The minor version number.

#### MajorVersion

The major version number.

#### Reserved

Reserved for system use.

#### AsULONG

A ULONG representation of the contents of the **WHEA_PCIEXPRESS_VERSION** union.

This member contains valid data only if the **ValidBits.Version** bit is set.

### `CommandStatus`

A **WHEA_PCIEXPRESS_COMMAND_STATUS** union that contains the contents of the PCI command and status registers of the PCIe device where the error occurred. The **WHEA_PCIEXPRESS_COMMAND_STATUS** union is defined as follows:

```cpp
typedef union _WHEA_PCIEXPRESS_COMMAND_STATUS {
  struct {
    USHORT  Command;
    USHORT  Status;
  };
  ULONG  AsULONG;
} WHEA_PCIEXPRESS_COMMAND_STATUS, *PWHEA_PCIEXPRESS_COMMAND_STATUS;
```

#### Command

The contents of the PCI command register.

#### Status

The contents of the PCI status register.

#### AsULONG (CommandStatus)

A **ULONG** representation of the contents of the **WHEA_PCIEXPRESS_COMMAND_STATUS** union.

This member contains valid data only if the **ValidBits.CommandStatus** bit is set.

### `Reserved`

Reserved for system use.

### `DeviceId`

A **WHEA_PCIEXPRESS_DEVICE_ID** structure that contains data that identifies the PCIe device where the error occurred. The **WHEA_PCIEXPRESS_DEVICE_ID** structure is defined as follows:

```cpp
typedef struct _WHEA_PCIEXPRESS_DEVICE_ID {
  USHORT  VendorID;
  USHORT  DeviceID;
  ULONG  ClassCode:24;
  ULONG  FunctionNumber:8;
  ULONG  DeviceNumber:8;
  ULONG  Segment:16;
  ULONG  PrimaryBusNumber:8;
  ULONG  SecondaryBusNumber:8;
  ULONG Reserved1:3;
  ULONG SlotNumber:13;  ULONG  Reserved2:8;
} WHEA_PCIEXPRESS_DEVICE_ID, *PWHEA_PCIEXPRESS_DEVICE_ID;
```

#### VendorID

The vendor ID of the device.

#### DeviceId

The device ID of the device.

#### ClassCode

The class code of the device.

#### FunctionNumber

The function number of the device on the bus.

#### DeviceNumber

The device number of the device on the bus.

#### Segment

The number of the bus segment that contains the device.

#### PrimaryBusNumber

The root port/bridge primary bus number or the device bus number.

#### SecondaryBusNumber

The root port/bridge secondary bus number.

#### Reserved1

Reserved for system use.

#### SlotNumber

The slot number where the device is located in the system.

#### Reserved2

Reserved for system use.

This member contains valid data only if the **ValidBits.DeviceId** bit is set.

### `DeviceSerialNumber`

The serial number of the PCIe device where the error occurred.

This member contains valid data only if the **ValidBits.DeviceSerialNumber** bit is set.

### `BridgeControlStatus`

A **WHEA_PCIEXPRESS_BRIDGE_CONTROL_STATUS** union that contains the contents of the PCI control and secondary status registers of the bridge device where the error occurred. The **WHEA_PCIEXPRESS_BRIDGE_CONTROL_STATUS** union is defined as follows:

```cpp
typedef union _WHEA_PCIEXPRESS_BRIDGE_CONTROL_STATUS {
  struct {
    USHORT  BridgeSecondaryStatus;
    USHORT  BridgeControl;
  };
  ULONG  AsULONG;
} WHEA_PCIEXPRESS_BRIDGE_CONTROL_STATUS, *PWHEA_PCIEXPRESS_BRIDGE_CONTROL_STATUS;
```

#### BridgeSecondaryStatus

The contents of the secondary status register of the bridge device.

#### BridgeControl

The contents of the control register of the bridge device.

#### AsULONG (BridgeControlStatus)

A ULONG representation of the contents of the **WHEA_PCIEXPRESS_BRIDGE_CONTROL_STATUS** union.

This member contains valid data only if the **ValidBits.BridgeControlStatus** bit is set.

### `ExpressCapability`

A buffer that contains a [**PCI_EXPRESS_CAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability) structure that describes the PCIe capability structure for the device where the error occurred.

This member contains valid data only if the **ValidBits.ExpressCapability** bit is set.

### `AerInfo`

A buffer that contains a [**PCI_EXPRESS_AER_CAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability) structure that describes the PCIe advanced error reporting (AER) extended capability structure for the device where the error occurred.

This member contains valid data only if the **ValidBits.AerInfo** bit is set.

## Remarks

The WHEA_PCIEXPRESS_ERROR_SECTION structure describes the error data that is contained in a PCI Express (PCIe) error section of an [error record](https://learn.microsoft.com/windows-hardware/drivers/whea/error-records). An error record contains a PCIe error section only if the **SectionType** member of one of the [**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor) structures that describe the error record sections for that error record contains PCIEXPRESS_ERROR_SECTION_GUID.

## See also

[**PCI_EXPRESS_AER_CAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_pci_express_aer_capability)

[**PCI_EXPRESS_CAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_pci_express_capability)

[**WHEA_ERROR_PACKET**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560465(v=vs.85))

[**WHEA_ERROR_RECORD_SECTION_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_section_descriptor)

[**WHEA_PCIEXPRESS_ERROR_SECTION_VALIDBITS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pciexpress_error_section_validbits)