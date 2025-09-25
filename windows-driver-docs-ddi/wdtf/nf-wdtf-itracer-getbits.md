# ITracer::GetBits

## Description

The **GetBits** method returns the set of tracing flags for a coclass as a bit mask, given a specified [TTraceLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/) value and the CLSID of the coclass.

## Parameters

### `ClassID` [in]

The CLSID of the co-class of the object that is requesting the tracing bit mask. This parameter causes the interface's [TraceLevel Path](https://learn.microsoft.com/windows-hardware/drivers/ddi/) to be defined as HKCR\CLSID\<*ClassID*>.

### `Level` [in]

The tracing level that is requested. A value of **Trace_Default** indicates that **GetBits** will search the interface's TraceLevel Path for the default level. TraceLevel Path is specified by using either *ClassID* or *pszTraceLevelPath*. .

### `pBits` [out, retval]

The returned set of flags as a bit mask.

## Return value

**GetBits** returns a standard **HRESULT** value.

## Remarks

The **GetBits** method is intended for low-level WDTF usage. If you want to change the trace level of an object at runtime, see [ITracing](https://learn.microsoft.com/windows-hardware/drivers/ddi/).

If no default trace level exists, this method fails.

If **GetBits** fails for any reason, the caller is expected to silently continue to use the tracing bit mask of its creator.

## See also

[ITracer](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[ITracing](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[TTraceLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/)