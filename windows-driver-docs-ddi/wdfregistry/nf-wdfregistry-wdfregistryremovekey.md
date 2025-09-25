# WdfRegistryRemoveKey function

## Description

[Applies to KMDF and UMDF]

The **WdfRegistryRemoveKey** method removes the registry key that is associated with a specified framework registry-key object and then deletes the registry-key object.

## Parameters

### `Key` [in]

A handle to a registry-key object that represents an opened registry key.

## Return value

**WdfRegistryRemoveKey** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | [WdfRegistryRemoveKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryremovekey) was not called at IRQL = PASSIVE_LEVEL. |
| **STATUS_ACCESS_DENIED** | The driver did not open the registry key with deletion access. |
| **STATUS_NOT_IMPLEMENTED** | See the Remarks section. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

> [!NOTE]
> Before calling **WdfRegistryRemoveKey**, ensure that all the keys and values under the given key have been deleted. Delete each subkey first, starting with the leaf keys and work your way up.

**Note**

From a KMDF driver, do not call **WdfRegistryRemoveKey** and then [WdfRegistryClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryclose) on the same key. The WDFKEY is no longer valid after **WdfRegistryRemoveKey** returns.

While it is legal for a UMDF driver to call **WdfRegistryRemoveKey**, the call always returns **STATUS_NOT_IMPLEMENTED**. To delete the WDFKEY object, a UMDF driver should instead call [WdfRegistryClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryclose).

For more information about registry-key objects, see [Using the Registry in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-wdf-drivers).

#### Examples

The following code example removes a registry key and deletes the registry-key object.

```cpp
NTSTATUS  status;

status = WdfRegistryRemoveKey(Key);
```