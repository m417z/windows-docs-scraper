## Description

The **MONITORREG** structure supplies print monitors with the address of registry functions to use instead of Win32 registry API functions.

## Members

### `cbSize`

Size, in bytes, of the **MONITORREG** structure.

### `fpCreateKey`

Pointer to a **CreateKey** spooler registry function.

### `fpOpenKey`

Pointer to an **OpenKey** spooler registry function.

### `fpCloseKey`

Pointer to a **CloseKey** spooler registry function.

### `fpDeleteKey`

Pointer to a **DeleteKey** spooler registry function.

### `fpEnumKey`

Pointer to an **EnumKey** spooler registry function.

### `fpQueryInfoKey`

Pointer to a **QueryInfoKey** spooler registry function.

### `fpSetValue`

Pointer to a **SetValue** spooler registry function.

### `fpDeleteValue`

Pointer to a **DeleteValue** spooler registry function.

### `fpEnumValue`

Pointer to an **EnumValue** spooler registry function.

### `fpQueryValue`

Pointer to a **QueryValue** spooler registry function.

## Remarks

The **MONITORREG** structure's address is supplied in a [MONITORINIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitorinit) structure, which is passed to a print monitor's [InitializePrintMonitor2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-initializeprintmonitor2) function.

When [storing port configuration information](https://learn.microsoft.com/windows-hardware/drivers/print/storing-port-configuration-information), print monitors must not explicitly call either the Win32 registry API or the cluster registry API.

The spooler contains a copy of the registry. Do not use the Win32 registry API to get the value actually used by the spooler. Use the spooler registry functions listed below whose pointers are contained in the **MONITORREG** structure.

Instead, they must call equivalent spooler registry functions. The **MONITORREG** structure supplies the addresses of these functions. The following table lists each spooler registry function and its equivalent cluster registry function.

| Spooler registry function | Equivalent cluster registry function |
|---|---|
| CreateKey | ClusterRegCreateKey |
| OpenKey | ClusterRegOpenKey |
| CloseKey | ClusterRegCloseKey |
| DeleteKey | ClusterRegDeleteKey |
| EnumKey | ClusterRegEnumKey |
| QueryInfoKey | ClusterRegQueryInfoKey |
| SetValue | ClusterRegSetValue |
| DeleteValue | ClusterRegDeleteValue |
| EnumValue | ClusterRegEnumValue |
| QueryValue | ClusterRegQueryValue |

Input and output parameters for these spooler functions match the parameters of the equivalent cluster registry functions in the [clusapi.h](https://learn.microsoft.com/windows/win32/api/clusapi/) header, with the following exceptions:

- Each spooler registry function requires an *hSpooler* input parameter. This is the spooler handle received in the [**MONITORINIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitorinit) structure.

- The spooler registry functions use HANDLE and PHANDLE parameter types instead of the HKEY and PHKEY types used by the cluster registry functions. Monitors receive the handle of the root registry location in the **hckRegistryRoot** member of the [**MONITORINIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitorinit) structure.

## See also

[InitializePrintMonitor2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-initializeprintmonitor2)

[**MONITORINIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitorinit)