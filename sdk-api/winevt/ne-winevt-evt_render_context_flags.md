# EVT_RENDER_CONTEXT_FLAGS enumeration

## Description

Defines the values that specify the type of information to access from the event. These flags cannot be combined.

## Constants

### `EvtRenderContextValues:0`

Render specific properties from the event.

### `EvtRenderContextSystem`

Render the system properties under the **System** element. The properties are returned in the order defined in the [EVT_SYSTEM_PROPERTY_ID enumeration](https://learn.microsoft.com/windows/win32/api/winevt/ne-winevt-evt_system_property_id).

### `EvtRenderContextUser`

Render all user-defined properties under the **UserData** or **EventData** element. If the data template associated with the event contains a **UserData** section, the **UserData** properties are rendered; otherwise, the **EventData** properties are rendered.

## Remarks

## See also

[EvtCreateRenderContext function](https://learn.microsoft.com/windows/win32/api/winevt/nf-winevt-evtcreaterendercontext)