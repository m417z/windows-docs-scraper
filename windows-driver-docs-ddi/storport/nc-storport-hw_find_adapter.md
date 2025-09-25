# HW_FIND_ADAPTER callback function

## Description

The **HwStorFindAdapter** routine uses the supplied configuration to determine whether a specific HBA is supported and, if it is, to return configuration information about that adapter.

## Parameters

### `DeviceExtension`

Supplies a per adapter storage area.

### `HwContext` [in]

Set to NULL.

### `BusInformation` [in]

Set to NULL.

### `ArgumentString` [in]

Supplies a **NULL**-terminated string with context information about the driver.

### `ConfigInfo` [in/out]

Supplies an initialized [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) structure that the miniport driver uses during initialization.

### `Reserved3` [in]

Reserved for system use.

## Return value

**HwStorFindAdapter** must return one of the following status values:

| Return code | Description |
| ----------- | ----------- |
| **SP_RETURN_FOUND** | Indicates that a supported HBA was found and that the HBA-relevant configuration information was successfully determined and set in the [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) structure. |
| **SP_RETURN_ERROR** | Indicates that an HBA was found but there was an error obtaining the configuration information. If possible, such an error should be logged with [**StorPortLogError**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportlogerror). |
| **SP_RETURN_BAD_CONFIG** | Indicates that the supplied configuration information was invalid for the adapter. |
| **SP_RETURN_NOT_FOUND** | Indicates that no supported HBA was found for the supplied configuration information. |

## Remarks

Because the Storport driver supports only Plug and Play (PnP) devices, the *HwContext* and *BusInformation* parameters to **HwStorFindAdapter** are not supplied to non-virtual miniport drivers.

**HwStorFindAdapter** must set the **MaximumTransferLength** and **NumberOfPhysicalBreaks** fields in the *ConfigInfo* structure. Other than these fields, the [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) structure will always fully specify all adapter resources that are required to start the adapter.

The name **HwStorFindAdapter** is just a placeholder. The actual prototype of this routine is defined in *Storport.h* as follows:

```C
typedef
ULONG
HW_FIND_ADAPTER (
  _In_ PVOID  DeviceExtension,
  _In_ PVOID  HwContext,
  _In_ PVOID  BusInformation,
  _In_z_ PCHAR  ArgumentString,
  _Inout_ PPORT_CONFIGURATION_INFORMATION  ConfigInfo,
  _In_ PBOOLEAN  Reserved3
  );
```

In most cases StorPort calls the **HwStorFindAdapter** routine at IRQL == PASSIVE_LEVEL without acquiring any spin locks. The exception case is when the miniport does not support calling [**HwStorAdaptorControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with the **ScsiRestartAdapter** control type. In this situation, StorPort will instead reinitialize the adapter by calling both **HwStorFindAdapter** and [**HwStorInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize). When this is the case, **HwStorFindAdapter** is called at IRQL == DISPATCH_LEVEL. Also, when in dump mode, **HwStorFindAdapter** is called at IRQL == HIGH_LEVEL.

### Examples

To define an **HwStorFindAdapter** callback function, you must first provide a function declaration that identifies the type of callback function you’re defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it’s a requirement for writing drivers for the Windows operating system.

 For example, to define a **HwStorFindAdapter** callback routine that is named *MyHwFindAdapter*, use the **HW_FIND_ADAPTER** type as shown in this code example:

```cpp
HW_FIND_ADAPTER MyHwFindAdapter;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
ULONG
MyHwFindAdapter (
  _In_ PVOID  DeviceExtension,
  _In_ PVOID  HwContext,
  _In_ PVOID  BusInformation,
  _In_z_ PCHAR  ArgumentString,
  _Inout_ PPORT_CONFIGURATION_INFORMATION  ConfigInfo,
  _In_ PBOOLEAN  Reserved3
  );
  {
      ...
  }
```

The **HW_FIND_ADAPTER** function type is defined in the Storport.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **HW_FIND_ADAPTER** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions Using Function Role Types for Storport Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-storport-drivers). For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[**HwStorInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize)

[**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information)

[**StorPortInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize)

[**StorPortLogError**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportlogerror)