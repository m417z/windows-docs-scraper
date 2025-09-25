# SafeArrayLock function

## Description

Increments the lock count of an array, and places a pointer to the array data in pvData of the array descriptor.

## Parameters

### `psa` [in]

An array descriptor created by [SafeArrayCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraycreate).

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The argument *psa* is not valid. |
| **E_UNEXPECTED** | The array could not be locked. |

## Remarks

The pointer in the array descriptor is valid until the [SafeArrayUnlock](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayunlock) function is called. Calls to **SafeArrayLock** can be nested, in which case an equal number of calls to **SafeArrayUnlock** are required.

An array cannot be deleted while it is locked.

#### Thread Safety

All public static (Shared in Visual Basic) members of the [SAFEARRAY data type](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) are thread safe. Instance members are not guaranteed to be thread safe.

For example, consider an application that uses the SafeArrayLock and [SafeArrayUnlock](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayunlock) functions. If these functions are called concurrently from different threads on the same [SAFEARRAY data type](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-safearray) instance, an inconsistent lock count may be created. This will eventually cause the **SafeArrayUnlock** function to return E_UNEXPECTED. You can prevent this by providing your own synchronization code.