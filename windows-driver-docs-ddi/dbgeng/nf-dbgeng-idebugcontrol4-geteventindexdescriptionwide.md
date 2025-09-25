# IDebugControl4::GetEventIndexDescriptionWide

## Description

The **GetEventIndexDescriptionWide** method describes the specified event in a static list of events for the current target.

## Parameters

### `Index` [in]

Specifies the index of the event whose description will be returned.

### `Which` [in]

Specifies which piece of the event description to return. Currently only DEBUG_EINDEX_NAME is supported; this returns the name of the event.

### `Buffer` [in, optional]

Receives the description of the event. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size, in characters, of the *Buffer* buffer.

### `DescSize` [out, optional]

Receives the size, in characters, of the description. If *DescSize* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The amount of descriptive information available for a particular target varies depending on the type of the target.

## See also

[GetCurrentEventIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getcurrenteventindex)

[GetNumberEvents](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getnumberevents)

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)