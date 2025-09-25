# PcNewRegistryKey function

## Description

The **PcNewRegistryKey** function opens or creates a new registry key and creates an [IRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iregistrykey) object to represent the key. The caller accesses the key through this object.

## Parameters

### `OutRegistryKey` [out]

Output pointer to the registry-key object created by this function. This parameter points to a caller-allocated pointer variable into which the function outputs the pointer to the [IRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iregistrykey) object. The object represents the registry key being opened or created. Specify a valid, non-**NULL** pointer value for this parameter.

### `OuterUnknown` [in, optional]

Pointer to the [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) interface of an object that needs to aggregate the *OutRegistryKey* object. Unless aggregation is required, set this parameter to **NULL**.

### `RegistryKeyType` [in]

Specifies the type of registry key that the caller wants to create or open. For more information, see the following Remarks section.

### `DesiredAccess` [in]

Specifies an access-control mask. This parameter is a structure of type [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask). It indicates the type of access that the caller is requesting to the registry key that is to be opened or created. For more information, see the following Remarks section.

### `DeviceObject` [in, optional]

Pointer to the adapter driver's device object. This pointer is cast to type PVOID. If *RegistryKeyType* is any value other than **GeneralRegistryKey**, this parameter must point to a valid, initialized system structure of type [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object). If the value of *RegistryKeyType* is **GeneralRegistryKey**, the **PcNewRegistryKey** function does not use this parameter. For more information, see the following Remarks section.

### `SubDevice` [in, optional]

Specifies the aspect of the device that is to be offered to clients. Adapter drivers must assign the value **NULL** to this parameter.

### `ObjectAttributes` [in, optional]

Pointer to the object attributes of the key being created or opened. If *RegistryKeyType* has the value **GeneralRegistryKey**, this parameter must point to a valid, initialized system structure of type [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) with a valid *ObjectName* string for the key; otherwise, the function does not use this parameter. For more information, see the following Remarks section.

### `CreateOptions` [in, optional]

Specifies the create options. Can be zero if none are desired. If *RegistryKeyType* is not **GeneralRegistryKey**, the **PcNewRegistryKey** function ignores this parameter. For more information, see the following Remarks section.

### `Disposition` [out, optional]

Pointer to a variable that receives a value indicating whether a key was created or an existing key was opened. This parameter is optional and can be specified as **NULL**. If *RegistryKeyType* is any value other than **GeneralRegistryKey**, the **PcNewRegistryKey** function ignores this parameter. For more information, see the following Remarks section.

## Return value

**PcNewRegistryKey** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

If the *RegistryKeyType* parameter's value is **GeneralRegistryKey**, then the **PcNewRegistryKey** function either opens an existing key or creates a new key in the registry, as indicated by the value that the function outputs through the *Disposition* parameter. If the key is of any type other than **GeneralRegistryKey**, then the function opens an already existing key that was previously created during Plug and Play device enumeration.

The *DesiredAccess*, *ObjectAttributes*, *CreateOptions*, and *Disposition* parameters take on the values that are defined for the parameters with the same names in the [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) call.

The *RegistryKeyType* parameter should be set to one of the enumeration values shown in the following table.

| RegistryKeyType value | Meaning |
| --- | --- |
| **GeneralRegistryKey** | Provide generic access to any key type. Open the specified key if it already exists or create the key if it does not. |
| **DeviceRegistryKey** | Open an existing key containing device-specific information. The key is located under the key for the device instance specified by *DeviceObject*. |
| **DriverRegistryKey** | Open an existing key containing driver-specific information. |
| **HwProfileRegistryKey** | Open an existing key relative to the current hardware profile containing device or driver information. This allows the driver to access configuration information that is hardware-profile-specific. |
| **DeviceInterfaceRegistryKey** | Not used with **PcNewRegistryKey**. See [IPort::NewRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-newregistrykey) for details. |

For a *RegistryKeyType* value of **GeneralRegistryKey**, the caller must provide a valid *ObjectAttributes* parameter value, and the *CreateOptions* and *Disposition* parameters are optional. For any other *RegistryKeyType* value, the caller must provide a valid *DeviceObject* parameter value, and the *CreateOptions* and *Disposition* parameters are not used.

The *ObjectAttributes* parameter points to an opaque structure of type OBJECT_ATTRIBUTES that contains object attributes such as key name and security descriptor. Use the [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) macro to initialize the structure. In the *Attributes* parameter for this macro, set the OBJ_KERNEL_HANDLE flag unless you intend to allow non-secure, user-mode applications to have read/write access to the registry key.

The *DesiredAccess* parameter is an access-control mask. It specifies the type of access control that the caller needs to have to the new registry key when accessing it through the *OutRegistryKey* object. This mask should not be confused with the access control list (ACL) that controls access by users to the registry key. When calling **PcNewRegistryKey** to create a registry key of type **GeneralRegistryKey**, the *ObjectAttributes* parameter specifies the key's attributes, including a security descriptor that contains the ACL. However, if the new key is of type **GeneralRegistryKey** and either the security descriptor pointer in the *ObjectAttributes* structure is **NULL** or the ACL pointer in the security descriptor is **NULL**, then the new key will inherit the parent key's ACL by default.

If the key is of any type other than **GeneralRegistryKey**, then the key retains the ACL that Plug and Play assigned to the key when it was created during device enumeration.

The **PcNewRegistryKey** function is similar to the [IPort::NewRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-newregistrykey) method except that the device object and port object must be explicitly specified in a **PcNewRegistryKey** call but are simply implied in a **NewRegistryKey** call. **PcNewRegistryKey** is used primarily by adapter drivers. Miniport drivers typically call **NewRegistryKey** instead.

The *OutRegistryKey* and *OuterUnknown* parameters follow the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IPort::NewRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-newregistrykey)

[IRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iregistrykey)

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes)

[ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey)