# EvtCreateRenderContext function

## Description

Creates a context that specifies the information in the event that you want to render.

## Parameters

### `ValuePathsCount` [in]

The number of XPath expressions in the *ValuePaths* parameter.

### `ValuePaths` [in]

An array of XPath expressions that uniquely identify a node or attribute in the event that you want to render.

Set to **NULL** if the **EvtRenderContextValues** context flag is not set in the *Flags* parameter.

The expressions must not contain the **OR** or **AND** operator.

Attribute names in the expressions must not be followed by a space.

### `Flags` [in]

Flag that identifies the information in the event that you want to render. For example, the system information, user information, or specific values. For possible values, see the [EVT_RENDER_CONTEXT_FLAGS](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_render_context_flags) enumeration.

## Return value

A context handle that you use when calling the [EvtRender](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtrender) function to render the contents of an event; otherwise, **NULL**. If **NULL**, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get the error code.

## Remarks

To render the specified information from the event, call the [EvtRender](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtrender) function.

You must call the [EvtClose](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtclose) function to close the handle when done.

#### Examples

For an example that shows how to use this function, see [Rendering Events](https://learn.microsoft.com/windows/desktop/WES/rendering-events).

## See also

[EvtRender](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtrender)