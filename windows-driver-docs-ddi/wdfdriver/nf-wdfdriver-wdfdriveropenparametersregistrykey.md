# WdfDriverOpenParametersRegistryKey function

## Description

[Applies to KMDF and UMDF]

The **WdfDriverOpenParametersRegistryKey** method opens the driver's **Parameters** registry key and retrieves a handle to a framework registry-key object that represents the key.

## Parameters

### `Driver` [in]

A handle to the driver's framework driver object that the driver obtained from a previous call to [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate) or [WdfGetDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfgetdriver).

### `DesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)-typed value that specifies an access mask for the **Parameters** registry key.

A KMDF driver typically requests **KEY_READ**, **KEY_WRITE**, or **KEY_READ | KEY_WRITE**.

If you are writing a UMDF driver, use **KEY_READ** or **KEY_READ | KEY_SET_VALUE**.

As a best practice, ask for only the types of access that your driver needs.

### `KeyAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that specifies object attributes for the framework registry-key object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `Key` [out]

A pointer to a location that receives a handle to a framework registry-key object.

## Return value

**WdfDriverOpenParametersRegistryKey** returns STATUS_SUCCESS if the operation succeeds. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED** | A UMDF driver specified one of the following flags in the *DesiredAccess* parameter:<br><br>* GENERIC_WRITE<br>* KEY_CREATE_SUBKEY<br>* WRITE_DAC<br><br>Because the above values are invalid for UMDF drivers, universal flags such as GENERIC_ALL and STANDARD_RIGHTS_ALL also cause [WdfDriverOpenParametersRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdriveropenparametersregistrykey) to fail with this return value. |

For more information about return values, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A system bug check occurs if a KMDF driver specifies an invalid handle in *Driver*.

## Remarks

The driver's **Parameters** key is located in the registry's [Services](https://learn.microsoft.com/windows-hardware/test/wpt/services) tree. If the driver's **Parameters** key does not exist, the **WdfDriverOpenParametersRegistryKey** method creates it.

When the driver has finished using the **Parameters** registry key, the driver must call [WdfRegistryClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryclose).

> [!NOTE]
> UMDF does not support creating subkeys.

For more information about the registry, see [Using the Registry in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-wdf-drivers).

#### Examples

The following code example opens a driver's **Parameters** registry key and obtains a handle to a framework registry-key object that represents the key.

```cpp
WDFKEY hKey;

status = WdfDriverOpenParametersRegistryKey(
                                            Driver,
                                            STANDARD_RIGHTS_ALL,
                                            WDF_NO_OBJECT_ATTRIBUTES,
                                            &hKey
                                            );
```

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate)

[WdfDriverGetRegistryPath](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivergetregistrypath)

[WdfGetDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfgetdriver)

[WdfRegistryClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryclose)