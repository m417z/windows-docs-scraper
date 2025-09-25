## Description

Defines constants that specify DXCore adapter properties. Pass one of these constants to the [IDXCoreAdapter::GetPropertySize](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapter-getpropertysize) method to retrieve the buffer size necessary to receive the value of the corresponding property; then pass the same constant to the [IDXCoreAdapter::GetProperty](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapter-getproperty) method to retrieve the property's value in a buffer that you allocate.

## Constants

### `InstanceLuid:0`

Specifies the *InstanceLuid* adapter property, which contains a locally unique identifier representing the adapter. This value remains constant for the lifetime of this adapter. The LUID of an adapter changes on reboot, driver upgrade, or device disablement/enablement.

The *InstanceLuid* adapter property has type [LUID](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-luid).

### `DriverVersion:1`

Specifies the *DriverVersion* adapter property, which contains the driver version, represented in **WORD**s as a **LARGE_INTEGER**.

The *DriverVersion* adapter property has type **uint64_t**, representing a Boolean value.

### `DriverDescription:2`

Specifies the *DriverDescription* adapter property, which contains a NULL-terminated array of **CHAR**s describing the driver, as specified by the driver, in [UTF-8](https://learn.microsoft.com/windows/win32/intl/unicode) encoding.

The *DriverDescription* adapter property has type **char***.

### `HardwareID:3`

Specifies the *HardwareID* adapter property, which represents the PnP hardware ID parts. But use *HardwareIDParts* instead, if available.

The *HardwareID* adapter property has type [DXCoreHardwareID](https://learn.microsoft.com/windows/win32/api/dxcore_interface/ns-dxcore_interface-dxcorehardwareid).

### `KmdModelVersion:4`

Specifies the *KmdModelVersion* adapter property, which represents the driver model.

The *KmdModelVersion* adapter property has type [D3DKMT_DRIVERVERSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dkmthk/ne-d3dkmthk-_qai_driverversion).

### `ComputePreemptionGranularity:5`

Specifies the *ComputePreemptionGranularity* adapter property, which represents the compute preemption granularity.

The *ComputePreemptionGranularity* adapter property has type **uint16_t**, representing a [D3DKMDT_COMPUTE_PREEMPTION_GRANULARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dkmdt/ne-d3dkmdt-_d3dkmdt_compute_preemption_granularity) value.

### `GraphicsPreemptionGranularity:6`

Specifies the *GraphicsPreemptionGranularity* adapter property, which represents the graphics preemption granularity.

The *GraphicsPreemptionGranularity* adapter property has type **uint16_t**, representing a [D3DKMDT_GRAPHICS_PREEMPTION_GRANULARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dkmdt/ne-d3dkmdt-_d3dkmdt_graphics_preemption_granularity) value.

### `DedicatedAdapterMemory:7`

Specifies the *DedicatedAdapterMemory* adapter property, which represents the number of bytes of dedicated adapter memory that are not shared with the CPU.

The *DedicatedVideoMemory* adapter property has type **uint64_t**.

### `DedicatedSystemMemory:8`

Specifies the *DedicatedSystemMemory* adapter property, which represents the number of bytes of dedicated system memory that are not shared with the CPU. This memory is allocated from available system memory at boot time.

The *DedicatedSystemMemory* adapter property has type **uint64_t**.

### `SharedSystemMemory:9`

Specifies the *SharedSystemMemory* adapter property, which represents the number of bytes of shared system memory. This is the maximum value of system memory that may be consumed by the adapter during operation. Any incidental memory consumed by the driver as it manages and uses video memory is additional.

The *SharedSystemMemory* adapter property has type **uint64_t**.

### `AcgCompatible:10`

Specifies the *AcgCompatible* adapter property, which indicates whether the adapter is compatible with processes that enforce Arbitrary Code Guard.

The *AcgCompatible* adapter property has type **bool**.

### `IsHardware:11`

Specifies the *IsHardware* adapter property, which determines whether or not this is a hardware adapter. An adapter that's not a hardware adapter is a software adapter.

The *IsHardware* adapter property has type **bool**.

### `IsIntegrated:12`

Specifies the *IsIntegrated* adapter property, which determines whether the adapter is reported to be an integrated graphics processor (iGPU).

The *IsIntegrated* adapter property has type **bool**.

### `IsDetachable:13`

Specifies the *IsDetachable* adapter property, which determines whether the adapter has been reported to be detachable, or removable.

The *IsDetachable* adapter property has type **bool**.

**Note**. Even if [IDXCoreAdapter::GetProperty](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapter-getproperty) indicates `false` for this property, the adapter still has the ability to be reported as removed, such as in the case of malfunction, or driver update.

### `HardwareIDParts:14`

Specifies the *HardwareIDParts* adapter property, which represents the PnP hardware ID parts.

The *HardwareIDParts* adapter property has type [DXCoreHardwareID](https://learn.microsoft.com/windows/win32/api/dxcore_interface/ns-dxcore_interface-dxcorehardwareid).

### `PhysicalAdapterCount:15`

This query outputs the number of physical adapters grouped under the logical adapter.

### `AdapterEngineCount:16`

This query takes physical adapter index as input, and outputs the count of engines on the physical adapter.

### `AdapterEngineName:17`

This query takes physical adapter index and engine ID as input, and outputs engine type.

## See also

[IDXCoreAdapter::GetPropertySize](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapter-getpropertysize), [IDXCoreAdapter::GetProperty](https://learn.microsoft.com/windows/win32/dxcore/dxcore_interface/nf-dxcore_interface-idxcoreadapter-getproperty), [DXCore reference](https://learn.microsoft.com/windows/win32/dxcore/dxcore-reference), [Using DXCore to enumerate adapters](https://learn.microsoft.com/windows/win32/dxcore/dxcore-enum-adapters)