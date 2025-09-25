## Description

The **KeRegisterNmiCallback** routine registers a routine to be called whenever a nonmaskable interrupt (NMI) occurs.

## Parameters

### `CallbackRoutine` [in]

Pointer to a function of the form:

```cpp
BOOLEAN
 XxxNmiCallback(
 IN PVOID Context,
  IN BOOLEAN Handled
 );
```

### `Context` [in, optional]

Specifies the value to be passed as the *Context* parameter of *XxxNmiCallback* when it is called.

## Return value

On success, **KeRegisterNmiCallback** returns an opaque pointer that the caller passes to [KeDeregisterNmiCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kederegisternmicallback) to deregister the callback. The routine returns **NULL** if it is unable to register the callback.

## Remarks

When a nonmaskable interrupt occurs, the system calls each registered callback in reverse order from the order in which they were registered. For the first callback, the system passes **FALSE** as the *Handled* parameter. For each subsequent callback, if any previous callback returned **TRUE**, the system passes **TRUE** as the *Handled* parameter, otherwise it passes **FALSE**. If any callback returns a value of **TRUE**, the system considers the interrupt to have been handled. Otherwise, the system calls the HAL's default handler for the interrupt, which normally causes the system to bug check.

The callback routine must be able to be run at IRQL = HIGH_LEVEL.

## See also

[KeDeregisterNmiCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kederegisternmicallback)