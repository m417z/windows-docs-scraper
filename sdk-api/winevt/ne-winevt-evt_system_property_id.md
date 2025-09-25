# EVT_SYSTEM_PROPERTY_ID enumeration

## Description

Defines the identifiers that identify the system-specific properties of an event.

## Constants

### `EvtSystemProviderName:0`

Identifies the **Name** attribute of the provider element. The variant type for this property is **EvtVarTypeString**.

### `EvtSystemProviderGuid`

Identifies the **Guid** attribute of the provider element. The variant type for this property is **EvtVarTypeGuid**.

### `EvtSystemEventID`

Identifies the **EventID** element. The variant type for this property is **EvtVarTypeUInt16**.

### `EvtSystemQualifiers`

Identifies the **Qualifiers** attribute of the EventID element. The variant type for this property is **EvtVarTypeUInt16**.

### `EvtSystemLevel`

Identifies the **Level** element. The variant type for this property is **EvtVarTypeUInt8**.

### `EvtSystemTask`

Identifies the **Task** element. The variant type for this property is **EvtVarTypeUInt16**.

### `EvtSystemOpcode`

Identifies the **Opcode** element. The variant type for this property is **EvtVarTypeUInt8**.

### `EvtSystemKeywords`

Identifies the **Keywords** element. The variant type for this property is **EvtVarTypeInt64**.

### `EvtSystemTimeCreated`

Identifies the **SystemTime** attribute of the TimeCreated element. The variant type for this property is **EvtVarTypeFileTime**.

### `EvtSystemEventRecordId`

Identifies the **EventRecordID** element. The variant type for this property is **EvtVarTypeUInt64**.

### `EvtSystemActivityID`

Identifies the **ActivityID** attribute of the Correlation element. The variant type for this property is **EvtVarTypeGuid**.

### `EvtSystemRelatedActivityID`

Identifies the **RelatedActivityID** attribute of the Correlation element. The variant type for this property is **EvtVarTypeGuid**.

### `EvtSystemProcessID`

Identifies the **ProcessID** attribute of the Execution element. The variant type for this property is **EvtVarTypeUInt32**.

### `EvtSystemThreadID`

Identifies the **ThreadID** attribute of the Execution element. The variant type for this property is **EvtVarTypeUInt32**.

### `EvtSystemChannel`

Identifies the **Channel** element. The variant type for this property is **EvtVarTypeString**.

### `EvtSystemComputer`

Identifies the **Computer** element. The variant type for this property is **EvtVarTypeString**.

### `EvtSystemUserID`

Identifies the **UserID** element. The variant type for this property is **EvtVarTypeSid**.

### `EvtSystemVersion`

Identifies the **Version** element. The variant type for this property is **EvtVarTypeUInt8**.

### `EvtSystemPropertyIdEND`

 This enumeration value marks the end of the enumeration values.

## Remarks

Before accessing these properties, check the variant type to ensure that it is not EvtVarTypeNULL; not all events will contain all system properties. For a list of system properties, see the [Event](https://learn.microsoft.com/windows/desktop/WES/eventschema-schema) schema.

## See also

[EVT_RENDER_CONTEXT_FLAGS](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_render_context_flags)

[EVT_RENDER_FLAGS](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_render_flags)

[EvtCreateRenderContext](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtcreaterendercontext)

[EvtRender](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtrender)