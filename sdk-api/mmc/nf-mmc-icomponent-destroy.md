# IComponent::Destroy

## Description

The IComponent::Destroy method releases all references to the console that are held by this component.

## Parameters

### `cookie`

Reserved for future use.

## Return value

This method can return one of these values.

## Remarks

The snap-in is in the process of being unloaded. It should release all references to the console contained by the component.

### Notes to Callers

Only the console calls this method.

## See also

[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent)