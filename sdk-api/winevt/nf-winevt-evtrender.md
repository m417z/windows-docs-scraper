# EvtRender function

## Description

Renders an XML fragment based on the rendering context that you specify.

## Parameters

### `Context` [in]

A handle to the rendering context that the [EvtCreateRenderContext](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtcreaterendercontext) function returns. This parameter must be set to **NULL** if the *Flags* parameter is set to EvtRenderEventXml or EvtRenderBookmark.

### `Fragment` [in]

A handle to an event or to a bookmark. Set this parameter to a bookmark handle if the *Flags* parameter is set to EvtRenderBookmark; otherwise, set to an event handle.

### `Flags` [in]

A flag that identifies what to render. For example, the entire event or specific properties of the event. For possible values, see the [EVT_RENDER_FLAGS](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_render_flags) enumeration.

### `BufferSize` [in]

The size of the *Buffer* buffer, in bytes.

### `Buffer` [in]

A caller-allocated buffer that will receive the rendered output. The contents is a **null**-terminated Unicode string if the *Flags* parameter is set to EvtRenderEventXml or EvtRenderBookmark. Otherwise, if *Flags* is set to EvtRenderEventValues, the buffer contains an array of [EVT_VARIANT](https://learn.microsoft.com/windows/desktop/api/winevt/ns-winevt-evt_variant) structures; one for each property specified by the rendering context. The *PropertyCount* parameter contains the number of elements in the array.

 You can set this parameter to **NULL** to determine the required buffer size.

### `BufferUsed` [out]

The size, in bytes, of the caller-allocated buffer that the function used or the required buffer size if the function fails with ERROR_INSUFFICIENT_BUFFER.

### `PropertyCount` [out]

The number of the properties in the *Buffer* parameter if the *Flags* parameter is set to EvtRenderEventValues; otherwise, zero.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded. |
| **FALSE** | The function failed. Call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to get the error code. |

## Remarks

 There is a one-to-one relationship between the array of XPath expressions that you specified when you called the [EvtCreateRenderContext](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtcreaterendercontext) function and the array the values returned in the buffer.

When an EVT_HANDLE from this function is used in the **EvtRender** function, the list of values that is returned by that function consists of an array of [EVT_VARIANT](https://learn.microsoft.com/windows/desktop/api/winevt/ns-winevt-evt_variant) structures, each corresponding to exactly one of the XPATH expressions in the original *ValuePaths* parameter array in order of appearance. Each such **EVT_VARIANT** structure contains the value that is identified by its corresponding XPATH expression for the event that is being rendered. If no value is found, the **EVT_VARIANT** structure contains **NULL**. If multiple values are present, the **EVT_VARIANT** structure will contain the first value encountered.

Be careful when comparing floating-point numbers in XPath queries. Any string representation of a floating-point number is approximated, so the value displayed in XML might not match the number stored with the event. Floating-point numbers should be compared as being less than or greater than a constant.

#### Examples

For an example that shows how to use this function, see [Rendering Events](https://learn.microsoft.com/windows/desktop/WES/rendering-events) and [Bookmarking Events](https://learn.microsoft.com/windows/desktop/WES/bookmarking-events).

## See also

[EvtCreateRenderContext](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtcreaterendercontext)