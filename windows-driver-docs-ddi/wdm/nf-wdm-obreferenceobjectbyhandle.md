# ObReferenceObjectByHandle function

## Description

The **ObReferenceObjectByHandle** routine provides access validation on the object handle, and, if access can be granted, returns the corresponding pointer to the object's body.

## Parameters

### `Handle` [in]

Specifies an open handle for an object.

### `DesiredAccess` [in]

Specifies the requested types of access to the object. The interpretation of this field is dependent on the object type. Do not use any generic access rights. For more information, see [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask).

### `ObjectType` [in, optional]

Pointer to the object type. *ObjectType* can be **\*ExEventObjectType**, **\*ExSemaphoreObjectType**, **\*IoFileObjectType**, **\*PsProcessType**, **\*PsThreadType**, **\*SeTokenObjectType**, **\*TmEnlistmentObjectType**, **\*TmResourceManagerObjectType**, **\*TmTransactionManagerObjectType**, or **\*TmTransactionObjectType**.

If *ObjectType* is not **NULL**, the operating system verifies that the supplied object type matches the object type of the object that *Handle* specifies.

### `AccessMode` [in]

Specifies the access mode to use for the access check. It must be either **UserMode** or **KernelMode**. Drivers should always specify **UserMode** for handles they receive from user address space.

### `Object` [out]

Pointer to a variable that receives a pointer to the object's body. The following table contains the pointer types.

|ObjectType parameter|Object pointer type|
|----|----|
|**\*ExEventObjectType**|PKEVENT|
|**\*ExSemaphoreObjectType**|PKSEMAPHORE|
|**\*IoFileObjectType**|PFILE_OBJECT|
|**\*PsProcessType**|PEPROCESS or PKPROCESS|
|**\*PsThreadType**|PETHREAD or PKTHREAD|
|**\*SeTokenObjectType**|PACCESS_TOKEN|
|**\*TmEnlistmentObjectType**|PKENLISTMENT|
|**\*TmResourceManagerObjectType**|PKRESOURCEMANAGER|
|**\*TmTransactionManagerObjectType**|PKTM|
|**\*TmTransactionObjectType**|PKTRANSACTION|

The structures that the pointer types reference are opaque, and drivers cannot access the structure members. Because the structures are opaque, PEPROCESS is equivalent to PKPROCESS, and PETHREAD is equivalent to PKTHREAD.

### `HandleInformation` [out, optional]

Drivers set this to **NULL**.

## Return value

**ObReferenceObjectByHandle** returns STATUS_SUCCESS if the call is successful. Possible return values include the following error codes:

|Return code|Description|
|----|----|
|**STATUS_OBJECT_TYPE_MISMATCH**|The *ObjectType* parameter specifies the wrong object type for the object that is identified by the *Handle* parameter.|
|**STATUS_ACCESS_DENIED**|The caller cannot be granted the requested access rights to the object.|
|**STATUS_INVALID_HANDLE**|The *Handle* parameter is not a valid object handle.|

## Remarks

A pointer to the object body is retrieved from the object table entry and returned to the caller by means of the *Object* parameter.

If *AccessMode* is **UserMode**, the requested access is compared to the granted access for the object. If *AccessMode* is **KernelMode**, the handle should originate in the kernel address space.

Starting with Windows 7, if *AccessMode* is **KernelMode** and handle is received from user address space, [Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/driver-verifier) issues bugcheck C4, subcode F6.

If the call succeeds, a pointer to the object body is returned to the caller and the pointer reference count is incremented. Incrementing this count prevents the object from being deleted while the pointer is being referenced. The caller must decrement the reference count with [ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) as soon as it is done with the object.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)

[ObReferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obfreferenceobject)

[ObReferenceObjectByPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbypointer)