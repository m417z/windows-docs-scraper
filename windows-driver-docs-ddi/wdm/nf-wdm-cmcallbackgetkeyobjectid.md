## Description

The **CmCallbackGetKeyObjectID** routine retrieves the unique identifier and object name that are associated with a specified registry key object.

Starting with Windows 8, registry filter drivers should call the [CmCallbackGetKeyObjectIDEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmcallbackgetkeyobjectidex) routine instead of **CmCallbackGetKeyObjectID**. For more information, see the **Remarks** section below.

## Parameters

### `Cookie` [in]

The cookie value that the driver previously obtained by calling the [CmRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallback) or [CmRegisterCallbackEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallbackex) routine.

### `Object` [in]

The pointer value that the driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) callback routine received in the **Object** member of one of the **REG_*XXX*_KEY_INFORMATION** structures.

> [!WARNING]
> In certain circumstances registry callback notification structures may contain invalid non-NULL object pointers. Registry filtering drivers must not pass such pointers to this routine. For more information, see [Invalid Key Object Pointers in Registry Notifications](https://learn.microsoft.com/windows-hardware/drivers/kernel/invalid-key-object-pointers-in-registry-notifications).

### `ObjectID` [out, optional]

A pointer to a location that receives a pointer to the unique identifier that represents the registry key that *Object* specifies. This parameter is optional and can be **NULL**.

### `ObjectName` [out, optional]

A pointer to a location that receives a pointer to a [**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure. This structure contains the object name of the registry key object that *Object* specifies. The object name is actually the full path name of the registry key that the object represents. The caller must not write to this **UNICODE_STRING** structure or free it. This parameter is optional and can be **NULL**.

## Return value

**CmCallbackGetKeyObjectID** returns STATUS_SUCCESS if the operation succeeds. Possible error return values include the following status code.

| Return code | Description |
|---|---|
| **STATUS_INVALID_PARAMETER** | The *Cookie* or *Object* parameter is invalid. |

## Remarks

The **CmCallbackGetKeyObjectID** routine is available starting with Windows Vista. An improved version of this routine, [CmCallbackGetKeyObjectIDEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmcallbackgetkeyobjectidex), is available starting with Windows 8. Drivers that run only in Windows 8 and later versions of Windows should call **CmCallbackGetKeyObjectIDEx** instead of **CmCallbackGetKeyObjectID**.

Drivers can use **CmCallbackGetKeyObjectID** to obtain the registry key identifier, the object name, or both, by supplying non-**NULL** values for the *ObjectID* or *ObjectName* parameters.

After the driver has obtained the identifier or name, the identifier or name is valid until the driver's *RegistryCallback* routine receives pre-notification of handle closure.

The driver must not modify the object name.

If two registry key objects represent the same registry key, the key identifiers for both objects are identical.

For more information about **CmCallbackGetKeyObjectID** and registry filtering operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[CmCallbackGetKeyObjectIDEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmcallbackgetkeyobjectidex)

[CmRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallback)

[CmRegisterCallbackEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallbackex)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)

[**UNICODE_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)