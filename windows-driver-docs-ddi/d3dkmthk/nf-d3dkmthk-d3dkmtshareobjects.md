# D3DKMTShareObjects function

## Description

**D3DKMTShareObjects** shares resource objects that were created with the [**D3KMTCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation), [**D3KMTCreateAllocation2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation2)[**D3DKMTCreateKeyedMutex2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatekeyedmutex2), and [**D3DKMTCreateSynchronizationObject2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatesynchronizationobject2) functions.

## Parameters

### `cObjects` [in]

The number of resource objects provided in the **hObjects** parameter. This value must be less than or equal to **D3DKMT_MAX_OBJECTS_PER_HANDLE**.

### `hObjects` [in]

A pointer to an array of local kernel-mode handles that specify the resource objects to be shared. For more information, see **Remarks**.

### `pObjectAttributes` [in]

A pointer to an [**OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that specifies attributes of the resource objects.

### `dwDesiredAccess` [in]

Specifies read and write access for the resource.

For GPU synchronization objects, **dwDesiredAccess** can be a combination of the following bit fields (defined in *d3dukmdt.h*).

| Value | Meaning |
| ----- | ------- |
| STANDARD_RIGHTS_READ | The process that opens the sync object can read the state of the sync object. This flag must be specified or the object will be inaccessible. |
| D3DDDI_SYNC_OBJECT_WAIT | The process that opens the sync object can issue wait operations for the sync object. |
| D3DDDI_SYNC_OBJECT_SIGNAL | The process that opens the sync object can issue signal operations for the sync object. |
| D3DDDI_SYNC_OBJECT_ALL_ACCESS | The process that opens the sync object can issue any operation for the sync object. |

For shared resources, the desired access can be specified as a combination of the following flags (defined in *d3dkmthk.h*):

| Value | Meaning |
| ----- | ------- |
| STANDARD_RIGHTS_READ | The process that opens the resource can have read access. This flag must be specified or the object will be inaccessible. |
| SHARED_ALLOCATION_WRITE | The process that opens the resource can have write access. If this access flag is not specified, the resource will be opened as read-only. |
| SHARED_ALLOCATION_ALL_ACCESS | The process that opens the resource can have all access to the object. |

### `phSharedNtHandle` [out]

A pointer to a shared NT handle that specifies the resource objects.

This parameter will be **NULL** if the **NtSecuritySharing** flag value is not set. For more information, see **Remarks**.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

Objects to be shared using **D3DKMTShareObjects** must first be created with the **NtSecuritySharing** flag value set. This flag value is available in the [**D3DKMT_CREATEALLOCATIONFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createallocationflags), [**D3DKMT_CREATEKEYEDMUTEX2_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createkeyedmutex2_flags), and [**D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobject_flags) structures.

This function must specify handles through the **hObjects** parameter only to the following combinations of input object array types:

- an allocation
- an allocation, a keyed mutex, and a synchronization object
- a synchronization object

The operating system will reject any other input handle combinations.

## See also

[**D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_synchronizationobject_flags)

[**D3DKMTCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation)

[**D3DKMTCreateAllocation2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation2)

[**D3DKMTCreateKeyedMutex2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatekeyedmutex2)

[**D3DKMTCreateSynchronizationObject2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatesynchronizationobject2)

[**D3DKMT_CREATEALLOCATIONFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createallocationflags)

[**D3DKMT_CREATEKEYEDMUTEX2_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createkeyedmutex2_flags)