# EtwProviderEnabled function

## Description

The **EtwProviderEnabled** function verifies that a provider is enabled for event logging at a specified level and keyword.

## Parameters

### `RegHandle` [in]

A pointer to the event provider registration handle, which is returned by the **EtwRegister** function if the event provider registration is successful.

### `Level` [in]

The level at which the provider is enabled.

### `Keyword` [in]

The keyword that indicates whether the provider is enabled.

## Return value

The function returns **TRUE** if the provider is enabled and **FALSE** if the provider is not enabled.

## Remarks

You can use the **EtwProviderEnabled** function to verify that the registered provider is enabled for any event by passing in zeros for the *Level* and *Keyword* values when you call the function. If any event is enabled, the provider is enabled.

If an event descriptor is already available, use the [EtwEventEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etweventenabled) function.

## See also

[EtwEventEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-etweventenabled)