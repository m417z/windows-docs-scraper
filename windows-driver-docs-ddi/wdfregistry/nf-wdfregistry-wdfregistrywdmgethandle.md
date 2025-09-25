# WdfRegistryWdmGetHandle function

## Description

[Applies to KMDF and UMDF]

The **WdfRegistryWdmGetHandle** method returns a Windows Driver Model (WDM) handle to the registry key that a specified framework registry-key object represents.

## Parameters

### `Key` [in]

A handle to a registry-key object that represents an opened registry key.

## Return value

**WdfRegistryWdmGetHandle** returns a WDM handle to a registry key.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

A KMDF driver can pass the returned WDM handle to the [ZwXxx routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/) that accept a WDM handle as input.

A UMDF driver can pass the returned handle to APIs that require an HKEY, such as [RegEnumKeyEx](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regenumkeyexa).

The handle that the **WdfRegistryWdmGetHandle** method returns is valid until the registry-key object is deleted. If the driver provides an [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) function for the registry-key object, the pointer is valid until the callback function returns.

For more information about registry-key objects, see [Using the Registry in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-wdf-drivers).

#### Examples

The following code example obtains a WDM handle to the registry key that a specified framework registry-key object represents.

```cpp
HANDLE hKey;

hKey = WdfRegistryWdmGetHandle(Key);
```