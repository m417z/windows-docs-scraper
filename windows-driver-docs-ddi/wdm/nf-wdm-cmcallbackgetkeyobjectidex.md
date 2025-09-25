## Description

The **CmCallbackGetKeyObjectIDEx** routine retrieves the unique identifier and object name that are associated with a specified registry key object.

This routine is available starting with Windows 8. In earlier versions of Windows, use the [CmCallbackGetKeyObjectID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmcallbackgetkeyobjectid) routine instead. For more information, see the **Remarks** section below.

## Parameters

### `Cookie` [in]

A cookie value that represents the caller's registration to receive registry filter callbacks. The driver previously obtained this cookie value from the [CmRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallback) or [CmRegisterCallbackEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallbackex) routine.

### `Object` [in]

A pointer to the registry key object. This parameter is the pointer value that the driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) callback routine received in the **Object** member of one of the **REG_*XXX*_KEY_INFORMATION** structures.

> [!WARNING]
> In certain circumstances registry callback notification structures may contain invalid non-NULL object pointers. Registry filtering drivers must not pass such pointers to this routine. For more information, see [Invalid Key Object Pointers in Registry Notifications](https://learn.microsoft.com/windows-hardware/drivers/kernel/invalid-key-object-pointers-in-registry-notifications).

### `ObjectID` [out, optional]

A pointer to a location that receives a pointer to the key identifier for the registry key that *Object* represents. This identifier is unique across all keys in the registry. This parameter is optional and can be **NULL**. For more information, see the **Remarks** section below..

### `ObjectName` [out, optional]

A pointer to a location that receives a pointer to a [**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure. This structure contains the object name of the registry key object that *Object* specifies. The object name is actually the full path name of the registry key that the object represents. The caller is responsible for freeing this structure by calling the [CmCallbackReleaseKeyObjectIDEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmcallbackreleasekeyobjectidex) routine. This parameter is optional and can be **NULL**. For more information, see Remarks.

### `Flags` [in]

Reserved. Set to zero.

## Return value

**CmCallbackGetKeyObjectIDEx** returns STATUS_SUCCESS if the operation succeeds. Possible error return values include the following status code:

| Return code | Description |
|---|---|
| **STATUS_INVALID_PARAMETER** | The *Cookie*, *Object*, or *Flags* parameter is invalid. |

## Remarks

Drivers can use **CmCallbackGetKeyObjectIDEx** to obtain the registry key identifier, the object name, or both, by supplying non-**NULL** values for the *ObjectID* or *ObjectName* parameters.

The caller can obtain the key identifier through the *ObjectID* parameter. If two registry key objects represent the same registry key, the key identifiers obtained from **CmCallbackGetKeyObjectIDEx** for the two objects are identical. If the name of the registry key changes, the key identifier obtained from **CmCallbackGetKeyObjectIDEx** does not change. The caller can use the key identifier to reliably track accesses that are made to a particular registry key through multiple key objects, and even across changes to the registry key name.

The caller can obtain the object name through the *ObjectName* parameter. The storage for the [**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the object name remains valid until the caller calls [CmCallbackReleaseKeyObjectIDEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmcallbackreleasekeyobjectidex) to free the structure.

**CmCallbackGetKeyObjectIDEx** is an improved version of the [CmCallbackGetKeyObjectID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmcallbackgetkeyobjectid) routine, which is available starting with Windows Vista. Drivers that run in versions of Windows earlier than Windows 8 should call **CmCallbackGetKeyObjectID** instead of **CmCallbackGetKeyObjectIDEx**. Drivers that run only in Windows 8 and later versions of Windows should call **CmCallbackGetKeyObjectIDEx** instead of **CmCallbackGetKeyObjectID**.

**CmCallbackGetKeyObjectIDEx** has two important features that are not available from **CmCallbackGetKeyObjectID**.

First, **CmCallbackGetKeyObjectIDEx** enables a registry filter driver to explicitly control the lifetime of the *ObjectName* structure. The driver can call **CmCallbackReleaseKeyObjectIDEx** at any time to free this structure. In contrast, the driver cannot explicitly free the *ObjectName* structure received from **CmCallbackGetKeyObjectID**. This structure is automatically released when all handles to the key are closed.

Second, if a registry filter driver calls **CmCallbackGetKeyObjectID** to get an *ObjectName* structure pointer, and, after this call, the name of the registry key changes, subsequent calls to **CmCallbackGetKeyObjectID** get a pointer to a stale copy of the *ObjectName* structure, which contains the old key name. The stale copy of this structure persists until all handles to the key are closed. In contrast, the *ObjectName* structure obtained from **CmCallbackGetKeyObjectIDEx** always contains the most up-to-date key name.

For more information about registry filter drivers, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[CmCallbackGetKeyObjectID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmcallbackgetkeyobjectid)

[CmCallbackReleaseKeyObjectIDEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmcallbackreleasekeyobjectidex)

[CmRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallback)

[CmRegisterCallbackEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallbackex)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)

[**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)