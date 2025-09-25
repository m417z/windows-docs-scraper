# IWbemDecoupledBasicEventProvider::GetSink

## Description

The
**IWbemDecoupledBasicEventProvider::GetSink** method retrieves an
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink) object for event forwarding to WMI. This method provides for fully concurrent access.

## Parameters

### `a_Flags` [in]

Reserved for future use.

### `a_Context` [in]

Reserved for future use.

### `a_Sink` [out]

Pointer to an
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink) instance used to forward events to WMI.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.