# WdfRegistryOpenKey function

## Description

[Applies to KMDF and UMDF]

The **WdfRegistryOpenKey** method opens a specified registry key and creates a framework registry-key object that represents the registry key.

## Parameters

### `ParentKey` [in, optional]

A handle to a framework registry-key object. This object represents a parent registry key that the driver has opened. This parameter is optional and can be **NULL**. If the parameter is not **NULL**, the key that *KeyName* specifies must reside under this parent key in the registry. For more information about this parent key, see the Remarks section.

### `KeyName` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the name of the key to be opened. The key name can include path information. If *ParentKey* is **NULL**, *KeyName* must specify a complete path to a registry key. For examples, see the Remarks section.

### `DesiredAccess` [in]

An [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)-typed value that specifies access rights that the driver is requesting for the specified registry key. For a list of access rights that drivers typically use for registry keys, see [Opening a Handle to a Registry-Key Object](https://learn.microsoft.com/windows-hardware/drivers/kernel/opening-a-handle-to-a-registry-key-object). Your driver must ask for only the types of access that it needs. For example, the driver must not ask for KEY_ALL_ACCESS if it will only read the registry key.

### `KeyAttributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains driver-supplied attributes for the new registry-key object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `Key` [out]

A pointer to a location that receives a handle to the new registry-key object.

## Return value

**WdfRegistryOpenKey** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | [WdfRegistryOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryopenkey) was not called at IRQL = PASSIVE_LEVEL. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_INSUFFICIENT_RESOURCES** | A registry-key object could not be allocated. |
| **STATUS_ACCESS_DENIED** | The system denied the specified access rights. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The specified registry key does not exist. |

For a list of other return values that the **WdfRegistryOpenKey** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

To obtain a handle to a registry-key object that represents a parent key, your driver can call [WdfDriverOpenParametersRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdriveropenparametersregistrykey), [WdfDeviceOpenRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceopenregistrykey), or [WdfFdoInitOpenRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitopenregistrykey).

The string format specified in the *KeyName* parameter depends on whether the caller is a KMDF driver or a UMDF driver. For example, to open the following path:

**HKLM\System\CurrentControlSet\Control**

Your driver might use this conditional logic:

```cpp
#ifdef _KERNEL_MODE
#define CONTROL_KEY_FULL_PATH L"\\Registry\\Machine\\System\\CurrentControlSet\\Control "
#else
#define CONTROL_KEY_FULL_PATH L"System\\CurrentControlSet\\Control\\"
#endif

```
When the driver has finished using a registry key that it opens with **WdfRegistryOpenKey**, the driver must call [WdfRegistryClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryclose).

For more information about registry-key objects, see [Using the Registry in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-wdf-drivers).

#### Examples

The following code example opens a driver's software key, and then it opens the **MySubKey** registry key, which is located under the driver's software key.

```cpp
WDFKEY  hKey, subkey;
NTSTATUS  status;
UNICODE_STRING myKeyStr;

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
                         L"MySubKey"
                         );
    status = WdfRegistryOpenKey(
                                hKey,
                                &myKeyStr,
                                KEY_READ,
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

[WdfDriverOpenParametersRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdriveropenparametersregistrykey)

[WdfFdoInitOpenRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitopenregistrykey)

[WdfRegistryClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryclose)

[WdfRegistryCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistrycreatekey)