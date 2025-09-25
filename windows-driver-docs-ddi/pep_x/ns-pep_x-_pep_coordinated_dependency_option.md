# _PEP_COORDINATED_DEPENDENCY_OPTION structure (pep_x.h)

## Description

The **PEP_COORIDNATED_DEPENDENCY_OPTION** structure describes a coordinated idle state's dependency to the OS.

## Members

### `ExpectedStateIndex`

Supplies the index of the idle state (coordinated idle state or processor idle state) that must have already been entered/be entered by this idle transition.

### `LooseDependency`

When  **FALSE**, the OS must use synchronization to guarantee that the state referred to by this dependency has already been entered.
When **TRUE**, the OS may perform best-effort coordination that the target state is entered.
The PEP must set **LooseDependency** to **TRUE** if the **ExpectedState** is a processor state and has the **WakesSpuriously** flag set.

### `InitiatingState`

Indicates if the OS may simultaneously enter the state referred to by this dependency.
If **FALSE**, this state is only valid when another processor has previously entered it.

### `DependentState`

Indicates if this state is a valid state for a dependent processor to be in.

## See also

[PEP_NOTIFY_PPM_QUERY_COORDINATED_DEPENDENCY notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[PEP_PPM_QUERY_COORDINATED_DEPENDENCY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_coordinated_dependency)