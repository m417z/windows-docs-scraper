# IMsmMerge::get_Errors

## Description

The
**get_Errors** method retrieves the
[Errors](https://learn.microsoft.com/windows/desktop/Msi/merge-errors) property of the
[Merge](https://learn.microsoft.com/windows/desktop/Msi/merge-object) object. This retrieves the current collection of errors.

**IMsmMerge2::get_Errors** Mergemod.dll version 2.0 or later.**IMsmMerge::get_Errors** All Mergemod.dll versions.

## Parameters

### `Errors` [out]

Pointer to a memory location containing another pointer to an **IMsmErrors** interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **E_INVALIDARG** | The *Errors* pointer is **NULL** |
| **E_OUTOFMEMORY** | The system is out of memory. |
| **S_OK** | The function succeeded. |

## Remarks

The retrieval is non-destructive, meaning that several instances of the error collection may be retrieved by repeatedly calling this method.

If there is an error, the memory location pointed to by *Errors* is set to **NULL**.

The client is responsible for releasing the interface returned by this function.

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)