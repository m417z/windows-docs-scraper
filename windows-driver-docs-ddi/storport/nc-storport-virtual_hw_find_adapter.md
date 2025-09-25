# VIRTUAL_HW_FIND_ADAPTER callback function

## Description

The Storport virtual miniport uses configuration information supplied to the **VIRTUAL_HW_FIND_ADAPTER** routine to further initialize itself.

## Parameters

### `DeviceExtension`

A pointer to the miniport driver's per-adapter non-paged storage area. The operating system-specific port driver allocates memory for and initializes this extension with zeros before it calls the miniport's **VIRTUAL_HW_FIND_ADAPTER** routine.

### `HwContext`

A pointer to the PDO in the device stack. The HBA itself is the FDO. The PDO might belong to the Pci.sys driver if the miniport driver controls physical hardware. But in the case of a virtual miniport driver, the PDO belongs to the PnP manager.

### `BusInformation`

A pointer to the miniport's functional device object (FDO).

### `LowerDevice`

A pointer to the device object controlled by the miniport's FDO.

### `ArgumentString`

A pointer to a null-terminated ASCII string. This string, if supplied, contains device information from the registry such as a base parameter.

### `ConfigInfo`

A pointer to a [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) structure. The port driver initializes this structure with any known configuration information, such as values that the miniport driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) set in the [**VIRTUAL_HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_virtual_hw_initialization_data). **VIRTUAL_HW_FIND_ADAPTER** must use any supplied information to determine if the virtual HBA it describes is one that the miniport driver supports. If so, **VIRTUAL_HW_FIND_ADAPTER** initializes and configures that HBA and fills in any missing configuration information. If possible, a miniport driver should have default configuration values for each type of HBA that it supports, in the event that the operating system-dependent port driver cannot supply additional configuration information that was not provided by the miniport driver's **DriverEntry** routine.

### `Again`

Not used.

## Return value

**VIRTUAL_HW_FIND_ADAPTER** must return one of the following status values:

| Return code | Description |
| ----------- | ----------- |
| SP_RETURN_FOUND | A supported HBA was found and that the HBA-relevant configuration information was determined successfully and set in the [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) structure. |
| SP_RETURN_ERROR | An HBA was found, but an error occurred when it obtained the configuration information. If possible, such an error should be logged with [**ScsiPortLogError**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportlogerror). |
| SP_RETURN_BAD_CONFIG | The supplied configuration information was invalid for the adapter. |
| SP_RETURN_NOT_FOUND | No supported HBA was found for the supplied configuration information. |

## Remarks

The **VirtualDevice** field in the configuration information structure must be set to **TRUE**. Other fields can be set as needed.

The port driver calls the Storport virtual miniport's **VIRTUAL_HW_FIND_ADAPTER** at PASSIVE_LEVEL.

The name **VirtualHwStorFindAdapter** is placeholder text for the actual routine name. The actual prototype of this routine is defined in *Srb.h* as follows:

``` c
typedef
ULONG
VIRTUAL_HW_FIND_ADAPTER (
  _In_ PVOID  DeviceExtension,
  _In_ PVOID  HwContext,
  _In_ PVOID  BusInformation,
  _In_ PVOID  LowerDevice,
  _In_ PCHAR  ArgumentString,
  _Inout_ PPORT_CONFIGURATION_INFORMATION  ConfigInfo,
  _Out_ PBOOLEAN Again
  );
```

### Examples

To define a **VIRTUAL_HW_FIND_ADAPTER** callback function, you must first provide a function declaration that identifies the type of callback function you’re defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it’s a requirement for writing drivers for the Windows operating system.

 For example, to define a **VIRTUAL_HW_FIND_ADAPTER** callback routine that is named **MyVirtualHwFindAdapter**, use the **VIRTUAL_HW_FIND_ADAPTER** type as shown in this code example:

``` c
VIRTUAL_HW_FIND_ADAPTER MyVirtualHwFindAdapter;
```

Then, implement your callback routine as follows:

``` c
_Use_decl_annotations_
ULONG
MyVirtualHwFindAdapter (
  _In_ PVOID  DeviceExtension,
  _In_ PVOID  HwContext,
  _In_ PVOID  BusInformation,
  _In_ PVOID  LowerDevice,
  _In_ PCHAR  ArgumentString,
  _Inout_ PPORT_CONFIGURATION_INFORMATION  ConfigInfo,
  _Out_ PBOOLEAN Again
  );
  {
      ...
  }
```

The **VIRTUAL_HW_FIND_ADAPTER** function type is defined in the Storport.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **VIRTUAL_HW_FIND_ADAPTER** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions Using Function Role Types for Storport Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-storport-drivers). For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter)

[**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information)

[**ScsiPortLogError**](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportlogerror)

[**VIRTUAL_HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_virtual_hw_initialization_data)