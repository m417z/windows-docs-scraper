# RestoreDC function

## Description

The **RestoreDC** function restores a device context (DC) to the specified state. The DC is restored by popping state information off a stack created by earlier calls to the [SaveDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-savedc) function.

## Parameters

### `hdc` [in]

A handle to the DC.

### `nSavedDC` [in]

The saved state to be restored. If this parameter is positive, *nSavedDC* represents a specific instance of the state to be restored. If this parameter is negative, *nSavedDC* represents an instance relative to the current state. For example, -1 restores the most recently saved state.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

 Each DC maintains a stack of saved states. The [SaveDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-savedc) function pushes the current state of the DC onto its stack of saved states. That state can be restored only to the same DC from which it was created. After a state is restored, the saved state is destroyed and cannot be reused. Furthermore, any states saved after the restored state was created are also destroyed and cannot be used. In other words, the **RestoreDC** function pops the restored state (and any subsequent states) from the state information stack.

## See also

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[SaveDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-savedc)