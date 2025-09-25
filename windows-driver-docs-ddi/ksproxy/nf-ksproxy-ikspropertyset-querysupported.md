## Description

The **QuerySupported** method determines whether a KS object supports a property set and the type of that support.

## Parameters

### `PropSet` [in]

GUID that identifies the property set.

### `Id` [in]

Identifier of the property within the property set.

### `TypeSupport` [out]

Pointer to a variable that receives a bitmask enumerating the flags that indicate the support that the underlying driver provides. A driver can support a bitwise OR combination of the following flags:

| Value | Description |
|---|---|
| KSPROPERTY_SUPPORT_GET | Supports retrieving a property. Use the [IKsPropertySet::Get](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-ikspropertyset-get) method to retrieve the property. |
| KSPROPERTY_SUPPORT_SET | Supports setting a property. Use the [IKsPropertySet::Set](https://learn.microsoft.com/windows-hardware/drivers/ddi/dsound/nf-dsound-ikspropertyset-set) method to set the property. |

## Return value

Returns NOERROR if successful; otherwise, returns one of the following error codes:

| Return code | Description |
|---|---|
| **E_NOTIMPL** | Property set is not supported. |
| **E_PROP_ID_UNSUPPORTED** | Property identifier (*Id*) is not supported for the specified property set. |
| **E_PROP_SET_UNSUPPORTED** | Property set is not supported. |

## Remarks

KS objects include, for example, KS filters, KS pins, and KS clocks.

> [!WARNING]
> Header files *ksproxy.h* and *dsound.h* define similar but incompatible versions of the **IKsPropertySet** interface. Applications that require the KS proxy module should use the version defined in *ksproxy.h*. If an application must include both *ksproxy.h* and *dsound.h*, whichever header file the compiler scans first is the one whose definition of **IKsPropertySet** is used by the compiler.

## See also

[IKsPropertySet::Get](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-ikspropertyset-get)

[IKsPropertySet::Set](https://learn.microsoft.com/windows-hardware/drivers/ddi/dsound/nf-dsound-ikspropertyset-set)