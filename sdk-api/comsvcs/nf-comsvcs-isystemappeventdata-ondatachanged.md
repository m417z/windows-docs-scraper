# ISystemAppEventData::OnDataChanged

## Description

Generated when the configuration of a COM+ application instance is changed.

## Parameters

### `dwPID` [in]

The process identifier of the application instance for which the configuration was changed.

### `dwMask` [in]

The event mask used to determine which tracing event fires.

### `dwNumberSinks` [in]

Always set equal to SinkType::NUMBER_SINKS.

### `bstrDwMethodMask` [in]

The event mask used to determine to which events the user has subscribed.

### `dwReason` [in]

Always set equal to INFO_MASKCHANGED.

### `u64TraceHandle` [in]

A handle to the relevant tracing session.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ISystemAppEventData](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isystemappeventdata)