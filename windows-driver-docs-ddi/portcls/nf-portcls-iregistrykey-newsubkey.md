# IRegistryKey::NewSubKey

## Description

The `NewSubKey` method either creates a new registry subkey or opens an existing subkey under the key represented by the **IRegistryKey** object.

## Parameters

### `RegistrySubKey` [out]

Output pointer for the new subkey. This parameter points to a caller-allocated pointer variable into which the method writes the pointer to the new **IRegistryKey** object. This object represents the subkey being opened or created. Specify a valid, non-**NULL** pointer value for this parameter.

### `OuterUnknown` [in]

Pointer to the **IUnknown** interface of an object that needs to aggregate the registry key object. This parameter is optional. If aggregation is not required, specify this parameter as **NULL**.

### `DesiredAccess` [in]

Specifies the type of access that the caller requires to the subkey that is being opened or created. This parameter is of type [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask). For more information, see the following Remarks section.

### `SubKeyName` [in]

Pointer to the name that is to be assigned to the subkey. This parameter must be a valid, non-**NULL** pointer to an initialized structure of type [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string).

### `CreateOptions` [in]

Flags indicating the create options. Can be zero if none are desired. This parameter is required if the value of *RegistryKeyType* is **GeneralRegistryKey**; otherwise, the method does not use this parameter. For more information, see the following Remarks section.

### `Disposition` [out, optional]

Output pointer for the disposition value. This parameter points to a caller-allocated ULONG variable into which the method writes a status value indicating whether a new key was created or an existing key was opened. This parameter is optional and can be specified as **NULL** if the caller does not need it. For more information, see the following Remarks section.

## Return value

`NewSubKey` returns STATUS_SUCCESS if the call was successful in outputting a valid **IRegistryKey** pointer through the *RegistrySubKey* parameter. Otherwise, the method returns an appropriate error code.

## Remarks

The `NewSubKey` method either opens the specified registry key if it already exists, or creates a new key in the registry if it does not exist. The method outputs a pointer to the **IRegistryKey** interface of the new key through the *RegistrySubKey* parameter. The method also outputs a status value through the optional *Disposition* parameter to indicate whether the key was opened or created.

The *DesiredAccess*, *CreateOptions*, and *Disposition* parameters take on the values that are defined for the parameters with the same names in the [PcNewRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcnewregistrykey) call.

The *DesiredAccess* parameter is an access-control mask that specifies the type of access control that the caller needs to have to the subkey when accessing it through the *RegistrySubKey* object. This mask should not be confused with the ACL (access control list) that controls access by users to the registry subkey. When the **PcNewRegistryKey** function or [IPort::NewRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-newregistrykey) method creates a registry key of type **GeneralRegistryKey**, the *ObjectAttributes* parameter specifies the key's attributes, including a security descriptor that contains the ACL. When the `NewSubKey` method creates a new registry subkey, however, that subkey simply inherits the ACL from its parent key. The `NewSubKey` method provides no means to specify an ACL that differs from that of the parent key.

The *RegistrySubKey* and *OuterUnknown* parameters follow the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[IPort::NewRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-newregistrykey)

[IRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iregistrykey)

[PcNewRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcnewregistrykey)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)