# _WDF_OBJECT_CONTEXT_TYPE_INFO structure

## Description

[Applies to KMDF and UMDF]

The WDF_OBJECT_CONTEXT_TYPE_INFO structure describes a framework object's driver-defined context memory.

## Members

### `Size`

The size, in bytes, of this structure.

### `ContextName`

A quoted string that represents the name of a driver-defined structure that contains an object's context information.

### `ContextSize`

The size, in bytes, of the structure that the **ContextName** member specifies. The framework allocates space for this structure when it creates an object. If the **ContextSizeOverride** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure is nonzero, its value overrides the value in the **ContextSize** member.

### `UniqueType`

For internal use.

### `EvtDriverGetUniqueContextType`

For internal use.

## Remarks

For each object instance, the framework allocates context memory with a size that is based on the value of the **ContextSize** member or the value of the **ContextSizeOverride** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure.

To create and initialize a WDF_OBJECT_CONTEXT_TYPE_INFO structure, drivers should use either the [WDF_DECLARE_CONTEXT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-declare-context-type) macro or the [WDF_DECLARE_CONTEXT_TYPE_WITH_NAME](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-declare-context-type-with-name) macro.

To insert a pointer to this structure into a WDF_OBJECT_ATTRIBUTES structure, drivers should use the [WDF_OBJECT_ATTRIBUTES_SET_CONTEXT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-object-attributes-set-context-type) macro.

For more information about using these macros, see [Framework Object Context Space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space).

## See also

[WDF_DECLARE_CONTEXT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-declare-context-type)

[WDF_DECLARE_CONTEXT_TYPE_WITH_NAME](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-declare-context-type-with-name)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_OBJECT_ATTRIBUTES_SET_CONTEXT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-object-attributes-set-context-type)