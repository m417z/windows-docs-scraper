# MI_ProviderFT structure

## Description

A support structure used in the [MI_ClassDecl](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_classdecl) and [MI_Module](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_module) structures.

## Members

### `Load`

The server invokes this function to initialize the provider, which
performs initialization activities.

### `Unload`

The server invokes this function to release any resources held by the
provider.

### `GetInstance`

The server invokes this function to obtain a single CIM
instance from the provider.

### `EnumerateInstances`

The server calls this function to enumerate instances of a CIM class
in the target namespace.

### `CreateInstance`

The server calls this function to create a single CIM
instance in the target namespace.

### `ModifyInstance`

The server calls this function to modify an existing CIM
instance in the target namespace. The instance must already exist.

### `DeleteInstance`

The server calls this function to delete a single CIM
instance from the target namespace.

### `AssociatorInstances`

The server calls this function to find all CIM instances
associated with a particular 'source' CIM instance.

### `ReferenceInstances`

The server calls this function to enumerate association
instances that refer to a particular CIM instance.

### `EnableIndications`

The server calls this function to enable indications delivery
from the provider.

### `DisableIndications`

The server calls this function to disable indications delivery
from the provider.

### `Subscribe`

The server invokes this function to subscribe to indications.

### `Unsubscribe`

The server invokes this function to unsubscribe from indications.

### `Invoke`

The server calls this function to carry out a CIM extrinsic method
invocation on behalf of a requestor.

## See also

[MI_ProviderFT_AssociatorInstances](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn759647(v=vs.85))

[MI_ProviderFT_CreateInstance](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn759648(v=vs.85))

[MI_ProviderFT_DeleteInstance](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn759649(v=vs.85))

[MI_ProviderFT_DisableIndications](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn759650(v=vs.85))

[MI_ProviderFT_EnableIndications](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn759651(v=vs.85))

[MI_ProviderFT_EnumerateInstances](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn759652(v=vs.85))

[MI_ProviderFT_GetInstance](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn759653(v=vs.85))

[MI_ProviderFT_Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn759654(v=vs.85))

[MI_ProviderFT_Load](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn759655(v=vs.85))

[MI_ProviderFT_ModifyInstance](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn759656(v=vs.85))

[MI_ProviderFT_ReferenceInstances](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn759657(v=vs.85))

[MI_ProviderFT_Subscribe](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn759658(v=vs.85))

[MI_ProviderFT_Unload](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn759659(v=vs.85))

[MI_ProviderFT_Unsubscribe](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn759660(v=vs.85))