## Description

The KSMETHOD_ITEM structure describes a single method within a method set.

## Members

### `MethodId`

Specifies the identifier of this method within its method set.

### `MethodHandler`

Pointer to a minidriver-supplied [KStrMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkshandler) callback routine.

### `MethodSupported`

Specifies if this method is supported or not.

### `MinMethod`

Specifies the minimum size of buffer required to specify the method completely. This size is at least **sizeof**(KSMETHOD) bytes.

### `MinData`

Specifies the minimum size buffer required to specify the method data buffer. This buffer is used to read and/or write information related to the method.

### `SupportHandler`

Pointer to a minidriver-supplied [KStrSupportHandler](https://learn.microsoft.com/previous-versions/ff567206(v=vs.85)) callback routine.

### `Flags`

Specifies the request type of this method request.

| Value | Type of method request |
|---|---|
| KSMETHOD_TYPE_NONE | Indicates that the *Data* buffer of the handler is not expected to be used. For buffered methods, although space is allocated, no data is copied to or from the system buffer. When in source mode (KSMETHOD_TYPE_SOURCE), no MDL is created. |
| KSMETHOD_TYPE_READ | Indicates that parameters are expected to be read from the *Data* buffer of the handler. When buffered, data is copied to the system buffer. When in source mode, the data is probed and locked for **IoReadAccess**. |
| KSMETHOD_TYPE_WRITE | Indicates that parameters are expected to be written to the *Data* buffer of the handler. When buffered, data is copied from the system buffer. When in source mode, the data is probed and locked for **IoWriteAccess**. |
| KSMETHOD_TYPE_MODIFY | Indicates that parameters are expected to be read and written to the *Data* buffer of the handler. The data passed in is overwritten by the data returned. This might imply that a structure passed in could be merely updated. When buffered, the data is copied to the system buffer, and copied back when the IRP is completed. When in source mode, the data is probed and locked for **IoModifyAccess**. |
| KSMETHOD_TYPE_SOURCE | Indicates that the method is to be processed in source mode. An MDL is allocated and the data is probed and locked. To indicate a buffered method, OR this flag with other flags from this list. |

## Remarks

A minidriver uses the KSMETHOD_ITEM structure to define methods in a method set. The minidriver implements methods and uses the **MethodHandler** member to point to these methods. A client can then use the IOCTL_KS_METHOD request along with the KSMETHOD structure to execute methods on a kernel streaming object that the minidriver handles. For more information, see [KS Methods](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-methods).

## See also

[**KSFASTMETHOD_ITEM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksfastmethod_item)

[**KSMETHOD**](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure)

[KStrSupportHandler](https://learn.microsoft.com/previous-versions/ff567206(v=vs.85))