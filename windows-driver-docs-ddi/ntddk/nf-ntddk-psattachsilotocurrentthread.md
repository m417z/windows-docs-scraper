# PsAttachSiloToCurrentThread function

## Description

This routine places a thread temporarily into the specified *Silo*.

## Parameters

### `Silo` [in]

The silo that the thread is to impersonate. The caller must hold a reference to the silo throughout the duration of the impersonation.

## Return value

The previous silo that was attached to the current thread.

## Remarks

The specified *Silo* is attached to the current thread so that it becomes the effective silo for the thread.

The thread then operates within the namespace of the attached silo until [PsDetachSiloFromCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psdetachsilofromcurrentthread) is called.

#### Examples

```cpp
PESILO PreviousSilo = PsAttachSiloToCurrentThread(SomeSilo);

// Do work within the silo context

PsDetachSiloFromCurrentThread(PreviousSilo);</pre>
```

## See also

[PsDetachSiloFromCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psdetachsilofromcurrentthread)