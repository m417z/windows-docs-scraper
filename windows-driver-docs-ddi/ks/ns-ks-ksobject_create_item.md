## Description

The **KSOBJECT_CREATE_ITEM** structure is used to look up the string passed to a create request.

## Members

### `Create`

Contains the create dispatch function for this particular base object class. See [**DRIVER_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) for the signature of this function type.

### `Context`

Points to a buffer that can be used to store object type-specific context information. Additional information is in the Remarks section below.

### `ObjectClass`

Points to a Unicode string that identifies the object class. This is the string that was used to register with PnP for a particular class of object supported by this device.

### `SecurityDescriptor`

Contains a pointer to a [**SECURITY_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) for this type of object, otherwise **NULL**. If security is used, this must be freed when the object type is no longer used. This must use pool memory, and cannot be shared, as it may be replaced. If this is modified, the **Flags** element is updated. Optional.

### `Flags`

Specifies the request type. Flags can have the values listed in the following table.

| Flag | Description |
|---|---|
| KSCREATE_ITEM_SECURITYCHANGED | Indicates that the security descriptor on this object type has been changed and should be persisted. |
| KSCREATE_ITEM_WILDCARD | Indicates that this create item represents a wild card that is used for any create requests that do not match any other create items. The ordering of the wild card entry in the list of create items is irrelevant. Only a single wild card entry is valid on any list of create items. |
| KSCREATE_ITEM_NOPARAMETERS | Indicates that this create item does not allow any parameters to be passed, and fails if any are found. Normally, create parameters are passed on to the create handler. This cannot be used with a wild card flag. |

## Remarks

A pointer to the KSOBJECT_CREATE_ITEM structure is placed in the **DriverContext** member of **Irp->Tail.Overlay** before the object is created. You can access this pointer by using the KSCREATE_ITEM_IRP_STORAGE macro. This macro and related macros are included in *ks.h*.

The minidriver might retrieve this pointer when creating a new object to examine the **Context** field.

## See also

[KsAllocateDeviceHeader](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocatedeviceheader)

[KsAllocateObjectHeader](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocateobjectheader)

[KsFilterFactoryAddCreateItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfilterfactoryaddcreateitem)