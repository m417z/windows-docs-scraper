# IWbemDecoupledBasicEventProvider::GetService

## Description

The
**IWbemDecoupledBasicEventProvider::GetService** method retrieves an **IWbemService** object to be used to call back into WMI. This method provides for fully concurrent access.

## Parameters

### `a_Flags` [in]

Reserved for future use.

### `a_Context` [in]

Reserved for future use.

### `a_Service` [out]

Pointer to an **IWbemService** object that can be used to retrieve information from WMI.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.