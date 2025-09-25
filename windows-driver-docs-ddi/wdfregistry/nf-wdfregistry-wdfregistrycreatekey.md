# WdfRegistryCreateKey function

## Description

[Applies to KMDF and UMDF]

The **WdfRegistryCreateKey** method creates and opens a specified registry key, or just opens the key if it already exists, and creates a framework registry-key object that represents the registry key.

## Parameters

### `ParentKey` [in, optional]

A handle to a framework registry-key object. This object represents a parent registry key that the driver has opened. This parameter is optional and can be **NULL**. If the parameter is not **NULL**, the key that *KeyName* specifies must reside under this parent key in the registry. For more information about this parent key, see the Remarks section.

### `KeyName` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the name of the key to be opened. The key name can include path information. If *ParentKey* is **NULL**, *KeyName* must specify a complete path to a registry key.

### `DesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)-typed value that specifies access rights that the driver is requesting for the specified registry key. For a list of access rights that drivers typically use for registry keys, see [Opening a Handle to a Registry-Key Object](https://learn.microsoft.com/windows-hardware/drivers/kernel/opening-a-handle-to-a-registry-key-object). Your driver must ask for only the types of access that it needs. For example, the driver must not ask for KEY_ALL_ACCESS if it will only read the registry key.

### `CreateOptions` [in]

One or more flags. For information about these flags, see the *CreateOptions* parameter or [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey).

### `CreateDisposition` [out, optional]

A pointer to a location that receives REG_CREATED_NEW_KEY if a new key is created or REG_OPENED_EXISTING_KEY if an existing key is opened. These values are defined in *Wdm.h*. This pointer is optional and can be **NULL**.

### `KeyAttributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains driver-supplied attributes for the new registry-key object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `Key` [out]

A pointer to a location that receives a handle to the new registry-key object.

## Return value

**WdfRegistryCreateKey** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | [WdfRegistryCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistrycreatekey) was not called at IRQL = PASSIVE_LEVEL. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_INSUFFICIENT_RESOURCES** | A registry-key object could not be allocated. |
| **STATUS_ACCESS_DENIED** | The system denied the specified access rights. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The specified registry key does not exist. |

For a list of other return values that the **WdfRegistryCreateKey** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

To obtain a handle to a registry-key object that represents a parent key, your driver can call [WdfDriverOpenParametersRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdriveropenparametersregistrykey), [WdfDeviceOpenRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceopenregistrykey), or [WdfFdoInitOpenRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitopenregistrykey).

By default, the new registry-key object's parent is the framework driver object that the [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate) method creates. You can use the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure to specify a different parent. The framework deletes the registry-key object when it deletes the parent object. If your driver does not change the default parent, the driver should delete the registry-key object when it has finished using the object; otherwise, the registry-key object will remain until the I/O manager unloads your driver.

 If your driver does not change the default parent, the driver should call [WdfRegistryClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryclose) when it has finished using the object; otherwise, the registry-key object will remain until the I/O manager unloads your driver. Alternatively, the driver can call [WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete) to delete the registry-key object.

For more information about registry-key objects, see [Using the Registry in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-wdf-drivers).

#### Examples

The following code example opens a driver's software key, and then it creates and opens the **myKeyStr** registry key, which is located under the driver's software key.

```cpp
WDFKEY  hKey, subkey;
NTSTATUS  status;
UNICODE_STRING  myKeyStr;

status = WdfDeviceOpenRegistryKey(
                                  device,
                                  PLUGPLAY_REGKEY_DRIVER,
                                  KEY_READ,
                                  WDF_NO_OBJECT_ATTRIBUTES,
                                  &hKey
                                  );
if (NT_SUCCESS(status)){
    RtlInitUnicodeString(
                         &myKeyStr,
                         L"myKeyStr"
                         );
    status = WdfRegistryCreateKey(
                                  hKey,
                                  &myKeyStr,
                                  KEY_READ,
                                  REG_OPTION_NON_VOLATILE,
                                  NULL,
                                  WDF_NO_OBJECT_ATTRIBUTES,
                                  &subkey
                                  );
}
```

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[RtlInitUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitunicodestring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfDeviceOpenRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceopenregistrykey)

[WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate)

[WdfDriverOpenParametersRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdriveropenparametersregistrykey)

[WdfFdoInitOpenRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitopenregistrykey)

[WdfRegistryOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryopenkey)

[ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey)