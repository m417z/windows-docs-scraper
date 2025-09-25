# TDH_CONTEXT structure

## Description

Defines the additional information required to parse an event.

## Members

### `ParameterValue`

Context value cast to a ULONGLONG. The context value is determined by the context type specified in **ParameterType**. For example, if the context type is TDH_CONTEXT_WPP_TMFFILE, the context value is a Unicode string that contains the name of the .tmf file.

### `ParameterType`

Context type. For a list of types, see the [TDH_CONTEXT_TYPE](https://learn.microsoft.com/windows/desktop/api/tdh/ne-tdh-tdh_context_type) enumeration.

### `ParameterSize`

Reserved for future use.

## See also
[TdhGetEventInformation](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgeteventinformation)