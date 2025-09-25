# _REG_QUERY_KEY_SECURITY_INFORMATION structure

## Description

The **REG_QUERY_KEY_SECURITY_INFORMATION** structure receives security information for a registry key object.

## Members

### `Object`

A pointer to the registry key object for the key whose security information is being retrieved.

### `SecurityInformation`

A pointer to a [SECURITY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-information)-typed value that identifies the type of security information that is being requested.

### `SecurityDescriptor`

A pointer to a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) structure that receives security information for the key object.

### `Length`

The length, in bytes of the **SECURITY_DESCRIPTOR** structure that **SecurityDescriptor** points to.

### `CallContext`

Optional driver-defined context information that the driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine can supply. This member is defined for Windows Vista and later versions of the Windows operating system.

### `ObjectContext`

A pointer to driver-defined context information that the driver has associated with a registry object by calling [CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext). This member is defined for Windows Vista and later versions of the Windows operating system.

### `Reserved`

This member is reserved for future use. This member is defined for Windows Vista and later versions of the Windows operating system.

## Remarks

The system passes the **REG_QUERY_KEY_SECURITY_INFORMATION** structure to the [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) routine every time a thread attempts to query a key's security information—for example, when a driver calls [ZwQuerySecurityObject](https://learn.microsoft.com/previous-versions/ff567066(v=vs.85)).

For more information about registry filtering operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

## See also

[CmSetCallbackObjectContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmsetcallbackobjectcontext)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-information)

[ZwQuerySecurityObject](https://learn.microsoft.com/previous-versions/ff567066(v=vs.85))